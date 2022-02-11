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
if ( ! V_2 -> V_36 )
F_5 ( V_2 ) ;
V_29 = V_2 -> V_37 / V_20 ;
V_33 = 0 ;
V_31 = false ;
F_14 (scan_idx, indio_dev->active_scan_mask,
indio_dev->masklength) {
V_9 = V_15 -> V_38 [ V_30 ] . V_9 ;
F_8 ( V_2 , V_9 ) ;
V_32 [ V_33 ] = F_10 ( V_15 , V_9 , V_29 ) ;
if ( V_32 [ V_33 ] == V_21 ) {
F_15 ( & V_15 -> V_39 ,
L_1 , V_9 ) ;
V_31 = true ;
goto V_40;
}
V_33 ++ ;
}
V_40:
if ( ! V_2 -> V_36 )
F_7 ( V_2 ) ;
F_16 ( & V_2 -> V_35 ) ;
if ( ! V_31 )
F_17 ( V_15 , V_32 ,
F_18 ( V_15 ) ) ;
F_19 ( V_15 -> V_41 ) ;
return V_42 ;
}
static T_2 F_20 ( struct V_14 * V_15 ,
struct V_43 const * V_44 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
unsigned int V_29 ;
T_2 V_4 ;
if ( ! V_2 -> V_36 )
F_5 ( V_2 ) ;
V_29 = V_2 -> V_37 / V_20 ;
F_8 ( V_2 , V_44 -> V_9 ) ;
V_4 = F_10 ( V_15 , V_44 -> V_9 , V_29 ) ;
if ( ! V_2 -> V_36 )
F_7 ( V_2 ) ;
return V_4 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_43 const * V_44 ,
int * V_4 , int * V_45 , long V_46 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
int V_47 ;
switch ( V_46 ) {
case V_48 :
if ( F_22 ( V_15 ) )
return - V_49 ;
F_13 ( & V_2 -> V_35 ) ;
* V_4 = F_20 ( V_15 , V_44 ) ;
F_16 ( & V_2 -> V_35 ) ;
if ( * V_4 == V_21 )
return - V_50 ;
return V_51 ;
case V_52 :
V_47 = F_23 ( V_2 -> V_3 ) ;
if ( V_47 < 0 )
return V_47 ;
* V_4 = V_47 / 1000 ;
* V_45 = V_44 -> V_53 . V_54 ;
return V_55 ;
default:
return - V_56 ;
}
}
static int F_24 ( struct V_14 * V_15 ,
const unsigned long * V_57 )
{
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_25 ( V_2 -> V_34 ) ;
V_2 -> V_34 = F_26 ( V_15 -> V_58 , V_59 ) ;
if ( ! V_2 -> V_34 )
return - V_60 ;
return 0 ;
}
static int F_27 ( struct V_14 * V_15 ,
unsigned long V_61 )
{
struct V_43 * V_62 , * V_63 ;
unsigned int V_64 , V_65 = 0 ;
V_15 -> V_66 = F_28 ( & V_61 ,
V_67 ) + 1 ;
V_62 = F_29 ( & V_15 -> V_39 , V_15 -> V_66 ,
sizeof( struct V_43 ) ,
V_59 ) ;
if ( ! V_62 )
return - V_60 ;
F_14 (bit, &channel_map, CC10001_ADC_NUM_CHANNELS) {
struct V_43 * V_44 = & V_62 [ V_65 ] ;
V_44 -> type = V_68 ;
V_44 -> V_69 = 1 ;
V_44 -> V_9 = V_64 ;
V_44 -> V_70 = V_65 ;
V_44 -> V_53 . V_71 = 'u' ;
V_44 -> V_53 . V_54 = 10 ;
V_44 -> V_53 . V_72 = 16 ;
V_44 -> V_73 = F_30 ( V_52 ) ;
V_44 -> V_74 = F_30 ( V_48 ) ;
V_65 ++ ;
}
V_63 = & V_62 [ V_65 ] ;
V_63 -> type = V_75 ;
V_63 -> V_9 = - 1 ;
V_63 -> V_70 = V_65 ;
V_63 -> V_53 . V_71 = 's' ;
V_63 -> V_53 . V_54 = 64 ;
V_63 -> V_53 . V_72 = 64 ;
V_15 -> V_38 = V_62 ;
return 0 ;
}
static int F_31 ( struct V_76 * V_77 )
{
struct V_78 * V_79 = V_77 -> V_39 . V_80 ;
struct V_1 * V_2 ;
unsigned long V_81 ;
struct V_82 * V_83 ;
struct V_14 * V_15 ;
unsigned long V_61 ;
int V_47 ;
V_15 = F_32 ( & V_77 -> V_39 , sizeof( * V_2 ) ) ;
if ( V_15 == NULL )
return - V_60 ;
V_2 = F_11 ( V_15 ) ;
V_61 = F_33 ( V_67 - 1 , 0 ) ;
if ( ! F_34 ( V_79 , L_2 , & V_47 ) ) {
V_2 -> V_36 = true ;
V_61 &= ~ V_47 ;
}
V_2 -> V_3 = F_35 ( & V_77 -> V_39 , L_3 ) ;
if ( F_36 ( V_2 -> V_3 ) )
return F_37 ( V_2 -> V_3 ) ;
V_47 = F_38 ( V_2 -> V_3 ) ;
if ( V_47 )
return V_47 ;
V_15 -> V_39 . V_84 = & V_77 -> V_39 ;
V_15 -> V_85 = F_39 ( & V_77 -> V_39 ) ;
V_15 -> V_86 = & V_87 ;
V_15 -> V_88 = V_89 ;
V_83 = F_40 ( V_77 , V_90 , 0 ) ;
V_2 -> V_5 = F_41 ( & V_77 -> V_39 , V_83 ) ;
if ( F_36 ( V_2 -> V_5 ) ) {
V_47 = F_37 ( V_2 -> V_5 ) ;
goto V_91;
}
V_2 -> V_92 = F_42 ( & V_77 -> V_39 , L_4 ) ;
if ( F_36 ( V_2 -> V_92 ) ) {
F_43 ( & V_77 -> V_39 , L_5 ) ;
V_47 = F_37 ( V_2 -> V_92 ) ;
goto V_91;
}
V_47 = F_44 ( V_2 -> V_92 ) ;
if ( V_47 ) {
F_43 ( & V_77 -> V_39 , L_6 ) ;
goto V_91;
}
V_81 = F_45 ( V_2 -> V_92 ) ;
if ( ! V_81 ) {
V_47 = - V_56 ;
F_43 ( & V_77 -> V_39 , L_7 ) ;
goto V_93;
}
V_2 -> V_37 = V_94 / V_81 ;
V_2 -> V_7 = V_2 -> V_37 * V_95 ;
if ( V_2 -> V_36 )
F_5 ( V_2 ) ;
V_47 = F_27 ( V_15 , V_61 ) ;
if ( V_47 < 0 )
goto V_93;
F_46 ( & V_2 -> V_35 ) ;
V_47 = F_47 ( V_15 , NULL ,
& F_12 , NULL ) ;
if ( V_47 < 0 )
goto V_93;
V_47 = F_48 ( V_15 ) ;
if ( V_47 < 0 )
goto V_96;
F_49 ( V_77 , V_15 ) ;
return 0 ;
V_96:
F_50 ( V_15 ) ;
V_93:
F_51 ( V_2 -> V_92 ) ;
V_91:
F_52 ( V_2 -> V_3 ) ;
return V_47 ;
}
static int F_53 ( struct V_76 * V_77 )
{
struct V_14 * V_15 = F_54 ( V_77 ) ;
struct V_1 * V_2 = F_11 ( V_15 ) ;
F_7 ( V_2 ) ;
F_55 ( V_15 ) ;
F_50 ( V_15 ) ;
F_51 ( V_2 -> V_92 ) ;
F_52 ( V_2 -> V_3 ) ;
return 0 ;
}
