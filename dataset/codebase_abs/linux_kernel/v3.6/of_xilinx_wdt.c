static void F_1 ( void )
{
F_2 ( & V_1 ) ;
V_2 = F_3 ( V_3 . V_4 + V_5 ) ;
V_2 |= ( V_6 | V_7 ) ;
F_4 ( ( V_2 | V_8 ) ,
V_3 . V_4 + V_5 ) ;
F_4 ( V_9 , V_3 . V_4 + V_10 ) ;
F_5 ( & V_1 ) ;
}
static void F_6 ( void )
{
F_2 ( & V_1 ) ;
V_2 = F_3 ( V_3 . V_4 + V_5 ) ;
F_4 ( ( V_2 & ~ V_8 ) ,
V_3 . V_4 + V_5 ) ;
F_4 ( 0 , V_3 . V_4 + V_10 ) ;
F_5 ( & V_1 ) ;
F_7 ( L_1 ) ;
}
static void F_8 ( void )
{
F_2 ( & V_1 ) ;
V_2 = F_3 ( V_3 . V_4 + V_5 ) ;
V_2 |= ( V_6 | V_7 ) ;
F_4 ( V_2 , V_3 . V_4 + V_5 ) ;
F_5 ( & V_1 ) ;
}
static void F_9 ( int * V_11 )
{
int V_12 ;
F_2 ( & V_1 ) ;
V_2 = F_3 ( V_3 . V_4 + V_5 ) ;
V_12 = ( ( V_2 &
( V_6 | V_7 ) ) != 0 ) ;
F_5 ( & V_1 ) ;
* V_11 = 0 ;
if ( V_12 & 1 )
* V_11 |= V_13 ;
}
static T_1 F_10 ( void )
{
int V_14 ;
T_1 V_15 ;
T_1 V_16 ;
F_2 ( & V_1 ) ;
V_15 = F_3 ( V_3 . V_4 + V_17 ) ;
V_16 = F_3 ( V_3 . V_4 + V_17 ) ;
for ( V_14 = 0 ;
( ( V_14 <= V_18 ) &&
( V_16 == V_15 ) ) ; V_14 ++ ) {
V_16 = F_3 ( V_3 . V_4 + V_17 ) ;
}
F_5 ( & V_1 ) ;
if ( V_16 != V_15 )
return ~ V_19 ;
else
return V_19 ;
}
static int F_11 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( F_12 ( 0 , & V_22 ) )
return - V_23 ;
if ( V_3 . V_24 )
F_13 ( V_25 ) ;
F_1 () ;
F_7 ( L_2 ) ;
return F_14 ( V_20 , V_21 ) ;
}
static int F_15 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
if ( V_26 == 42 ) {
F_6 () ;
} else {
F_16 ( L_3 ) ;
F_8 () ;
}
F_17 ( 0 , & V_22 ) ;
V_26 = 0 ;
return 0 ;
}
static T_2 F_18 ( struct V_21 * V_21 , const char T_3 * V_27 ,
T_4 V_28 , T_5 * V_29 )
{
if ( V_28 ) {
if ( ! V_3 . V_24 ) {
T_4 V_14 ;
V_26 = 0 ;
for ( V_14 = 0 ; V_14 != V_28 ; V_14 ++ ) {
char V_30 ;
if ( F_19 ( V_30 , V_27 + V_14 ) )
return - V_31 ;
if ( V_30 == 'V' )
V_26 = 42 ;
}
}
F_8 () ;
}
return V_28 ;
}
static long F_20 ( struct V_21 * V_21 , unsigned int V_32 , unsigned long V_33 )
{
int V_11 ;
union {
struct V_34 T_3 * V_35 ;
int T_3 * V_14 ;
} V_36 ;
V_36 . V_14 = ( int T_3 * ) V_33 ;
switch ( V_32 ) {
case V_37 :
return F_21 ( V_36 . V_35 , & V_35 ,
sizeof( V_35 ) ) ? - V_31 : 0 ;
case V_38 :
return F_22 ( V_3 . V_39 , V_36 . V_14 ) ;
case V_40 :
F_9 ( & V_11 ) ;
return F_22 ( V_11 , V_36 . V_14 ) ;
case V_41 :
F_8 () ;
return 0 ;
case V_42 :
if ( V_43 )
return - V_44 ;
else
return F_22 ( V_45 , V_36 . V_14 ) ;
default:
return - V_44 ;
}
}
static int T_6 F_23 ( struct V_46 * V_47 )
{
int V_48 ;
T_1 * V_49 ;
T_1 * V_50 ;
V_43 = 0 ;
V_50 = ( T_1 * ) F_24 ( V_47 -> V_51 . V_52 ,
L_4 , NULL ) ;
if ( V_50 == NULL ) {
F_25 ( L_5 ) ;
V_43 = 1 ;
}
V_48 = F_26 ( V_47 -> V_51 . V_52 , 0 , & V_3 . V_53 ) ;
if ( V_48 ) {
F_25 ( L_6 ) ;
return V_48 ;
}
V_49 = ( T_1 * ) F_24 ( V_47 -> V_51 . V_52 ,
L_7 , NULL ) ;
if ( V_49 == NULL ) {
F_25 ( L_8 ) ;
V_43 = 1 ;
} else {
V_3 . V_54 = * V_49 ;
}
V_49 = ( T_1 * ) F_24 ( V_47 -> V_51 . V_52 ,
L_9 , NULL ) ;
if ( V_49 == NULL ) {
F_25 ( L_10 ) ;
V_3 . V_24 = V_55 ;
}
if ( ! V_43 )
V_45 = 2 * ( ( 1 << V_3 . V_54 ) / * V_50 ) ;
if ( ! F_27 ( V_3 . V_53 . V_56 ,
V_3 . V_53 . V_57 - V_3 . V_53 . V_56 + 1 , V_58 ) ) {
V_48 = - V_59 ;
F_28 ( L_11 ) ;
goto V_60;
}
V_3 . V_4 = F_29 ( V_3 . V_53 . V_56 , V_3 . V_53 . V_57 - V_3 . V_53 . V_56 + 1 ) ;
if ( V_3 . V_4 == NULL ) {
V_48 = - V_61 ;
F_28 ( L_12 ) ;
goto V_62;
}
V_48 = F_10 () ;
if ( V_48 == V_19 ) {
F_28 ( L_13 ) ;
goto V_63;
}
F_9 ( & V_3 . V_39 ) ;
V_48 = F_30 ( & V_64 ) ;
if ( V_48 ) {
F_28 ( L_14 ,
V_64 . V_65 , V_48 ) ;
goto V_63;
}
if ( V_43 )
F_7 ( L_15 ,
V_3 . V_24 ) ;
else
F_7 ( L_16 ,
V_45 , V_3 . V_24 ) ;
V_26 = 0 ;
F_17 ( 0 , & V_22 ) ;
return 0 ;
V_63:
F_31 ( V_3 . V_4 ) ;
V_62:
F_32 ( V_3 . V_53 . V_56 , F_33 ( & V_3 . V_53 ) ) ;
V_60:
return V_48 ;
}
static int T_7 F_34 ( struct V_46 * V_51 )
{
F_35 ( & V_64 ) ;
F_31 ( V_3 . V_4 ) ;
F_32 ( V_3 . V_53 . V_56 , F_33 ( & V_3 . V_53 ) ) ;
return 0 ;
}
