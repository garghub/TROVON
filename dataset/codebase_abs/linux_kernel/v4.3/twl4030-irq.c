static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_5 , & V_4 ,
V_6 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
return V_7 ;
}
while ( V_4 ) {
unsigned long V_8 = F_4 ( V_4 ) ;
unsigned int V_1 ;
V_4 &= ~ F_5 ( V_8 ) ;
V_1 = V_8 + V_9 ;
F_6 ( V_1 ) ;
}
return V_10 ;
}
static int F_7 ( unsigned line )
{
const struct V_11 * V_11 ;
T_2 V_12 [ 4 ] ;
int V_13 ;
int V_14 ;
if ( line > 1 )
return - V_15 ;
V_16 = line ;
memset ( V_12 , 0xff , sizeof( V_12 ) ) ;
V_11 = V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ , V_11 ++ ) {
if ( ! V_11 -> V_19 )
continue;
if ( V_11 -> V_20 <= line )
continue;
V_14 = F_8 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_23 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_9 ( L_2 ,
V_14 , V_11 -> V_24 , L_3 ) ;
if ( V_11 -> V_25 ) {
V_14 = F_10 ( V_11 -> V_21 ,
V_26 ,
V_11 -> V_27 ) ;
if ( V_14 < 0 )
F_9 ( L_2 ,
V_14 , V_11 -> V_24 , L_4 ) ;
}
}
V_11 = V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ , V_11 ++ ) {
T_2 V_28 [ 4 ] ;
int V_29 ;
if ( ! V_11 -> V_19 )
continue;
if ( V_11 -> V_20 <= line )
continue;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_14 = F_11 ( V_11 -> V_21 , V_28 ,
V_11 -> V_22 [ line ] . V_30 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_3 ( L_2 ,
V_14 , V_11 -> V_24 , L_5 ) ;
if ( ! V_11 -> V_25 ) {
V_14 = F_8 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_30 ,
V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_3 ( L_6 ,
V_14 ) ;
}
}
}
return 0 ;
}
static inline void F_12 ( int V_1 )
{
F_13 ( V_1 , V_31 | V_32 ) ;
}
static void F_14 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_15 ( V_34 ) ;
V_36 -> V_37 |= F_5 ( V_34 -> V_1 - V_36 -> V_38 ) ;
V_36 -> V_39 = true ;
}
static void F_16 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_15 ( V_34 ) ;
V_36 -> V_37 &= ~ F_5 ( V_34 -> V_1 - V_36 -> V_38 ) ;
V_36 -> V_39 = true ;
}
static int F_17 ( struct V_33 * V_34 , unsigned V_40 )
{
struct V_35 * V_36 = F_15 ( V_34 ) ;
if ( V_40 & ~ ( V_41 | V_42 ) )
return - V_15 ;
if ( F_18 ( V_34 ) != V_40 )
V_36 -> V_43 |= F_5 ( V_34 -> V_1 - V_36 -> V_38 ) ;
return 0 ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_15 ( V_34 ) ;
F_20 ( & V_36 -> V_44 ) ;
}
static void F_21 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_15 ( V_34 ) ;
const struct V_11 * V_11 = V_36 -> V_11 ;
int V_14 ;
if ( V_36 -> V_39 ) {
union {
T_3 V_45 ;
T_2 V_46 [ 4 ] ;
} V_37 ;
V_37 . V_45 = F_22 ( V_36 -> V_37 ) ;
V_36 -> V_39 = false ;
V_14 = F_8 ( V_11 -> V_21 , V_37 . V_46 ,
V_11 -> V_22 [ V_16 ] . V_23 ,
V_11 -> V_19 ) ;
if ( V_14 )
F_9 ( L_7 , V_47 ,
L_8 , V_14 ) ;
}
if ( V_36 -> V_43 ) {
T_3 V_43 ;
T_2 V_46 [ 6 ] ;
V_43 = V_36 -> V_43 ;
V_36 -> V_43 = 0 ;
V_14 = F_11 ( V_11 -> V_21 , V_46 ,
V_11 -> V_48 , V_11 -> V_49 ) ;
if ( V_14 ) {
F_9 ( L_7 , V_47 ,
L_9 , V_14 ) ;
return;
}
while ( V_43 ) {
int V_13 = F_23 ( V_43 ) - 1 ;
int V_50 = V_13 >> 2 ;
int V_51 = ( V_13 & 0x3 ) * 2 ;
unsigned int type ;
V_46 [ V_50 ] &= ~ ( 0x03 << V_51 ) ;
type = F_24 ( V_13 + V_36 -> V_38 ) ;
if ( type & V_42 )
V_46 [ V_50 ] |= F_5 ( V_51 + 1 ) ;
if ( type & V_41 )
V_46 [ V_50 ] |= F_5 ( V_51 + 0 ) ;
V_43 &= ~ F_5 ( V_13 ) ;
}
V_14 = F_8 ( V_11 -> V_21 , V_46 ,
V_11 -> V_48 , V_11 -> V_49 ) ;
if ( V_14 )
F_9 ( L_7 , V_47 ,
L_8 , V_14 ) ;
}
F_25 ( & V_36 -> V_44 ) ;
}
static inline int F_26 ( const struct V_11 * V_11 )
{
int V_14 ;
union {
T_2 V_46 [ 4 ] ;
T_3 V_45 ;
} V_52 ;
V_52 . V_45 = 0 ;
V_14 = F_11 ( V_11 -> V_21 , V_52 . V_46 ,
V_11 -> V_22 [ V_16 ] . V_30 , V_11 -> V_19 ) ;
return ( V_14 < 0 ) ? V_14 : F_27 ( V_52 . V_45 ) ;
}
static T_1 F_28 ( int V_1 , void * V_34 )
{
struct V_35 * V_36 = F_29 ( V_1 ) ;
const struct V_11 * V_11 = V_36 -> V_11 ;
int V_52 ;
V_52 = F_26 ( V_11 ) ;
if ( V_52 < 0 ) {
F_9 ( L_10 ,
V_11 -> V_24 , V_52 ) ;
return V_10 ;
}
while ( V_52 ) {
V_1 = F_23 ( V_52 ) ;
V_1 -- ;
V_52 &= ~ F_5 ( V_1 ) ;
if ( V_1 < V_11 -> V_53 )
F_6 ( V_36 -> V_38 + V_1 ) ;
else
F_9 ( L_11 ,
V_11 -> V_24 , V_1 ) ;
}
return V_10 ;
}
int F_30 ( struct V_54 * V_55 , int V_21 , int V_38 )
{
int V_56 ;
const struct V_11 * V_11 = NULL ;
struct V_35 * V_36 ;
int V_13 , V_1 ;
int V_14 = - V_15 ;
for ( V_56 = 0 , V_11 = V_17 ; V_56 < V_18 ;
V_56 ++ , V_11 ++ ) {
if ( V_11 -> V_21 == V_21 && V_11 -> V_25 ) {
V_14 = 0 ;
break;
}
}
if ( V_14 < 0 )
return V_14 ;
V_36 = F_31 ( sizeof( * V_36 ) , V_57 ) ;
if ( ! V_36 )
return - V_58 ;
V_36 -> V_38 = V_38 ;
V_36 -> V_11 = V_11 ;
V_36 -> V_37 = ~ 0 ;
F_32 ( & V_36 -> V_44 ) ;
for ( V_13 = 0 ; V_13 < V_11 -> V_53 ; V_13 ++ ) {
V_1 = V_38 + V_13 ;
F_33 ( V_1 , V_36 ) ;
F_34 ( V_1 , & V_59 ,
V_60 ) ;
F_35 ( V_1 , 1 ) ;
F_12 ( V_1 ) ;
}
V_1 = V_56 + V_9 ;
F_36 ( V_1 , V_36 ) ;
V_36 -> V_61 = F_37 ( V_57 , L_12 , V_11 -> V_24 ) ;
V_14 = F_38 ( V_1 , NULL , F_28 ,
V_62 | V_63 ,
V_36 -> V_61 ? : V_11 -> V_24 , NULL ) ;
F_39 ( V_55 , L_13 , V_11 -> V_24 ,
V_1 , V_38 , V_38 + V_13 - 1 ) ;
return V_14 < 0 ? V_14 : V_38 ;
}
int F_40 ( struct V_54 * V_55 , int V_64 )
{
static struct V_65 V_66 ;
int V_14 , V_13 ;
int V_38 , V_67 , V_68 ;
struct V_69 * V_70 = V_55 -> V_71 ;
V_68 = V_72 + V_73 ;
V_38 = F_41 ( - 1 , 0 , V_68 , 0 ) ;
if ( F_42 ( V_38 ) ) {
F_43 ( V_55 , L_14 ) ;
return V_38 ;
}
F_44 ( V_70 , V_68 , V_38 , 0 ,
& V_74 , NULL ) ;
V_67 = V_38 + V_73 ;
V_14 = F_7 ( V_75 ) ;
if ( V_14 < 0 )
return V_14 ;
V_9 = V_38 ;
V_66 = V_76 ;
V_66 . V_24 = L_15 ;
V_59 . V_77 = V_76 . V_77 ;
for ( V_13 = V_38 ; V_13 < V_67 ; V_13 ++ ) {
F_34 ( V_13 , & V_66 ,
V_78 ) ;
F_35 ( V_13 , 1 ) ;
F_12 ( V_13 ) ;
}
F_39 ( V_55 , L_13 , L_16 ,
V_64 , V_38 , V_67 ) ;
V_14 = F_30 ( V_55 , V_79 , V_67 ) ;
if ( V_14 < 0 ) {
F_43 ( V_55 , L_17 , V_14 ) ;
goto V_80;
}
V_14 = F_38 ( V_64 , NULL , F_1 ,
V_63 ,
L_18 , NULL ) ;
if ( V_14 < 0 ) {
F_43 ( V_55 , L_19 , V_64 , V_14 ) ;
goto V_81;
}
F_45 ( V_64 ) ;
return V_38 ;
V_81:
V_80:
for ( V_13 = V_38 ; V_13 < V_67 ; V_13 ++ ) {
F_35 ( V_13 , 0 ) ;
F_34 ( V_13 , NULL , NULL ) ;
}
return V_14 ;
}
int F_46 ( void )
{
if ( V_9 ) {
F_9 ( L_20 ) ;
return - V_82 ;
}
return 0 ;
}
int F_47 ( const char * V_83 )
{
if ( ! strcmp ( V_83 , L_21 ) ) {
V_17 = V_84 ;
V_18 = F_48 ( V_84 ) ;
} else {
V_17 = V_85 ;
V_18 = F_48 ( V_85 ) ;
}
return 0 ;
}
