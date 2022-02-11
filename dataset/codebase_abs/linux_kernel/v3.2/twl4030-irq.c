static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_2 V_5 ;
V_4 = F_2 ( V_6 , & V_5 ,
V_7 ) ;
if ( V_4 ) {
F_3 ( L_1 , V_4 ) ;
return V_8 ;
}
for ( V_3 = V_9 ;
V_5 ;
V_5 >>= 1 , V_3 ++ ) {
if ( V_5 & 0x1 )
F_4 ( V_3 ) ;
}
return V_10 ;
}
static int F_5 ( unsigned line )
{
const struct V_11 * V_11 ;
T_2 V_12 [ 4 ] ;
int V_13 ;
int V_14 ;
if ( line > 1 )
return - V_15 ;
V_16 = line ;
memset ( V_12 , 0xff , sizeof V_12 ) ;
V_11 = V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ , V_11 ++ ) {
if ( ! V_11 -> V_19 )
continue;
if ( V_11 -> V_20 <= line )
continue;
V_14 = F_6 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_23 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_7 ( L_2 ,
V_14 , V_11 -> V_24 , L_3 ) ;
if ( V_11 -> V_25 ) {
V_14 = F_8 ( V_11 -> V_21 ,
V_26 ,
V_11 -> V_27 ) ;
if ( V_14 < 0 )
F_7 ( L_2 ,
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
V_14 = F_9 ( V_11 -> V_21 , V_28 ,
V_11 -> V_22 [ line ] . V_30 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_7 ( L_2 ,
V_14 , V_11 -> V_24 , L_5 ) ;
if ( ! V_11 -> V_25 )
V_14 = F_6 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_30 ,
V_11 -> V_19 ) ;
}
}
return 0 ;
}
static inline void F_10 ( int V_1 )
{
#ifdef F_11
F_12 ( V_1 , V_31 ) ;
#else
F_13 ( V_1 ) ;
#endif
}
static void F_14 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_15 ( V_33 ) ;
V_35 -> V_36 |= F_16 ( V_33 -> V_1 - V_35 -> V_37 ) ;
V_35 -> V_38 = true ;
}
static void F_17 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_15 ( V_33 ) ;
V_35 -> V_36 &= ~ F_16 ( V_33 -> V_1 - V_35 -> V_37 ) ;
V_35 -> V_38 = true ;
}
static int F_18 ( struct V_32 * V_33 , unsigned V_39 )
{
struct V_34 * V_35 = F_15 ( V_33 ) ;
if ( V_39 & ~ ( V_40 | V_41 ) )
return - V_15 ;
if ( F_19 ( V_33 ) != V_39 )
V_35 -> V_42 |= F_16 ( V_33 -> V_1 - V_35 -> V_37 ) ;
return 0 ;
}
static void F_20 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_15 ( V_33 ) ;
F_21 ( & V_35 -> V_43 ) ;
}
static void F_22 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_15 ( V_33 ) ;
const struct V_11 * V_11 = V_35 -> V_11 ;
int V_14 ;
if ( V_35 -> V_38 ) {
union {
T_3 V_44 ;
T_2 V_45 [ 4 ] ;
} V_36 ;
V_36 . V_44 = F_23 ( V_35 -> V_36 << 8 ) ;
V_35 -> V_38 = false ;
V_14 = F_6 ( V_11 -> V_21 , V_36 . V_45 ,
V_11 -> V_22 [ V_16 ] . V_23 ,
V_11 -> V_19 ) ;
if ( V_14 )
F_7 ( L_6 , V_46 ,
L_7 , V_14 ) ;
}
if ( V_35 -> V_42 ) {
T_3 V_42 ;
T_2 V_45 [ 6 ] ;
V_42 = V_35 -> V_42 ;
V_35 -> V_42 = 0 ;
V_14 = F_9 ( V_11 -> V_21 , V_45 + 1 ,
V_11 -> V_47 , V_11 -> V_48 ) ;
if ( V_14 ) {
F_7 ( L_6 , V_46 ,
L_8 , V_14 ) ;
return;
}
while ( V_42 ) {
int V_13 = F_24 ( V_42 ) - 1 ;
struct V_32 * V_49 ;
int V_50 = 1 + ( V_13 >> 2 ) ;
int V_51 = ( V_13 & 0x3 ) * 2 ;
unsigned int type ;
V_49 = F_25 ( V_13 + V_35 -> V_37 ) ;
V_45 [ V_50 ] &= ~ ( 0x03 << V_51 ) ;
type = F_19 ( V_49 ) ;
if ( type & V_41 )
V_45 [ V_50 ] |= F_16 ( V_51 + 1 ) ;
if ( type & V_40 )
V_45 [ V_50 ] |= F_16 ( V_51 + 0 ) ;
V_42 &= ~ F_16 ( V_13 ) ;
}
V_14 = F_6 ( V_11 -> V_21 , V_45 ,
V_11 -> V_47 , V_11 -> V_48 ) ;
if ( V_14 )
F_7 ( L_6 , V_46 ,
L_7 , V_14 ) ;
}
F_26 ( & V_35 -> V_43 ) ;
}
static inline int F_27 ( const struct V_11 * V_11 )
{
int V_14 ;
union {
T_2 V_45 [ 4 ] ;
T_3 V_44 ;
} V_52 ;
V_52 . V_44 = 0 ;
V_14 = F_9 ( V_11 -> V_21 , V_52 . V_45 ,
V_11 -> V_22 [ V_16 ] . V_30 , V_11 -> V_19 ) ;
return ( V_14 < 0 ) ? V_14 : F_28 ( V_52 . V_44 ) ;
}
static T_1 F_29 ( int V_1 , void * V_33 )
{
struct V_34 * V_35 = F_30 ( V_1 ) ;
const struct V_11 * V_11 = V_35 -> V_11 ;
int V_52 ;
V_52 = F_27 ( V_11 ) ;
if ( V_52 < 0 ) {
F_7 ( L_9 ,
V_11 -> V_24 , V_52 ) ;
return V_10 ;
}
while ( V_52 ) {
V_1 = F_24 ( V_52 ) ;
V_1 -- ;
V_52 &= ~ F_16 ( V_1 ) ;
if ( V_1 < V_11 -> V_53 )
F_4 ( V_35 -> V_37 + V_1 ) ;
else
F_7 ( L_10 ,
V_11 -> V_24 , V_1 ) ;
}
return V_10 ;
}
int F_31 ( int V_21 )
{
int V_54 ;
const struct V_11 * V_11 = NULL ;
struct V_34 * V_35 ;
int V_13 , V_1 ;
int V_14 = - V_15 ;
unsigned V_37 = V_55 ;
for ( V_54 = 0 , V_11 = V_17 ;
V_54 < V_18 ;
V_54 ++ , V_11 ++ ) {
if ( V_11 -> V_21 == V_21 && V_11 -> V_25 ) {
if ( ! F_32 ( ( V_37 + V_11 -> V_53 ) > V_56 ,
L_11 ,
V_37 + V_11 -> V_53 ,
V_11 -> V_24 ) )
V_14 = 0 ;
break;
}
}
if ( V_14 < 0 )
return V_14 ;
V_35 = F_33 ( sizeof *V_35 , V_57 ) ;
if ( ! V_35 )
return - V_58 ;
V_14 = 0 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_11 = V_11 ;
V_35 -> V_36 = ~ 0 ;
F_34 ( & V_35 -> V_43 ) ;
for ( V_13 = 0 ; V_13 < V_11 -> V_53 ; V_13 ++ ) {
V_1 = V_37 + V_13 ;
F_35 ( V_1 , V_35 ) ;
F_36 ( V_1 , & V_59 ,
V_60 ) ;
F_10 ( V_1 ) ;
}
V_55 += V_13 ;
V_1 = V_54 + V_9 ;
F_37 ( V_1 , V_35 ) ;
V_35 -> V_61 = F_38 ( V_57 , L_12 , V_11 -> V_24 ) ;
V_14 = F_39 ( V_1 , NULL , F_29 , 0 ,
V_35 -> V_61 ? : V_11 -> V_24 , NULL ) ;
F_40 ( L_13 , V_11 -> V_24 ,
V_1 , V_37 , V_55 - 1 ) ;
return V_14 < 0 ? V_14 : V_37 ;
}
int F_41 ( int V_62 , unsigned V_37 , unsigned V_63 )
{
static struct V_64 V_65 ;
int V_14 ;
int V_13 ;
V_14 = F_5 ( V_66 ) ;
if ( V_14 < 0 )
return V_14 ;
V_9 = V_37 ;
V_65 = V_67 ;
V_65 . V_24 = L_14 ;
V_59 . V_68 = V_67 . V_68 ;
for ( V_13 = V_37 ; V_13 < V_63 ; V_13 ++ ) {
F_36 ( V_13 , & V_65 ,
V_69 ) ;
F_42 ( V_13 , 1 ) ;
F_10 ( V_13 ) ;
}
V_55 = V_13 ;
F_40 ( L_13 , L_15 ,
V_62 , V_37 , V_55 - 1 ) ;
V_14 = F_31 ( V_70 ) ;
if ( V_14 < 0 ) {
F_7 ( L_16 , V_14 ) ;
goto V_71;
}
V_14 = F_39 ( V_62 , NULL , F_1 ,
V_72 ,
L_17 , NULL ) ;
if ( V_14 < 0 ) {
F_7 ( L_18 , V_62 , V_14 ) ;
goto V_73;
}
return V_14 ;
V_73:
V_71:
for ( V_13 = V_37 ; V_13 < V_63 ; V_13 ++ ) {
F_42 ( V_13 , 0 ) ;
F_36 ( V_13 , NULL , NULL ) ;
}
return V_14 ;
}
int F_43 ( void )
{
if ( V_9 ) {
F_7 ( L_19 ) ;
return - V_74 ;
}
return 0 ;
}
int F_44 ( const char * V_75 )
{
if ( ! strcmp ( V_75 , L_20 ) ) {
V_17 = V_76 ;
V_18 = F_45 ( V_76 ) ;
} else {
V_17 = V_77 ;
V_18 = F_45 ( V_77 ) ;
}
return 0 ;
}
