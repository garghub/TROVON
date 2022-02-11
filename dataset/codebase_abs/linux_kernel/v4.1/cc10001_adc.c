static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , 0 ) ;
F_6 ( V_2 -> V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 ,
V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_9 )
{
T_1 V_4 ;
V_4 = ( V_9 & V_10 ) | V_11 ;
F_1 ( V_2 , V_12 , V_4 ) ;
F_9 ( 1 ) ;
V_4 = F_3 ( V_2 , V_12 ) ;
V_4 = V_4 | V_13 ;
F_1 ( V_2 , V_12 , V_4 ) ;
}
static T_2 F_10 ( struct V_14 * V_15 ,
unsigned int V_9 ,
unsigned int V_16 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned int V_17 = 0 ;
while ( ! ( F_3 ( V_2 , V_18 ) &
V_19 ) ) {
F_6 ( V_16 ) ;
if ( V_17 ++ == V_20 )
return V_21 ;
}
V_17 = 0 ;
while ( ( F_3 ( V_2 , V_22 ) &
V_10 ) != V_9 ) {
F_6 ( V_16 ) ;
if ( V_17 ++ == V_20 )
return V_21 ;
}
return F_3 ( V_2 , V_23 ) &
V_24 ;
}
static T_3 F_12 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = V_26 ;
struct V_14 * V_15 ;
unsigned int V_29 ;
unsigned int V_9 ;
unsigned int V_30 ;
bool V_31 ;
T_2 * V_32 ;
int V_33 ;
V_15 = V_28 -> V_15 ;
V_2 = F_11 ( V_15 ) ;
V_32 = V_2 -> V_34 ;
F_13 ( & V_2 -> V_35 ) ;
F_5 ( V_2 ) ;
V_29 = V_2 -> V_36 / V_20 ;
V_33 = 0 ;
V_31 = false ;
F_14 (scan_idx, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_9 = V_15 -> V_37 [ V_30 ] . V_9 ;
F_8 ( V_2 , V_9 ) ;
V_32 [ V_33 ] = F_10 ( V_15 , V_9 , V_29 ) ;
if ( V_32 [ V_33 ] == V_21 ) {
F_15 ( & V_15 -> V_38 ,
L_1 , V_9 ) ;
V_31 = true ;
goto V_39;
}
V_33 ++ ;
}
V_39:
F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_35 ) ;
if ( ! V_31 )
F_17 ( V_15 , V_32 ,
F_18 () ) ;
F_19 ( V_15 -> V_40 ) ;
return V_41 ;
}
static T_2 F_20 ( struct V_14 * V_15 ,
struct V_42 const * V_43 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned int V_29 ;
T_2 V_4 ;
F_5 ( V_2 ) ;
V_29 = V_2 -> V_36 / V_20 ;
F_8 ( V_2 , V_43 -> V_9 ) ;
V_4 = F_10 ( V_15 , V_43 -> V_9 , V_29 ) ;
F_7 ( V_2 ) ;
return V_4 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_42 const * V_43 ,
int * V_4 , int * V_44 , long V_45 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_46 ;
switch ( V_45 ) {
case V_47 :
if ( F_22 ( V_15 ) )
return - V_48 ;
F_13 ( & V_2 -> V_35 ) ;
* V_4 = F_20 ( V_15 , V_43 ) ;
F_16 ( & V_2 -> V_35 ) ;
if ( * V_4 == V_21 )
return - V_49 ;
return V_50 ;
case V_51 :
V_46 = F_23 ( V_2 -> V_3 ) ;
if ( V_46 < 0 )
return V_46 ;
* V_4 = V_46 / 1000 ;
* V_44 = V_43 -> V_52 . V_53 ;
return V_54 ;
default:
return - V_55 ;
}
}
static int F_24 ( struct V_14 * V_15 ,
const unsigned long * V_56 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_25 ( V_2 -> V_34 ) ;
V_2 -> V_34 = F_26 ( V_15 -> V_57 , V_58 ) ;
if ( ! V_2 -> V_34 )
return - V_59 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 ,
unsigned long V_60 )
{
struct V_42 * V_61 , * V_62 ;
unsigned int V_63 , V_64 = 0 ;
V_15 -> V_65 = F_28 ( & V_60 ,
V_66 ) + 1 ;
V_61 = F_29 ( & V_15 -> V_38 , V_15 -> V_65 ,
sizeof( struct V_42 ) ,
V_58 ) ;
if ( ! V_61 )
return - V_59 ;
F_14 (bit, &channel_map, CC10001_ADC_NUM_CHANNELS) {
struct V_42 * V_43 = & V_61 [ V_64 ] ;
V_43 -> type = V_67 ;
V_43 -> V_68 = 1 ;
V_43 -> V_9 = V_63 ;
V_43 -> V_69 = V_64 ;
V_43 -> V_52 . V_70 = 'u' ;
V_43 -> V_52 . V_53 = 10 ;
V_43 -> V_52 . V_71 = 16 ;
V_43 -> V_72 = F_30 ( V_51 ) ;
V_43 -> V_73 = F_30 ( V_47 ) ;
V_64 ++ ;
}
V_62 = & V_61 [ V_64 ] ;
V_62 -> type = V_74 ;
V_62 -> V_9 = - 1 ;
V_62 -> V_69 = V_64 ;
V_62 -> V_52 . V_70 = 's' ;
V_62 -> V_52 . V_53 = 64 ;
V_62 -> V_52 . V_71 = 64 ;
V_15 -> V_37 = V_61 ;
return 0 ;
}
static int F_31 ( struct V_75 * V_76 )
{
struct V_77 * V_78 = V_76 -> V_38 . V_79 ;
struct V_1 * V_2 ;
unsigned long V_80 ;
struct V_81 * V_82 ;
struct V_14 * V_15 ;
unsigned long V_60 ;
int V_46 ;
V_15 = F_32 ( & V_76 -> V_38 , sizeof( * V_2 ) ) ;
if ( V_15 == NULL )
return - V_59 ;
V_2 = F_11 ( V_15 ) ;
V_60 = F_33 ( V_66 - 1 , 0 ) ;
if ( ! F_34 ( V_78 , L_2 , & V_46 ) )
V_60 &= ~ V_46 ;
V_2 -> V_3 = F_35 ( & V_76 -> V_38 , L_3 ) ;
if ( F_36 ( V_2 -> V_3 ) )
return F_37 ( V_2 -> V_3 ) ;
V_46 = F_38 ( V_2 -> V_3 ) ;
if ( V_46 )
return V_46 ;
V_15 -> V_38 . V_83 = & V_76 -> V_38 ;
V_15 -> V_84 = F_39 ( & V_76 -> V_38 ) ;
V_15 -> V_85 = & V_86 ;
V_15 -> V_87 = V_88 ;
V_82 = F_40 ( V_76 , V_89 , 0 ) ;
V_2 -> V_5 = F_41 ( & V_76 -> V_38 , V_82 ) ;
if ( F_36 ( V_2 -> V_5 ) ) {
V_46 = F_37 ( V_2 -> V_5 ) ;
goto V_90;
}
V_2 -> V_91 = F_42 ( & V_76 -> V_38 , L_4 ) ;
if ( F_36 ( V_2 -> V_91 ) ) {
F_43 ( & V_76 -> V_38 , L_5 ) ;
V_46 = F_37 ( V_2 -> V_91 ) ;
goto V_90;
}
V_46 = F_44 ( V_2 -> V_91 ) ;
if ( V_46 ) {
F_43 ( & V_76 -> V_38 , L_6 ) ;
goto V_90;
}
V_80 = F_45 ( V_2 -> V_91 ) ;
if ( ! V_80 ) {
V_46 = - V_55 ;
F_43 ( & V_76 -> V_38 , L_7 ) ;
goto V_92;
}
V_2 -> V_36 = V_93 / V_80 ;
V_2 -> V_7 = V_2 -> V_36 * V_94 ;
V_46 = F_27 ( V_15 , V_60 ) ;
if ( V_46 < 0 )
goto V_92;
F_46 ( & V_2 -> V_35 ) ;
V_46 = F_47 ( V_15 , NULL ,
& F_12 , NULL ) ;
if ( V_46 < 0 )
goto V_92;
V_46 = F_48 ( V_15 ) ;
if ( V_46 < 0 )
goto V_95;
F_49 ( V_76 , V_15 ) ;
return 0 ;
V_95:
F_50 ( V_15 ) ;
V_92:
F_51 ( V_2 -> V_91 ) ;
V_90:
F_52 ( V_2 -> V_3 ) ;
return V_46 ;
}
static int F_53 ( struct V_75 * V_76 )
{
struct V_14 * V_15 = F_54 ( V_76 ) ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_55 ( V_15 ) ;
F_50 ( V_15 ) ;
F_51 ( V_2 -> V_91 ) ;
F_52 ( V_2 -> V_3 ) ;
return 0 ;
}
