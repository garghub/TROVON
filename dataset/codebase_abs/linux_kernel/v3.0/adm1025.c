static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_8 -> V_9 [ V_6 ] ,
V_10 [ V_6 ] ) ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_8 -> V_11 [ V_6 ] ,
V_10 [ V_6 ] ) ) ;
}
static T_1
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_8 -> V_12 [ V_6 ] ,
V_10 [ V_6 ] ) ) ;
}
static T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_8 ( V_8 -> V_13 [ V_6 ] ) ) ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_8 ( V_8 -> V_14 [ V_6 ] ) ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , F_8 ( V_8 -> V_15 [ V_6 ] ) ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
long V_19 = F_14 ( V_5 , NULL , 10 ) ;
F_15 ( & V_8 -> V_20 ) ;
V_8 -> V_11 [ V_6 ] = F_16 ( V_19 , V_10 [ V_6 ] ) ;
F_17 ( V_18 , F_18 ( V_6 ) ,
V_8 -> V_11 [ V_6 ] ) ;
F_19 ( & V_8 -> V_20 ) ;
return V_16 ;
}
static T_1 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
long V_19 = F_14 ( V_5 , NULL , 10 ) ;
F_15 ( & V_8 -> V_20 ) ;
V_8 -> V_12 [ V_6 ] = F_16 ( V_19 , V_10 [ V_6 ] ) ;
F_17 ( V_18 , F_21 ( V_6 ) ,
V_8 -> V_12 [ V_6 ] ) ;
F_19 ( & V_8 -> V_20 ) ;
return V_16 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
long V_19 = F_14 ( V_5 , NULL , 10 ) ;
F_15 ( & V_8 -> V_20 ) ;
V_8 -> V_14 [ V_6 ] = F_23 ( V_19 ) ;
F_17 ( V_18 , F_24 ( V_6 ) ,
V_8 -> V_14 [ V_6 ] ) ;
F_19 ( & V_8 -> V_20 ) ;
return V_16 ;
}
static T_1 F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
int V_6 = F_2 ( V_4 ) -> V_6 ;
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
long V_19 = F_14 ( V_5 , NULL , 10 ) ;
F_15 ( & V_8 -> V_20 ) ;
V_8 -> V_15 [ V_6 ] = F_23 ( V_19 ) ;
F_17 ( V_18 , F_26 ( V_6 ) ,
V_8 -> V_15 [ V_6 ] ) ;
F_19 ( & V_8 -> V_20 ) ;
return V_16 ;
}
static T_1
F_27 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_21 ) ;
}
static T_1
F_28 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
int V_22 = F_2 ( V_4 ) -> V_6 ;
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , ( V_8 -> V_21 >> V_22 ) & 1 ) ;
}
static T_1
F_29 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_30 ( V_8 -> V_23 , V_8 -> V_24 ) ) ;
}
static T_1
F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_8 -> V_24 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_7 * V_8 = F_32 ( V_2 ) ;
V_8 -> V_24 = F_34 ( V_5 , NULL , 10 ) ;
return V_16 ;
}
static int F_35 ( struct V_17 * V_18 ,
struct V_25 * V_26 )
{
struct V_27 * V_28 = V_18 -> V_28 ;
const char * V_29 ;
T_3 V_30 , V_31 ;
if ( ! F_36 ( V_28 , V_32 ) )
return - V_33 ;
if ( ( F_37 ( V_18 , V_34 ) & 0x80 )
|| ( F_37 ( V_18 , V_35 ) & 0xC0 )
|| ( F_37 ( V_18 , V_36 ) & 0xBC ) ) {
F_38 ( & V_28 -> V_2 , L_3 ,
V_18 -> V_37 ) ;
return - V_33 ;
}
V_31 = F_37 ( V_18 , V_38 ) ;
if ( ( V_31 & 0xF0 ) != 0x20 )
return - V_33 ;
V_30 = F_37 ( V_18 , V_39 ) ;
if ( V_30 == 0x41 )
V_29 = L_4 ;
else if ( V_30 == 0xA1 && V_18 -> V_37 != 0x2E )
V_29 = L_5 ;
else
return - V_33 ;
F_39 ( V_26 -> type , V_29 , V_40 ) ;
return 0 ;
}
static int F_40 ( struct V_17 * V_18 ,
const struct V_41 * V_42 )
{
struct V_7 * V_8 ;
int V_43 ;
T_3 V_44 ;
V_8 = F_41 ( sizeof( struct V_7 ) , V_45 ) ;
if ( ! V_8 ) {
V_43 = - V_46 ;
goto exit;
}
F_42 ( V_18 , V_8 ) ;
F_43 ( & V_8 -> V_20 ) ;
F_44 ( V_18 ) ;
if ( ( V_43 = F_45 ( & V_18 -> V_2 . V_47 , & V_48 ) ) )
goto V_49;
V_44 = F_37 ( V_18 , V_34 ) ;
if ( ! ( V_44 & 0x20 ) ) {
if ( ( V_43 = F_45 ( & V_18 -> V_2 . V_47 ,
& V_50 ) ) )
goto V_51;
}
V_8 -> V_52 = F_46 ( & V_18 -> V_2 ) ;
if ( F_47 ( V_8 -> V_52 ) ) {
V_43 = F_48 ( V_8 -> V_52 ) ;
goto V_51;
}
return 0 ;
V_51:
F_49 ( & V_18 -> V_2 . V_47 , & V_48 ) ;
F_49 ( & V_18 -> V_2 . V_47 , & V_50 ) ;
V_49:
F_50 ( V_8 ) ;
exit:
return V_43 ;
}
static void F_44 ( struct V_17 * V_18 )
{
T_3 V_53 ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
int V_54 ;
V_8 -> V_24 = F_51 () ;
for ( V_54 = 0 ; V_54 < 6 ; V_54 ++ ) {
V_53 = F_37 ( V_18 ,
F_21 ( V_54 ) ) ;
if ( V_53 == 0 )
F_17 ( V_18 ,
F_21 ( V_54 ) ,
0xFF ) ;
}
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
V_53 = F_37 ( V_18 ,
F_26 ( V_54 ) ) ;
if ( V_53 == 0 )
F_17 ( V_18 ,
F_26 ( V_54 ) ,
0x7F ) ;
}
V_53 = F_37 ( V_18 , V_34 ) ;
if ( ! ( V_53 & 0x01 ) )
F_17 ( V_18 , V_34 ,
( V_53 & 0x7E ) | 0x01 ) ;
}
static int F_52 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = F_13 ( V_18 ) ;
F_53 ( V_8 -> V_52 ) ;
F_49 ( & V_18 -> V_2 . V_47 , & V_48 ) ;
F_49 ( & V_18 -> V_2 . V_47 , & V_50 ) ;
F_50 ( V_8 ) ;
return 0 ;
}
static struct V_7 * F_3 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = F_12 ( V_2 ) ;
struct V_7 * V_8 = F_13 ( V_18 ) ;
F_15 ( & V_8 -> V_20 ) ;
if ( F_54 ( V_55 , V_8 -> V_56 + V_57 * 2 ) || ! V_8 -> V_58 ) {
int V_54 ;
F_38 ( & V_18 -> V_2 , L_6 ) ;
for ( V_54 = 0 ; V_54 < 6 ; V_54 ++ ) {
V_8 -> V_9 [ V_54 ] = F_37 ( V_18 ,
F_55 ( V_54 ) ) ;
V_8 -> V_11 [ V_54 ] = F_37 ( V_18 ,
F_18 ( V_54 ) ) ;
V_8 -> V_12 [ V_54 ] = F_37 ( V_18 ,
F_21 ( V_54 ) ) ;
}
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
V_8 -> V_13 [ V_54 ] = F_37 ( V_18 ,
F_56 ( V_54 ) ) ;
V_8 -> V_14 [ V_54 ] = F_37 ( V_18 ,
F_24 ( V_54 ) ) ;
V_8 -> V_15 [ V_54 ] = F_37 ( V_18 ,
F_26 ( V_54 ) ) ;
}
V_8 -> V_21 = F_37 ( V_18 ,
V_35 )
| ( F_37 ( V_18 ,
V_36 ) << 8 ) ;
V_8 -> V_23 = ( F_37 ( V_18 ,
V_59 ) & 0x0f )
| ( ( F_37 ( V_18 ,
V_60 ) & 0x01 ) << 4 ) ;
V_8 -> V_56 = V_55 ;
V_8 -> V_58 = 1 ;
}
F_19 ( & V_8 -> V_20 ) ;
return V_8 ;
}
static int T_4 F_57 ( void )
{
return F_58 ( & V_61 ) ;
}
static void T_5 F_59 ( void )
{
F_60 ( & V_61 ) ;
}
