static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 V_6 ;
struct V_7 V_8 ;
T_2 V_9 ;
int V_10 ;
F_2 ( & V_6 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_9 = ( ( T_2 ) V_3 << 10 ) | ( 1 << 8 ) | V_4 ;
V_8 . V_11 = & V_9 ;
V_8 . V_12 = 16 ;
V_8 . V_13 = 2 ;
F_3 ( & V_8 , & V_6 ) ;
V_10 = F_4 ( V_2 , & V_6 ) ;
if ( V_10 < 0 )
F_5 ( & V_2 -> V_14 , L_1 , V_10 ) ;
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 gamma [ 12 ] )
{
T_1 V_15 , V_16 ;
for ( V_16 = V_15 = 0 ; V_15 < 4 ; V_15 ++ )
V_16 |= ( gamma [ V_15 ] & 0x300 ) >> ( ( V_15 + 1 ) * 2 ) ;
F_1 ( V_2 , 0x11 , V_16 ) ;
for ( V_16 = V_15 = 0 ; V_15 < 4 ; V_15 ++ )
V_16 |= ( gamma [ V_15 + 4 ] & 0x300 ) >> ( ( V_15 + 1 ) * 2 ) ;
F_1 ( V_2 , 0x12 , V_16 ) ;
for ( V_16 = V_15 = 0 ; V_15 < 4 ; V_15 ++ )
V_16 |= ( gamma [ V_15 + 8 ] & 0x300 ) >> ( ( V_15 + 1 ) * 2 ) ;
F_1 ( V_2 , 0x13 , V_16 ) ;
for ( V_16 = V_15 = 0 ; V_15 < 12 ; V_15 ++ )
F_1 ( V_2 , 0x14 + V_15 , gamma [ V_15 ] & 0xff ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_17 , bool V_18 )
{
T_1 V_19 = V_20 | V_21 |
V_22 | V_23 ;
if ( V_17 )
V_19 &= ~ V_20 ;
if ( V_18 )
V_19 &= ~ V_21 ;
return F_1 ( V_2 , 4 , V_19 ) ;
}
static int F_8 ( struct V_24 * V_25 , bool V_26 )
{
struct V_27 * V_28 = F_9 ( V_25 -> V_14 ) ;
V_28 -> V_29 = V_26 ;
return F_7 ( V_28 -> V_2 , V_28 -> V_29 ,
V_28 -> V_30 ) ;
}
static bool F_10 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_9 ( V_25 -> V_14 ) ;
return V_28 -> V_29 ;
}
static T_3 F_11 ( struct V_31 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
return snprintf ( V_34 , V_35 , L_2 , V_28 -> V_30 ) ;
}
static T_3 F_12 ( struct V_31 * V_14 ,
struct V_32 * V_33 , const char * V_34 , T_4 V_36 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
int V_16 ;
int V_37 ;
V_37 = F_13 ( V_34 , 0 , & V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
V_16 = ! ! V_16 ;
V_37 = F_7 ( V_28 -> V_2 , V_28 -> V_29 , V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
V_28 -> V_30 = V_16 ;
return V_36 ;
}
static T_3 F_14 ( struct V_31 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
return snprintf ( V_34 , V_35 , L_2 , V_28 -> V_38 ) ;
}
static T_3 F_15 ( struct V_31 * V_14 ,
struct V_32 * V_33 , const char * V_34 , T_4 V_36 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
long V_16 ;
int V_37 ;
V_37 = F_16 ( V_34 , 0 , & V_16 ) ;
if ( V_37 != 0 || V_16 & ~ 7 )
return - V_39 ;
V_28 -> V_38 = V_16 ;
V_16 |= V_40 ;
F_1 ( V_28 -> V_2 , 2 , V_16 ) ;
return V_36 ;
}
static T_3 F_17 ( struct V_31 * V_14 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
T_3 V_13 = 0 ;
int V_37 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_18 ( V_28 -> gamma ) ; V_15 ++ ) {
V_37 = snprintf ( V_34 + V_13 , V_35 - V_13 , L_3 ,
V_28 -> gamma [ V_15 ] ) ;
if ( V_37 < 0 )
return V_37 ;
V_13 += V_37 ;
}
V_34 [ V_13 - 1 ] = '\n' ;
return V_13 ;
}
static T_3 F_19 ( struct V_31 * V_14 ,
struct V_32 * V_33 , const char * V_34 , T_4 V_36 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
unsigned int V_41 [ 12 ] ;
int V_37 ;
int V_15 ;
V_37 = sscanf ( V_34 , L_4 ,
& V_41 [ 0 ] , & V_41 [ 1 ] , & V_41 [ 2 ] , & V_41 [ 3 ] , & V_41 [ 4 ] , & V_41 [ 5 ] ,
& V_41 [ 6 ] , & V_41 [ 7 ] , & V_41 [ 8 ] , & V_41 [ 9 ] , & V_41 [ 10 ] , & V_41 [ 11 ] ) ;
if ( V_37 != 12 )
return - V_39 ;
for ( V_15 = 0 ; V_15 < 12 ; V_15 ++ )
V_28 -> gamma [ V_15 ] = V_41 [ V_15 ] ;
F_6 ( V_28 -> V_2 , V_28 -> gamma ) ;
return V_36 ;
}
static int F_20 ( struct V_27 * V_28 )
{
int V_10 ;
if ( V_28 -> V_42 )
return 0 ;
V_10 = F_21 ( V_28 -> V_43 ) ;
if ( V_10 != 0 )
return V_10 ;
F_22 ( 160 ) ;
if ( F_23 ( V_28 -> V_44 ) )
F_24 ( V_28 -> V_44 , 1 ) ;
F_1 ( V_28 -> V_2 , 2 ,
F_25 ( V_28 -> V_38 ) | V_40 ) ;
F_1 ( V_28 -> V_2 , 3 , V_45 ) ;
F_1 ( V_28 -> V_2 , 0x20 , 0xf0 ) ;
F_1 ( V_28 -> V_2 , 0x21 , 0xf0 ) ;
F_7 ( V_28 -> V_2 , V_28 -> V_29 ,
V_28 -> V_30 ) ;
F_6 ( V_28 -> V_2 , V_28 -> gamma ) ;
V_28 -> V_42 = 1 ;
return 0 ;
}
static void F_26 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_42 )
return;
F_1 ( V_28 -> V_2 , 3 ,
V_46 | V_47 ) ;
if ( F_23 ( V_28 -> V_44 ) )
F_24 ( V_28 -> V_44 , 0 ) ;
F_22 ( 50 ) ;
F_1 ( V_28 -> V_2 , 3 , V_46 ) ;
F_27 ( V_28 -> V_43 ) ;
V_28 -> V_42 = 0 ;
}
static int F_28 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
int V_10 ;
if ( F_30 ( V_25 ) )
return 0 ;
V_10 = V_48 -> V_49 . V_50 -> V_51 ( V_48 , V_25 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
}
static void F_31 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
if ( ! F_30 ( V_25 ) )
return;
V_48 -> V_49 . V_50 -> V_52 ( V_48 , V_25 ) ;
}
static int F_32 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
int V_10 ;
if ( ! F_30 ( V_25 ) )
return - V_53 ;
if ( F_33 ( V_25 ) )
return 0 ;
if ( V_28 -> V_54 )
V_48 -> V_49 . V_50 -> V_55 ( V_48 , V_28 -> V_54 ) ;
V_48 -> V_49 . V_50 -> V_56 ( V_48 , & V_28 -> V_57 ) ;
V_10 = V_48 -> V_49 . V_50 -> V_26 ( V_48 ) ;
if ( V_10 )
return V_10 ;
if ( ! V_28 -> V_58 ) {
V_10 = F_20 ( V_28 ) ;
if ( V_10 ) {
V_48 -> V_49 . V_50 -> V_59 ( V_48 ) ;
return V_10 ;
}
}
V_25 -> V_60 = V_61 ;
return 0 ;
}
static void F_34 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
if ( ! F_33 ( V_25 ) )
return;
V_48 -> V_49 . V_50 -> V_59 ( V_48 ) ;
if ( ! V_28 -> V_58 )
F_26 ( V_28 ) ;
V_25 -> V_60 = V_62 ;
}
static void F_35 ( struct V_24 * V_25 ,
struct V_63 * V_57 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
V_28 -> V_57 = * V_57 ;
V_25 -> V_64 . V_57 = * V_57 ;
V_48 -> V_49 . V_50 -> V_56 ( V_48 , V_57 ) ;
}
static void F_36 ( struct V_24 * V_25 ,
struct V_63 * V_57 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
* V_57 = V_28 -> V_57 ;
}
static int F_37 ( struct V_24 * V_25 ,
struct V_63 * V_57 )
{
struct V_27 * V_28 = F_29 ( V_25 ) ;
struct V_24 * V_48 = V_28 -> V_48 ;
return V_48 -> V_49 . V_50 -> V_65 ( V_48 , V_57 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = V_2 -> V_14 . V_68 ;
struct V_27 * V_28 = F_9 ( & V_2 -> V_14 ) ;
struct V_24 * V_48 ;
int V_69 ;
V_69 = F_39 ( V_67 , L_5 , 0 ) ;
if ( ! F_23 ( V_69 ) ) {
F_40 ( & V_2 -> V_14 , L_6 ) ;
return V_69 ;
}
V_28 -> V_44 = V_69 ;
V_48 = F_41 ( V_67 ) ;
if ( F_42 ( V_48 ) ) {
F_40 ( & V_2 -> V_14 , L_7 ) ;
return F_43 ( V_48 ) ;
}
V_28 -> V_48 = V_48 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
struct V_24 * V_25 ;
int V_10 ;
F_45 ( & V_2 -> V_14 , L_8 , V_70 ) ;
V_2 -> V_12 = 16 ;
V_2 -> V_38 = V_71 ;
V_10 = F_46 ( V_2 ) ;
if ( V_10 < 0 ) {
F_40 ( & V_2 -> V_14 , L_9 , V_10 ) ;
return V_10 ;
}
V_28 = F_47 ( & V_2 -> V_14 , sizeof( * V_28 ) , V_72 ) ;
if ( V_28 == NULL )
return - V_73 ;
F_48 ( & V_2 -> V_14 , V_28 ) ;
V_28 -> V_2 = V_2 ;
if ( ! V_2 -> V_14 . V_68 )
return - V_53 ;
V_10 = F_38 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_28 -> V_38 = V_74 ;
memcpy ( V_28 -> gamma , V_75 , sizeof( V_28 -> gamma ) ) ;
V_28 -> V_43 = F_49 ( & V_2 -> V_14 , L_10 ) ;
if ( F_42 ( V_28 -> V_43 ) ) {
F_40 ( & V_2 -> V_14 , L_11 ) ;
V_10 = F_43 ( V_28 -> V_43 ) ;
goto V_76;
}
if ( F_23 ( V_28 -> V_44 ) ) {
V_10 = F_50 ( & V_2 -> V_14 ,
V_28 -> V_44 , V_77 ,
L_12 ) ;
if ( V_10 < 0 ) {
F_40 ( & V_2 -> V_14 , L_13 ) ;
goto V_78;
}
}
V_10 = F_51 ( & V_2 -> V_14 . V_79 , & V_80 ) ;
if ( V_10 ) {
F_40 ( & V_2 -> V_14 , L_14 ) ;
goto V_81;
}
V_28 -> V_57 = V_82 ;
V_25 = & V_28 -> V_25 ;
V_25 -> V_14 = & V_2 -> V_14 ;
V_25 -> V_83 = & V_84 ;
V_25 -> type = V_85 ;
V_25 -> V_86 = V_87 ;
V_25 -> V_64 . V_57 = V_28 -> V_57 ;
V_10 = F_52 ( V_25 ) ;
if ( V_10 ) {
F_40 ( & V_2 -> V_14 , L_15 ) ;
goto V_88;
}
return 0 ;
V_88:
F_53 ( & V_2 -> V_14 . V_79 , & V_80 ) ;
V_81:
V_78:
V_76:
F_54 ( V_28 -> V_48 ) ;
return V_10 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_9 ( & V_2 -> V_14 ) ;
struct V_24 * V_25 = & V_28 -> V_25 ;
struct V_24 * V_48 = V_28 -> V_48 ;
F_45 ( & V_28 -> V_2 -> V_14 , L_8 , V_70 ) ;
F_56 ( V_25 ) ;
F_34 ( V_25 ) ;
F_31 ( V_25 ) ;
F_54 ( V_48 ) ;
F_53 ( & V_2 -> V_14 . V_79 , & V_80 ) ;
return 0 ;
}
static int F_57 ( struct V_31 * V_14 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
F_45 ( V_14 , L_16 , V_28 ) ;
V_28 -> V_89 = V_28 -> V_42 ;
F_26 ( V_28 ) ;
V_28 -> V_58 = 1 ;
return 0 ;
}
static int F_58 ( struct V_31 * V_14 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
int V_37 ;
F_45 ( V_14 , L_17 ) ;
if ( V_28 -> V_89 ) {
V_37 = F_20 ( V_28 ) ;
if ( V_37 )
return V_37 ;
}
V_28 -> V_58 = 0 ;
return 0 ;
}
