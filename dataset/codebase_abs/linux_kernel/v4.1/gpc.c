void F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_6 ) ;
}
void F_3 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( ( V_1 << V_3 ) |
( V_2 << V_4 ) , V_5 + V_7 ) ;
}
void F_4 ( bool V_8 )
{
F_2 ( V_8 , V_5 + V_9 ) ;
}
void F_5 ( bool V_10 )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
if ( V_10 )
F_4 ( V_10 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ V_16 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
}
void F_7 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
F_4 ( false ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
static int F_8 ( struct V_17 * V_18 , unsigned int V_19 )
{
unsigned int V_20 = V_18 -> V_21 / 32 ;
T_1 V_22 ;
V_22 = 1 << V_18 -> V_21 % 32 ;
V_16 [ V_20 ] = V_19 ? V_16 [ V_20 ] | V_22 :
V_16 [ V_20 ] & ~ V_22 ;
return 0 ;
}
void F_9 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_15 [ V_13 ] = F_6 ( V_11 + V_13 * 4 ) ;
F_2 ( ~ 0 , V_11 + V_13 * 4 ) ;
}
}
void F_10 ( void )
{
void T_2 * V_11 = V_5 + V_12 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( V_15 [ V_13 ] , V_11 + V_13 * 4 ) ;
}
void F_11 ( unsigned int V_21 )
{
void T_2 * V_23 ;
T_1 V_24 ;
V_23 = V_5 + V_12 + V_21 / 32 * 4 ;
V_24 = F_6 ( V_23 ) ;
V_24 &= ~ ( 1 << V_21 % 32 ) ;
F_2 ( V_24 , V_23 ) ;
}
void F_12 ( unsigned int V_21 )
{
void T_2 * V_23 ;
T_1 V_24 ;
V_23 = V_5 + V_12 + V_21 / 32 * 4 ;
V_24 = F_6 ( V_23 ) ;
V_24 |= 1 << ( V_21 % 32 ) ;
F_2 ( V_24 , V_23 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
F_11 ( V_18 -> V_21 ) ;
F_14 ( V_18 ) ;
}
static void F_15 ( struct V_17 * V_18 )
{
F_12 ( V_18 -> V_21 ) ;
F_16 ( V_18 ) ;
}
static int F_17 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const T_1 * V_29 ,
unsigned int V_30 ,
unsigned long * V_31 ,
unsigned int * V_32 )
{
if ( V_26 -> V_33 != V_28 )
return - V_34 ;
if ( V_30 != 3 )
return - V_34 ;
if ( V_29 [ 0 ] != 0 )
return - V_34 ;
* V_31 = V_29 [ 1 ] ;
* V_32 = V_29 [ 2 ] ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 ,
unsigned int V_35 ,
unsigned int V_36 , void * V_37 )
{
struct V_38 * args = V_37 ;
struct V_38 V_39 ;
T_3 V_21 ;
int V_13 ;
if ( args -> V_40 != 3 )
return - V_34 ;
if ( args -> args [ 0 ] != 0 )
return - V_34 ;
V_21 = args -> args [ 1 ] ;
if ( V_21 >= V_41 )
return - V_34 ;
for ( V_13 = 0 ; V_13 < V_36 ; V_13 ++ )
F_19 ( V_26 , V_35 + V_13 , V_21 + V_13 ,
& V_42 , NULL ) ;
V_39 = * args ;
V_39 . V_43 = V_26 -> V_44 -> V_33 ;
return F_20 ( V_26 , V_35 , V_36 , & V_39 ) ;
}
static int T_4 F_21 ( struct V_27 * V_45 ,
struct V_27 * V_44 )
{
struct V_25 * V_46 , * V_26 ;
int V_13 ;
if ( ! V_44 ) {
F_22 ( L_1 , V_45 -> V_47 ) ;
return - V_48 ;
}
V_46 = F_23 ( V_44 ) ;
if ( ! V_46 ) {
F_22 ( L_2 , V_45 -> V_47 ) ;
return - V_49 ;
}
V_5 = F_24 ( V_45 , 0 ) ;
if ( F_25 ( ! V_5 ) )
return - V_50 ;
V_26 = F_26 ( V_46 , 0 , V_41 ,
V_45 , & V_51 ,
NULL ) ;
if ( ! V_26 ) {
F_27 ( V_5 ) ;
return - V_50 ;
}
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_2 ( ~ 0 , V_5 + V_12 + V_13 * 4 ) ;
return 0 ;
}
void T_4 F_28 ( void )
{
struct V_27 * V_43 ;
V_43 = F_29 ( NULL , NULL , L_3 ) ;
if ( F_25 ( ! V_43 ) )
return;
if ( F_25 ( ! F_30 ( V_43 , L_4 , NULL ) ) ) {
F_31 ( L_5 ) ;
V_5 = F_24 ( V_43 , 0 ) ;
}
}
static void F_32 ( struct V_52 * V_53 )
{
int V_54 , V_55 ;
T_1 V_24 ;
V_24 = F_6 ( V_5 + V_56 ) ;
V_54 = V_24 & 0x3f ;
V_55 = ( V_24 >> 8 ) & 0x3f ;
F_2 ( 0x1 , V_5 + V_57 ) ;
V_24 = F_6 ( V_5 + V_58 ) ;
V_24 |= V_59 ;
F_2 ( V_24 , V_5 + V_58 ) ;
F_33 ( ( V_54 + V_55 ) * 1000 / 66 ) ;
}
static int F_34 ( struct V_52 * V_53 )
{
struct V_60 * V_61 = F_35 ( V_53 , struct V_60 , V_62 ) ;
F_32 ( V_53 ) ;
if ( V_61 -> V_23 )
F_36 ( V_61 -> V_23 ) ;
return 0 ;
}
static int F_37 ( struct V_52 * V_53 )
{
struct V_60 * V_61 = F_35 ( V_53 , struct V_60 , V_62 ) ;
int V_13 , V_63 , V_2 , V_1 ;
T_1 V_24 ;
if ( V_61 -> V_23 )
V_63 = F_38 ( V_61 -> V_23 ) ;
if ( V_61 -> V_23 && V_63 ) {
F_22 ( L_6 , V_64 , V_63 ) ;
return V_63 ;
}
for ( V_13 = 0 ; V_13 < V_61 -> V_65 ; V_13 ++ )
F_39 ( V_61 -> V_66 [ V_13 ] ) ;
F_2 ( 0x1 , V_5 + V_57 ) ;
V_24 = F_6 ( V_5 + V_67 ) ;
V_2 = V_24 & 0x3f ;
V_1 = ( V_24 >> 8 ) & 0x3f ;
V_24 = F_6 ( V_5 + V_58 ) ;
V_24 |= V_68 ;
F_2 ( V_24 , V_5 + V_58 ) ;
F_33 ( ( V_2 + V_1 ) * 1000 / 66 ) ;
for ( V_13 = 0 ; V_13 < V_61 -> V_65 ; V_13 ++ )
F_40 ( V_61 -> V_66 [ V_13 ] ) ;
return 0 ;
}
static int F_41 ( struct V_69 * V_70 , struct V_71 * V_72 )
{
struct V_66 * V_66 ;
bool V_73 ;
int V_13 ;
V_74 . V_23 = V_72 ;
for ( V_13 = 0 ; ; V_13 ++ ) {
V_66 = F_42 ( V_70 -> V_33 , V_13 ) ;
if ( F_43 ( V_66 ) )
break;
if ( V_13 >= V_75 ) {
F_44 ( V_70 , L_7 , V_75 ) ;
goto V_76;
}
V_74 . V_66 [ V_13 ] = V_66 ;
}
V_74 . V_65 = V_13 ;
V_73 = F_45 ( V_77 ) ;
if ( V_73 ) {
F_32 ( & V_74 . V_62 ) ;
} else {
F_37 ( & V_74 . V_62 ) ;
}
F_46 ( & V_74 . V_62 , NULL , V_73 ) ;
return F_47 ( V_70 -> V_33 ,
& V_78 ) ;
V_76:
while ( V_13 -- )
F_48 ( V_74 . V_66 [ V_13 ] ) ;
return - V_34 ;
}
static inline int F_41 ( struct V_69 * V_70 , struct V_71 * V_23 )
{
return 0 ;
}
static int F_49 ( struct V_79 * V_80 )
{
struct V_71 * V_72 ;
int V_63 ;
if ( ! F_50 ( V_80 -> V_70 . V_33 , L_8 ) )
return 0 ;
V_72 = F_51 ( & V_80 -> V_70 , L_9 ) ;
if ( F_52 ( V_72 ) == - V_48 )
V_72 = NULL ;
if ( F_43 ( V_72 ) ) {
V_63 = F_52 ( V_72 ) ;
F_44 ( & V_80 -> V_70 , L_10 , V_63 ) ;
return V_63 ;
}
return F_41 ( & V_80 -> V_70 , V_72 ) ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_81 ) ;
}
