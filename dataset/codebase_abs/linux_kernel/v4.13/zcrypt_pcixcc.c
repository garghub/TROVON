static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned long long V_5 ;
unsigned int V_6 ;
struct {
struct V_7 V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
} V_13 ( ( V_14 ) ) * V_15 ;
struct {
struct V_16 V_8 ;
struct V_11 V_12 ;
char V_17 [ 2 ] ;
short int V_18 ;
char V_19 [ 8 ] ;
short int V_20 ;
short int V_21 ;
} V_22 * V_23 ;
int V_24 , V_25 ;
F_2 ( & V_4 ) ;
V_4 . V_26 = ( void * ) F_3 ( V_27 ) ;
if ( ! V_4 . V_26 )
return - V_28 ;
F_4 ( & V_4 , 4 , & V_6 ) ;
V_23 = V_4 . V_26 ;
V_23 -> V_12 . V_6 = F_5 ( V_2 -> V_29 ) ;
V_24 = F_6 ( V_2 -> V_29 , 0x0102030405060708ULL , V_4 . V_26 ,
V_4 . V_30 ) ;
if ( V_24 )
goto V_31;
for ( V_25 = 0 ; V_25 < 2 * V_32 ; V_25 ++ ) {
F_7 ( 1000 / V_32 ) ;
V_24 = F_8 ( V_2 -> V_29 , & V_5 , V_4 . V_26 , 4096 ) ;
if ( V_24 == 0 && V_5 == 0x0102030405060708ULL )
break;
}
if ( V_25 >= 2 * V_32 ) {
V_24 = - V_33 ;
goto V_31;
}
V_15 = V_4 . V_26 ;
if ( V_15 -> V_12 . V_34 == 0 && V_15 -> V_12 . V_35 == 0 )
V_24 = 1 ;
else
V_24 = 0 ;
V_31:
F_9 ( ( unsigned long ) V_4 . V_26 ) ;
return V_24 ;
}
static int F_10 ( struct V_36 * V_37 )
{
static const int V_38 [] = {
1000 , 1400 , 2400 , 1100 , 1500 , 2600 , 100 , 12 } ;
static const int V_39 [] = {
500 , 700 , 1400 , 550 , 800 , 1500 , 80 , 10 } ;
struct V_40 * V_41 = F_11 ( & V_37 -> V_42 ) ;
struct V_43 * V_44 ;
int V_24 = 0 ;
V_44 = F_12 () ;
if ( ! V_44 )
return - V_28 ;
V_44 -> V_45 = V_41 ;
V_41 -> V_46 = V_44 ;
switch ( V_41 -> V_37 . V_47 ) {
case V_48 :
V_44 -> V_49 = V_50 ;
V_44 -> V_51 = L_1 ;
memcpy ( V_44 -> V_52 , V_38 ,
sizeof( V_38 ) ) ;
V_44 -> V_53 = V_54 ;
V_44 -> V_55 = V_56 ;
V_44 -> V_57 = V_56 ;
break;
case V_58 :
V_44 -> V_49 = V_59 ;
V_44 -> V_51 = L_2 ;
memcpy ( V_44 -> V_52 , V_39 ,
sizeof( V_39 ) ) ;
V_44 -> V_53 = V_60 ;
V_44 -> V_55 = V_61 ;
V_44 -> V_57 = V_61 ;
break;
default:
F_13 ( V_44 ) ;
return - V_33 ;
}
V_44 -> V_62 = 1 ;
V_24 = F_14 ( V_44 ) ;
if ( V_24 ) {
V_41 -> V_46 = NULL ;
F_13 ( V_44 ) ;
}
return V_24 ;
}
static void F_15 ( struct V_36 * V_37 )
{
struct V_43 * V_44 = F_11 ( & V_37 -> V_42 ) -> V_46 ;
if ( V_44 )
F_16 ( V_44 ) ;
}
static int F_17 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_18 ( & V_37 -> V_42 ) ;
struct V_63 * V_64 ;
int V_24 ;
V_64 = F_19 ( V_65 ) ;
if ( ! V_64 )
return - V_28 ;
V_64 -> V_66 = V_2 ;
V_64 -> V_62 = 1 ;
F_20 ( & V_64 -> V_67 , 0 ) ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 ) {
F_21 ( V_64 ) ;
return V_24 ;
}
if ( V_24 )
V_64 -> V_68 = F_22 ( V_69 ,
V_70 ) ;
else
V_64 -> V_68 = F_22 ( V_69 ,
V_71 ) ;
F_23 ( V_2 , & V_64 -> V_15 ) ;
V_2 -> V_72 = V_73 ,
V_2 -> V_46 = V_64 ;
V_24 = F_24 ( V_64 ) ;
if ( V_24 ) {
V_2 -> V_46 = NULL ;
F_21 ( V_64 ) ;
}
return V_24 ;
}
static void F_25 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_18 ( & V_37 -> V_42 ) ;
struct V_63 * V_64 = V_2 -> V_46 ;
F_26 ( V_2 ) ;
if ( V_64 )
F_27 ( V_64 ) ;
}
int T_1 F_28 ( void )
{
int V_24 ;
V_24 = F_29 ( & V_74 ,
V_75 , L_3 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_29 ( & V_76 ,
V_75 , L_4 ) ;
if ( V_24 )
F_30 ( & V_74 ) ;
return V_24 ;
}
void F_31 ( void )
{
F_30 ( & V_76 ) ;
F_30 ( & V_74 ) ;
}
