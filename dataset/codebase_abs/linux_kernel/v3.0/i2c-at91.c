static void T_1 F_1 ( void )
{
unsigned long V_1 , V_2 ;
F_2 ( V_3 , 0xffffffff ) ;
F_2 ( V_4 , V_5 ) ;
F_2 ( V_4 , V_6 ) ;
V_1 = ( F_3 ( V_7 ) / ( 2 * V_8 ) ) - 3 ;
V_1 = V_1 + 1 ;
V_2 = 0 ;
while ( V_1 > 255 ) {
V_2 ++ ;
V_1 = V_1 >> 1 ;
}
if ( F_4 () ) {
if ( V_2 > 5 ) {
F_5 ( V_9 L_1 ) ;
V_2 = 5 ;
}
}
F_2 ( V_10 , ( V_2 << 16 ) | ( V_1 << 8 ) | V_1 ) ;
}
static short F_6 ( unsigned long V_11 )
{
int V_12 = 10000 ;
do {
F_7 ( 10 ) ;
} while ( ! ( F_8 ( V_13 ) & V_11 ) && ( -- V_12 > 0 ) );
return ( V_12 > 0 ) ;
}
static int F_9 ( struct V_14 * V_15 , unsigned char * V_16 , int V_17 )
{
F_2 ( V_4 , V_18 ) ;
while ( V_17 -- ) {
if ( ! V_17 )
F_2 ( V_4 , V_19 ) ;
if ( ! F_6 ( V_20 ) ) {
F_10 ( & V_15 -> V_21 , L_2 ) ;
return - V_22 ;
}
* V_16 ++ = ( F_8 ( V_23 ) & 0xff ) ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , unsigned char * V_16 , int V_17 )
{
F_2 ( V_24 , * V_16 ++ ) ;
F_2 ( V_4 , V_18 ) ;
do {
if ( ! F_6 ( V_25 ) ) {
F_10 ( & V_15 -> V_21 , L_3 ) ;
return - V_22 ;
}
V_17 -- ;
if ( V_17 > 0 )
F_2 ( V_24 , * V_16 ++ ) ;
} while ( V_17 );
F_2 ( V_4 , V_19 ) ;
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , struct V_26 * V_27 , int V_28 )
{
int V_29 , V_30 ;
F_10 ( & V_15 -> V_21 , L_4 , V_28 ) ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ ) {
F_10 ( & V_15 -> V_21 , L_5 , V_29 ,
V_27 -> V_31 & V_32 ? L_6 : L_7 ,
V_27 -> V_33 , V_27 -> V_33 > 1 ? L_8 : L_9 ,
V_27 -> V_31 & V_32 ? L_10 : L_11 , V_27 -> V_34 ) ;
F_2 ( V_35 , ( V_27 -> V_34 << 16 )
| ( ( V_27 -> V_31 & V_32 ) ? V_36 : 0 ) ) ;
if ( V_27 -> V_33 && V_27 -> V_16 ) {
if ( V_27 -> V_31 & V_32 )
V_30 = F_9 ( V_15 , V_27 -> V_16 , V_27 -> V_33 ) ;
else
V_30 = F_11 ( V_15 , V_27 -> V_16 , V_27 -> V_33 ) ;
if ( V_30 )
return V_30 ;
if ( ! F_6 ( V_37 ) ) {
F_10 ( & V_15 -> V_21 , L_12 ) ;
return - V_22 ;
}
}
F_10 ( & V_15 -> V_21 , L_13 ) ;
V_27 ++ ;
}
return V_29 ;
}
static T_2 F_13 ( struct V_14 * V_38 )
{
return V_39 | V_40 ;
}
static int T_1 F_14 ( struct V_41 * V_42 )
{
struct V_14 * V_38 ;
struct V_43 * V_44 ;
int V_45 ;
V_44 = F_15 ( V_42 , V_46 , 0 ) ;
if ( ! V_44 )
return - V_47 ;
if ( ! F_16 ( V_44 -> V_48 , F_17 ( V_44 ) , L_14 ) )
return - V_49 ;
V_50 = F_18 ( V_44 -> V_48 , F_17 ( V_44 ) ) ;
if ( ! V_50 ) {
V_45 = - V_51 ;
goto V_52;
}
V_7 = F_19 ( NULL , L_15 ) ;
if ( F_20 ( V_7 ) ) {
F_21 ( & V_42 -> V_21 , L_16 ) ;
V_45 = - V_53 ;
goto V_54;
}
V_38 = F_22 ( sizeof( struct V_14 ) , V_55 ) ;
if ( V_38 == NULL ) {
F_21 ( & V_42 -> V_21 , L_17 ) ;
V_45 = - V_51 ;
goto V_56;
}
snprintf ( V_38 -> V_57 , sizeof( V_38 -> V_57 ) , L_18 ) ;
V_38 -> V_58 = & V_59 ;
V_38 -> V_60 = V_61 ;
V_38 -> V_21 . V_62 = & V_42 -> V_21 ;
F_23 ( V_42 , V_38 ) ;
F_24 ( V_7 ) ;
F_1 () ;
V_45 = F_25 ( V_38 ) ;
if ( V_45 ) {
F_21 ( & V_42 -> V_21 , L_19 ,
V_38 -> V_57 ) ;
goto V_63;
}
F_26 ( & V_42 -> V_21 , L_20 ) ;
return 0 ;
V_63:
F_23 ( V_42 , NULL ) ;
F_27 ( V_38 ) ;
F_28 ( V_7 ) ;
V_56:
F_29 ( V_7 ) ;
V_54:
F_30 ( V_50 ) ;
V_52:
F_31 ( V_44 -> V_48 , F_17 ( V_44 ) ) ;
return V_45 ;
}
static int T_3 F_32 ( struct V_41 * V_42 )
{
struct V_14 * V_38 = F_33 ( V_42 ) ;
struct V_43 * V_44 ;
int V_45 ;
V_45 = F_34 ( V_38 ) ;
F_23 ( V_42 , NULL ) ;
V_44 = F_15 ( V_42 , V_46 , 0 ) ;
F_30 ( V_50 ) ;
F_31 ( V_44 -> V_48 , F_17 ( V_44 ) ) ;
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
return V_45 ;
}
static int F_35 ( struct V_41 * V_42 , T_4 V_64 )
{
F_28 ( V_7 ) ;
return 0 ;
}
static int F_36 ( struct V_41 * V_42 )
{
return F_24 ( V_7 ) ;
}
static int T_5 F_37 ( void )
{
return F_38 ( & V_65 ) ;
}
static void T_6 F_39 ( void )
{
F_40 ( & V_65 ) ;
}
