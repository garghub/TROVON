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
T_1 V_19 = V_20 | V_21 | \
V_22 | V_23 ;
if ( V_17 )
V_19 &= ~ V_20 ;
if ( V_18 )
V_19 &= ~ V_21 ;
return F_1 ( V_2 , 4 , V_19 ) ;
}
static int F_8 ( struct V_24 * V_25 , bool V_26 )
{
struct V_27 * V_28 = F_9 ( & V_25 -> V_14 ) ;
V_28 -> V_29 = V_26 ;
return F_7 ( V_28 -> V_2 , V_28 -> V_29 ,
V_28 -> V_30 ) ;
}
static bool F_10 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_9 ( & V_25 -> V_14 ) ;
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
static inline struct V_42
* F_20 ( const struct V_24 * V_25 )
{
return (struct V_42 * ) V_25 -> V_4 ;
}
static int F_21 ( struct V_27 * V_28 )
{
int V_10 ;
if ( V_28 -> V_43 )
return 0 ;
V_10 = F_22 ( V_28 -> V_44 ) ;
if ( V_10 != 0 )
return V_10 ;
F_23 ( 160 ) ;
if ( F_24 ( V_28 -> V_45 ) )
F_25 ( V_28 -> V_45 , 1 ) ;
F_1 ( V_28 -> V_2 , 2 ,
F_26 ( V_28 -> V_38 ) | V_40 ) ;
F_1 ( V_28 -> V_2 , 3 , V_46 ) ;
F_1 ( V_28 -> V_2 , 0x20 , 0xf0 ) ;
F_1 ( V_28 -> V_2 , 0x21 , 0xf0 ) ;
F_7 ( V_28 -> V_2 , V_28 -> V_29 ,
V_28 -> V_30 ) ;
F_6 ( V_28 -> V_2 , V_28 -> gamma ) ;
V_28 -> V_43 = 1 ;
return 0 ;
}
static void F_27 ( struct V_27 * V_28 )
{
if ( ! V_28 -> V_43 )
return;
F_1 ( V_28 -> V_2 , 3 ,
V_47 | V_48 ) ;
if ( F_24 ( V_28 -> V_45 ) )
F_25 ( V_28 -> V_45 , 0 ) ;
F_23 ( 50 ) ;
F_1 ( V_28 -> V_2 , 3 , V_47 ) ;
F_28 ( V_28 -> V_44 ) ;
V_28 -> V_43 = 0 ;
}
static int F_29 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_9 ( & V_25 -> V_14 ) ;
int V_10 ;
if ( V_25 -> V_49 == V_50 )
return 0 ;
F_30 ( V_25 , & V_25 -> V_51 . V_52 ) ;
F_31 ( V_25 , V_25 -> V_53 . V_54 . V_55 ) ;
V_10 = F_32 ( V_25 ) ;
if ( V_10 )
goto V_56;
if ( ! V_28 -> V_57 ) {
V_10 = F_21 ( V_28 ) ;
if ( V_10 )
goto V_58;
}
V_25 -> V_49 = V_50 ;
return 0 ;
V_58:
F_33 ( V_25 ) ;
V_56:
return V_10 ;
}
static void F_34 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_9 ( & V_25 -> V_14 ) ;
if ( V_25 -> V_49 != V_50 )
return;
F_33 ( V_25 ) ;
if ( ! V_28 -> V_57 )
F_27 ( V_28 ) ;
}
static int F_35 ( struct V_24 * V_25 )
{
F_36 ( & V_25 -> V_14 , L_5 ) ;
return F_29 ( V_25 ) ;
}
static void F_37 ( struct V_24 * V_25 )
{
F_36 ( & V_25 -> V_14 , L_6 ) ;
F_34 ( V_25 ) ;
V_25 -> V_49 = V_59 ;
}
static int F_38 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = V_60 ;
struct V_42 * V_61 = F_20 ( V_25 ) ;
int V_37 = 0 ;
F_36 ( & V_25 -> V_14 , L_7 ) ;
if ( V_28 == NULL ) {
F_39 ( & V_25 -> V_14 , L_8 ) ;
return - V_62 ;
}
if ( ! V_61 )
return - V_39 ;
V_28 -> V_45 = V_61 -> V_45 ;
V_25 -> V_51 . V_52 = V_63 ;
V_25 -> V_64 . V_65 = 24 ;
V_28 -> V_38 = V_66 ;
memcpy ( V_28 -> gamma , V_67 , sizeof( V_28 -> gamma ) ) ;
V_28 -> V_44 = F_40 ( & V_25 -> V_14 , L_9 ) ;
if ( F_41 ( V_28 -> V_44 ) ) {
F_39 ( & V_25 -> V_14 , L_10 ) ;
V_37 = F_42 ( V_28 -> V_44 ) ;
goto V_68;
}
if ( F_24 ( V_28 -> V_45 ) ) {
V_37 = F_43 ( & V_25 -> V_14 ,
V_28 -> V_45 , V_69 ,
L_11 ) ;
if ( V_37 < 0 ) {
F_39 ( & V_25 -> V_14 , L_12 ) ;
goto V_70;
}
}
V_37 = F_44 ( & V_25 -> V_14 . V_71 , & V_72 ) ;
if ( V_37 )
F_5 ( & V_25 -> V_14 , L_13 ) ;
F_45 ( & V_25 -> V_14 , V_28 ) ;
return 0 ;
V_70:
F_46 ( V_28 -> V_44 ) ;
V_68:
F_47 ( V_28 ) ;
return V_37 ;
}
static void F_48 ( struct V_24 * V_25 )
{
struct V_27 * V_28 = F_9 ( & V_25 -> V_14 ) ;
F_36 ( & V_25 -> V_14 , L_14 ) ;
F_49 ( & V_25 -> V_14 . V_71 , & V_72 ) ;
F_46 ( V_28 -> V_44 ) ;
}
static void F_50 ( struct V_24 * V_25 ,
struct V_73 * V_52 )
{
F_30 ( V_25 , V_52 ) ;
V_25 -> V_51 . V_52 = * V_52 ;
}
static int F_51 ( struct V_24 * V_25 ,
struct V_73 * V_52 )
{
return F_52 ( V_25 , V_52 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_14 . V_74 ;
struct V_27 * V_28 ;
int V_37 ;
if ( V_25 == NULL ) {
F_39 ( & V_2 -> V_14 , L_15 ) ;
return - V_62 ;
}
if ( V_60 != NULL )
return - V_75 ;
V_2 -> V_12 = 16 ;
V_2 -> V_38 = V_76 ;
V_37 = F_54 ( V_2 ) ;
if ( V_37 < 0 ) {
F_39 ( & V_2 -> V_14 , L_16 , V_37 ) ;
return V_37 ;
}
V_28 = F_55 ( sizeof( * V_28 ) , V_77 ) ;
if ( V_28 == NULL )
return - V_78 ;
V_28 -> V_2 = V_2 ;
F_45 ( & V_2 -> V_14 , V_28 ) ;
V_60 = V_28 ;
F_56 ( & V_79 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_9 ( & V_2 -> V_14 ) ;
F_58 ( & V_79 ) ;
F_47 ( V_28 ) ;
V_60 = NULL ;
return 0 ;
}
static int F_59 ( struct V_31 * V_14 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
F_36 ( V_14 , L_17 , V_28 ) ;
V_28 -> V_80 = V_28 -> V_43 ;
F_27 ( V_28 ) ;
V_28 -> V_57 = 1 ;
return 0 ;
}
static int F_60 ( struct V_31 * V_14 )
{
struct V_27 * V_28 = F_9 ( V_14 ) ;
int V_37 ;
F_36 ( V_14 , L_18 ) ;
if ( V_28 -> V_80 ) {
V_37 = F_21 ( V_28 ) ;
if ( V_37 )
return V_37 ;
}
V_28 -> V_57 = 0 ;
return 0 ;
}
