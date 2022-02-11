static int
F_1 ( void )
{
F_2 ( 0xffff , 0xff ) ;
return 0 ;
}
static int
F_3 ( const char T_1 * V_1 , T_2 V_2 )
{
if ( F_4 ( V_1 , V_2 ) ) {
F_5 ( V_3
L_1 ) ;
return - V_4 ;
}
return 0 ;
}
static int
F_6 ( const char T_1 * V_1 , T_2 V_2 )
{
int V_5 , V_6 , V_7 ;
T_3 V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
char V_13 [ 16 ] ;
if ( V_2 >= sizeof V_13 )
return - V_4 ;
V_13 [ sizeof V_13 - 1 ] = '\0' ;
if ( F_7 ( V_13 , V_1 , V_2 ) )
return - V_14 ;
V_7 = sscanf ( V_13 , L_2 , & V_5 , & V_6 ) ;
if ( V_7 != 2 ) {
F_8 ( L_3 , V_13 ) ;
return - V_4 ;
}
V_10 = F_9 ( V_5 , V_6 , 0 ) ;
if ( ! V_10 )
return - V_4 ;
F_10 ( & V_10 -> V_15 , V_8 ) ;
F_11 ( V_10 ) ;
F_2 ( V_5 , V_6 ) ;
V_16:
V_12 = F_12 ( V_10 ) ;
F_13 ( & V_10 -> V_15 , V_8 ) ;
if ( ! V_12 && ! F_14 ( 250 ) ) {
F_10 ( & V_10 -> V_15 , V_8 ) ;
goto V_16;
}
F_15 ( V_10 ) ;
if ( V_12 ) {
struct V_17 V_18 ;
F_16 ( & V_18 ) ;
F_17 ( & V_18 , V_12 ) ;
F_18 ( & V_18 ) ;
}
return 0 ;
}
void
F_19 ( char * V_19 )
{
struct V_20 * V_21 ;
char * V_22 ;
T_3 V_8 , V_7 ;
V_7 = strlen ( V_19 ) ;
F_10 ( & V_23 , V_8 ) ;
V_21 = V_24 + V_25 ;
if ( ( V_21 -> V_8 & V_26 ) ) {
V_27: F_13 ( & V_23 , V_8 ) ;
return;
}
V_22 = F_20 ( V_7 , V_28 ) ;
if ( V_22 == NULL ) {
F_5 ( V_3 L_4 , V_7 ) ;
goto V_27;
}
memcpy ( V_22 , V_19 , V_7 ) ;
V_21 -> V_19 = V_22 ;
V_21 -> V_8 |= V_26 ;
V_21 -> V_29 = V_7 ;
V_25 ++ ;
V_25 %= F_21 ( V_24 ) ;
F_13 ( & V_23 , V_8 ) ;
if ( V_30 )
F_22 ( & V_31 ) ;
}
static T_4
F_23 ( struct V_32 * V_33 , const char T_1 * V_13 , T_2 V_34 , T_5 * V_35 )
{
int V_36 = - V_4 ;
switch ( ( unsigned long ) V_33 -> V_37 ) {
default:
F_5 ( V_38 L_5 ) ;
break;
case V_39 :
V_36 = F_1 () ;
break;
case V_40 :
V_36 = F_3 ( V_13 , V_34 ) ;
break;
case V_41 :
V_36 = F_6 ( V_13 , V_34 ) ;
break;
case V_42 :
V_36 = F_24 ( V_13 , V_34 ) ;
break;
}
if ( V_36 == 0 )
V_36 = V_34 ;
return V_36 ;
}
static int
F_25 ( struct V_43 * V_43 , struct V_32 * V_33 )
{
int V_7 , V_44 ;
F_26 ( & V_45 ) ;
V_7 = F_27 ( V_43 ) ;
V_33 -> V_37 = ( void * ) ( unsigned long ) V_7 ;
for ( V_44 = 0 ; V_44 < F_21 ( V_46 ) ; ++ V_44 )
if ( V_46 [ V_44 ] . V_6 == V_7 ) {
F_28 ( & V_45 ) ;
return 0 ;
}
F_28 ( & V_45 ) ;
return - V_4 ;
}
static int
F_29 ( struct V_43 * V_43 , struct V_32 * V_33 )
{
return 0 ;
}
static T_4
F_30 ( struct V_32 * V_33 , char T_1 * V_13 , T_2 V_34 , T_5 * V_47 )
{
unsigned long V_7 ;
char * V_22 ;
struct V_20 * V_21 ;
T_4 V_29 ;
T_3 V_8 ;
V_7 = ( unsigned long ) V_33 -> V_37 ;
if ( V_7 != V_48 )
return - V_14 ;
F_10 ( & V_23 , V_8 ) ;
for (; ; ) {
V_21 = V_24 + V_49 ;
if ( ( V_21 -> V_8 & V_26 ) != 0 )
break;
if ( V_33 -> V_50 & V_51 ) {
F_13 ( & V_23 , V_8 ) ;
return - V_52 ;
}
V_30 ++ ;
F_13 ( & V_23 , V_8 ) ;
V_7 = F_31 ( & V_31 ) ;
F_10 ( & V_23 , V_8 ) ;
V_30 -- ;
if ( V_7 ) {
F_13 ( & V_23 , V_8 ) ;
return - V_53 ;
}
}
if ( V_21 -> V_29 > V_34 ) {
F_13 ( & V_23 , V_8 ) ;
return - V_52 ;
}
V_22 = V_21 -> V_19 ;
V_29 = V_21 -> V_29 ;
V_21 -> V_19 = NULL ;
V_21 -> V_8 &= ~ V_26 ;
V_49 ++ ;
V_49 %= F_21 ( V_24 ) ;
F_13 ( & V_23 , V_8 ) ;
V_7 = F_32 ( V_13 , V_22 , V_29 ) ;
F_33 ( V_22 ) ;
return V_7 == 0 ? V_29 : - V_14 ;
}
static char * F_34 ( struct V_54 * V_55 , T_6 * V_56 )
{
return F_35 ( V_57 , L_6 , F_36 ( V_55 ) ) ;
}
int T_7
F_37 ( void )
{
int V_7 , V_44 ;
V_7 = F_38 ( V_58 , L_7 , & V_59 ) ;
if ( V_7 < 0 ) {
F_5 ( V_3 L_8 ) ;
return V_7 ;
}
F_39 ( & V_31 ) ;
F_40 ( & V_23 ) ;
V_60 = F_41 ( V_61 , L_9 ) ;
if ( F_42 ( V_60 ) ) {
F_43 ( V_58 , L_7 ) ;
return F_44 ( V_60 ) ;
}
V_60 -> V_62 = F_34 ;
for ( V_44 = 0 ; V_44 < F_21 ( V_46 ) ; ++ V_44 )
F_45 ( V_60 , NULL ,
F_46 ( V_58 , V_46 [ V_44 ] . V_6 ) , NULL ,
V_46 [ V_44 ] . V_63 ) ;
return 0 ;
}
void
F_47 ( void )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_21 ( V_46 ) ; ++ V_44 )
F_48 ( V_60 , F_46 ( V_58 , V_46 [ V_44 ] . V_6 ) ) ;
F_49 ( V_60 ) ;
F_43 ( V_58 , L_7 ) ;
}
