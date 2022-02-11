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
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
T_1 V_4 ;
V_4 = ( V_6 & V_7 ) | V_8 ;
F_1 ( V_2 , V_9 , V_4 ) ;
V_4 = F_3 ( V_2 , V_9 ) ;
V_4 = V_4 | V_10 ;
F_1 ( V_2 , V_9 , V_4 ) ;
}
static T_2 F_6 ( struct V_11 * V_12 ,
unsigned int V_6 ,
unsigned int V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned int V_14 = 0 ;
while ( ! ( F_3 ( V_2 , V_15 ) &
V_16 ) ) {
F_8 ( V_13 ) ;
if ( V_14 ++ == V_17 )
return V_18 ;
}
V_14 = 0 ;
while ( ( F_3 ( V_2 , V_19 ) &
V_7 ) != V_6 ) {
F_8 ( V_13 ) ;
if ( V_14 ++ == V_17 )
return V_18 ;
}
return F_3 ( V_2 , V_20 ) &
V_21 ;
}
static T_3 F_9 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 ;
struct V_24 * V_25 = V_23 ;
struct V_11 * V_12 ;
unsigned int V_26 ;
unsigned int V_6 ;
bool V_27 ;
T_2 * V_28 ;
int V_29 ;
V_12 = V_25 -> V_12 ;
V_2 = F_7 ( V_12 ) ;
V_28 = V_2 -> V_30 ;
F_10 ( & V_2 -> V_31 ) ;
F_1 ( V_2 , V_32 ,
V_33 ) ;
F_8 ( V_2 -> V_34 ) ;
V_26 = V_2 -> V_35 / V_17 ;
V_29 = 0 ;
V_27 = false ;
F_11 (channel, indio_dev->active_scan_mask,
indio_dev->masklength) {
F_5 ( V_2 , V_6 ) ;
V_28 [ V_29 ] = F_6 ( V_12 , V_6 , V_26 ) ;
if ( V_28 [ V_29 ] == V_18 ) {
F_12 ( & V_12 -> V_36 ,
L_1 , V_6 ) ;
V_27 = true ;
goto V_37;
}
V_29 ++ ;
}
V_37:
F_1 ( V_2 , V_32 , 0 ) ;
F_13 ( & V_2 -> V_31 ) ;
if ( ! V_27 )
F_14 ( V_12 , V_28 ,
F_15 () ) ;
F_16 ( V_12 -> V_38 ) ;
return V_39 ;
}
static T_2 F_17 ( struct V_11 * V_12 ,
struct V_40 const * V_41 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned int V_26 ;
T_2 V_4 ;
F_1 ( V_2 , V_32 ,
V_33 ) ;
F_8 ( V_2 -> V_34 ) ;
V_26 = V_2 -> V_35 / V_17 ;
F_5 ( V_2 , V_41 -> V_6 ) ;
V_4 = F_6 ( V_12 , V_41 -> V_6 , V_26 ) ;
F_1 ( V_2 , V_32 , 0 ) ;
return V_4 ;
}
static int F_18 ( struct V_11 * V_12 ,
struct V_40 const * V_41 ,
int * V_4 , int * V_42 , long V_43 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
int V_44 ;
switch ( V_43 ) {
case V_45 :
if ( F_19 ( V_12 ) )
return - V_46 ;
F_10 ( & V_2 -> V_31 ) ;
* V_4 = F_17 ( V_12 , V_41 ) ;
F_13 ( & V_2 -> V_31 ) ;
if ( * V_4 == V_18 )
return - V_47 ;
return V_48 ;
case V_49 :
V_44 = F_20 ( V_2 -> V_3 ) ;
if ( V_44 )
return V_44 ;
* V_4 = V_44 / 1000 ;
* V_42 = V_41 -> V_50 . V_51 ;
return V_52 ;
default:
return - V_53 ;
}
}
static int F_21 ( struct V_11 * V_12 ,
const unsigned long * V_54 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
F_22 ( V_2 -> V_30 ) ;
V_2 -> V_30 = F_23 ( V_12 -> V_55 , V_56 ) ;
if ( ! V_2 -> V_30 )
return - V_57 ;
return 0 ;
}
static int F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_40 * V_58 , * V_59 ;
unsigned int V_60 , V_61 = 0 ;
V_12 -> V_62 = F_25 ( & V_2 -> V_63 ,
V_64 ) ;
V_58 = F_26 ( & V_12 -> V_36 , V_12 -> V_62 + 1 ,
sizeof( struct V_40 ) ,
V_56 ) ;
if ( ! V_58 )
return - V_57 ;
F_11 (bit, &adc_dev->channel_map, CC10001_ADC_NUM_CHANNELS) {
struct V_40 * V_41 = & V_58 [ V_61 ] ;
V_41 -> type = V_65 ;
V_41 -> V_66 = 1 ;
V_41 -> V_6 = V_60 ;
V_41 -> V_67 = V_61 ;
V_41 -> V_50 . V_68 = 'u' ;
V_41 -> V_50 . V_51 = 10 ;
V_41 -> V_50 . V_69 = 16 ;
V_41 -> V_70 = F_27 ( V_49 ) ;
V_41 -> V_71 = F_27 ( V_45 ) ;
V_61 ++ ;
}
V_59 = & V_58 [ V_61 ] ;
V_59 -> type = V_72 ;
V_59 -> V_6 = - 1 ;
V_59 -> V_67 = V_61 ;
V_59 -> V_50 . V_68 = 's' ;
V_59 -> V_50 . V_51 = 64 ;
V_59 -> V_50 . V_69 = 64 ;
V_12 -> V_73 = V_58 ;
return 0 ;
}
static int F_28 ( struct V_74 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_36 . V_78 ;
struct V_1 * V_2 ;
unsigned long V_79 ;
struct V_80 * V_81 ;
struct V_11 * V_12 ;
int V_44 ;
V_12 = F_29 ( & V_75 -> V_36 , sizeof( * V_2 ) ) ;
if ( V_12 == NULL )
return - V_57 ;
V_2 = F_7 ( V_12 ) ;
V_2 -> V_63 = F_30 ( V_64 - 1 , 0 ) ;
if ( ! F_31 ( V_77 , L_2 , & V_44 ) )
V_2 -> V_63 &= ~ V_44 ;
V_2 -> V_3 = F_32 ( & V_75 -> V_36 , L_3 ) ;
if ( F_33 ( V_2 -> V_3 ) )
return F_34 ( V_2 -> V_3 ) ;
V_44 = F_35 ( V_2 -> V_3 ) ;
if ( V_44 )
return V_44 ;
V_12 -> V_36 . V_82 = & V_75 -> V_36 ;
V_12 -> V_83 = F_36 ( & V_75 -> V_36 ) ;
V_12 -> V_84 = & V_85 ;
V_12 -> V_86 = V_87 ;
V_81 = F_37 ( V_75 , V_88 , 0 ) ;
V_2 -> V_5 = F_38 ( & V_75 -> V_36 , V_81 ) ;
if ( F_33 ( V_2 -> V_5 ) ) {
V_44 = F_34 ( V_2 -> V_5 ) ;
goto V_89;
}
V_2 -> V_90 = F_39 ( & V_75 -> V_36 , L_4 ) ;
if ( F_33 ( V_2 -> V_90 ) ) {
F_40 ( & V_75 -> V_36 , L_5 ) ;
V_44 = F_34 ( V_2 -> V_90 ) ;
goto V_89;
}
V_44 = F_41 ( V_2 -> V_90 ) ;
if ( V_44 ) {
F_40 ( & V_75 -> V_36 , L_6 ) ;
goto V_89;
}
V_79 = F_42 ( V_2 -> V_90 ) ;
if ( ! V_79 ) {
V_44 = - V_53 ;
F_40 ( & V_75 -> V_36 , L_7 ) ;
goto V_91;
}
V_2 -> V_35 = V_92 / V_79 ;
V_2 -> V_34 = V_2 -> V_35 * V_93 ;
V_44 = F_24 ( V_12 ) ;
if ( V_44 < 0 )
goto V_91;
F_43 ( & V_2 -> V_31 ) ;
V_44 = F_44 ( V_12 , NULL ,
& F_9 , NULL ) ;
if ( V_44 < 0 )
goto V_91;
V_44 = F_45 ( V_12 ) ;
if ( V_44 < 0 )
goto V_94;
F_46 ( V_75 , V_12 ) ;
return 0 ;
V_94:
F_47 ( V_12 ) ;
V_91:
F_48 ( V_2 -> V_90 ) ;
V_89:
F_49 ( V_2 -> V_3 ) ;
return V_44 ;
}
static int F_50 ( struct V_74 * V_75 )
{
struct V_11 * V_12 = F_51 ( V_75 ) ;
struct V_1 * V_2 = F_7 ( V_12 ) ;
F_52 ( V_12 ) ;
F_47 ( V_12 ) ;
F_48 ( V_2 -> V_90 ) ;
F_49 ( V_2 -> V_3 ) ;
return 0 ;
}
