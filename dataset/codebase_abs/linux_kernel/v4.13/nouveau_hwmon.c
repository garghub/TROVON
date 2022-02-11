static T_1
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return snprintf ( V_5 , V_6 , L_1 , 100 ) ;
}
static T_1
F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
return snprintf ( V_5 , V_6 , L_1 ,
V_12 -> V_14 ( V_12 , V_15 ) * 1000 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
long V_17 ;
if ( F_6 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_12 -> V_19 ( V_12 , V_15 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
return snprintf ( V_5 , V_6 , L_1 ,
V_12 -> V_14 ( V_12 , V_20 ) * 1000 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
long V_17 ;
if ( F_6 ( V_5 , 10 , & V_17 ) == - V_18 )
return V_16 ;
V_12 -> V_19 ( V_12 , V_20 ,
V_17 / 1000 ) ;
return V_16 ;
}
static T_1
F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
int V_21 ;
V_21 = V_12 -> V_14 ( V_12 , V_22 ) ;
if ( V_21 < 0 )
return V_21 ;
return sprintf ( V_5 , L_2 , V_21 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
int V_21 ;
V_21 = V_12 -> V_14 ( V_12 , V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
return sprintf ( V_5 , L_2 , V_21 ) ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
long V_17 ;
int V_21 ;
if ( F_6 ( V_5 , 10 , & V_17 ) == - V_18 )
return - V_18 ;
V_21 = V_12 -> V_19 ( V_12 , V_23 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_16 ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_16 )
{
struct V_7 * V_8 = F_3 ( V_2 ) ;
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
long V_17 ;
int V_21 ;
if ( F_6 ( V_5 , 10 , & V_17 ) == - V_18 )
return - V_18 ;
V_21 = V_12 -> V_19 ( V_12 , V_22 , V_17 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_16 ;
}
static T_3
F_13 ( const void * V_24 , T_4 V_25 , int V_26 )
{
switch ( V_25 ) {
case V_27 :
return 0444 ;
default:
return 0 ;
}
}
static T_3
F_14 ( const void * V_24 , T_4 V_25 , int V_26 )
{
struct V_9 * V_10 = V_9 ( (struct V_7 * ) V_24 ) ;
struct V_28 * V_29 = F_15 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_29 || ! V_29 -> V_30 || F_16 ( & V_29 -> V_31 ) )
return 0 ;
switch ( V_25 ) {
case V_32 :
return 0444 ;
case V_33 :
if ( V_29 -> V_34 )
return 0444 ;
return 0 ;
case V_35 :
if ( V_29 -> V_36 )
return 0444 ;
return 0 ;
default:
return 0 ;
}
}
static T_3
F_17 ( const void * V_24 , T_4 V_25 , int V_26 )
{
struct V_9 * V_10 = V_9 ( (struct V_7 * ) V_24 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( V_12 && V_12 -> V_14 && F_18 ( V_12 ) < 0 )
return 0 ;
switch ( V_25 ) {
case V_37 :
return 0444 ;
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
return 0644 ;
default:
return 0 ;
}
}
static T_3
F_19 ( const void * V_24 , T_4 V_25 , int V_26 )
{
struct V_9 * V_10 = V_9 ( (struct V_7 * ) V_24 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( V_12 && V_12 -> V_14 && V_12 -> V_44 &&
V_12 -> V_44 ( V_12 ) < 0 )
return 0 ;
switch ( V_25 ) {
case V_45 :
case V_46 :
return 0644 ;
default:
return 0 ;
}
}
static T_3
F_20 ( const void * V_24 , T_4 V_25 , int V_26 )
{
struct V_9 * V_10 = V_9 ( (struct V_7 * ) V_24 ) ;
struct V_47 * V_48 = F_21 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_48 || F_22 ( V_48 ) < 0 )
return 0 ;
switch ( V_25 ) {
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return 0444 ;
default:
return 0 ;
}
}
static T_3
F_23 ( const void * V_24 , T_4 V_25 , int V_26 )
{
struct V_9 * V_10 = V_9 ( (struct V_7 * ) V_24 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_12 || ! V_12 -> V_14 || F_24 ( V_12 ) < 0 )
return 0 ;
switch ( V_25 ) {
case V_53 :
return 0444 ;
default:
return 0 ;
}
}
static int
F_25 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
switch ( V_25 ) {
case V_27 :
* V_54 = 1000 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
int V_21 ;
if ( ! V_12 || ! V_12 -> V_14 )
return - V_55 ;
switch ( V_25 ) {
case V_37 :
V_21 = F_18 ( V_12 ) ;
* V_54 = V_21 < 0 ? V_21 : ( V_21 * 1000 ) ;
break;
case V_38 :
* V_54 = V_12 -> V_14 ( V_12 , V_57 )
* 1000 ;
break;
case V_39 :
* V_54 = V_12 -> V_14 ( V_12 , V_58 )
* 1000 ;
break;
case V_40 :
* V_54 = V_12 -> V_14 ( V_12 , V_59 )
* 1000 ;
break;
case V_41 :
* V_54 = V_12 -> V_14 ( V_12 , V_60 )
* 1000 ;
break;
case V_42 :
* V_54 = V_12 -> V_14 ( V_12 , V_61 )
* 1000 ;
break;
case V_43 :
* V_54 = V_12 -> V_14 ( V_12 , V_62 )
* 1000 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_27 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_12 )
return - V_55 ;
switch ( V_25 ) {
case V_53 :
* V_54 = F_24 ( V_12 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_28 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_47 * V_48 = F_21 ( & V_10 -> V_13 . V_1 ) ;
int V_21 ;
if ( ! V_48 )
return - V_55 ;
switch ( V_25 ) {
case V_49 :
V_21 = F_22 ( V_48 ) ;
* V_54 = V_21 < 0 ? V_21 : ( V_21 / 1000 ) ;
break;
case V_51 :
* V_54 = V_48 -> V_63 > 0 ? ( V_48 -> V_63 / 1000 ) : - V_64 ;
break;
case V_52 :
* V_54 = V_48 -> V_65 > 0 ? ( V_48 -> V_65 / 1000 ) : - V_64 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_12 || ! V_12 -> V_14 || ! V_12 -> V_44 )
return - V_55 ;
switch ( V_25 ) {
case V_45 :
* V_54 = V_12 -> V_14 ( V_12 , V_66 ) ;
break;
case V_46 :
* V_54 = V_12 -> V_44 ( V_12 ) ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long * V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_28 * V_29 = F_15 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_29 )
return - V_55 ;
switch ( V_25 ) {
case V_32 :
* V_54 = F_31 ( V_29 ) ;
break;
case V_33 :
* V_54 = V_29 -> V_34 ;
break;
case V_35 :
* V_54 = V_29 -> V_36 ;
break;
default:
return - V_55 ;
}
return 0 ;
}
static int
F_32 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_12 || ! V_12 -> V_19 )
return - V_55 ;
switch ( V_25 ) {
case V_38 :
return V_12 -> V_19 ( V_12 , V_57 ,
V_54 / 1000 ) ;
case V_39 :
return V_12 -> V_19 ( V_12 , V_58 ,
V_54 / 1000 ) ;
case V_40 :
return V_12 -> V_19 ( V_12 , V_59 ,
V_54 / 1000 ) ;
case V_41 :
return V_12 -> V_19 ( V_12 , V_60 ,
V_54 / 1000 ) ;
case V_42 :
return V_12 -> V_19 ( V_12 , V_61 ,
V_54 / 1000 ) ;
case V_43 :
return V_12 -> V_19 ( V_12 , V_62 ,
V_54 / 1000 ) ;
default:
return - V_55 ;
}
}
static int
F_33 ( struct V_1 * V_8 , T_4 V_25 , int V_26 , long V_54 )
{
struct V_7 * V_56 = F_3 ( V_8 ) ;
struct V_9 * V_10 = V_9 ( V_56 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
if ( ! V_12 || ! V_12 -> V_19 )
return - V_55 ;
switch ( V_25 ) {
case V_46 :
return V_12 -> V_67 ( V_12 , V_54 ) ;
case V_45 :
return V_12 -> V_19 ( V_12 , V_66 , V_54 ) ;
default:
return - V_55 ;
}
}
static T_3
F_34 ( const void * V_24 , enum V_68 type , T_4 V_25 ,
int V_26 )
{
switch ( type ) {
case V_69 :
return F_13 ( V_24 , V_25 , V_26 ) ;
case V_70 :
return F_17 ( V_24 , V_25 , V_26 ) ;
case V_71 :
return F_23 ( V_24 , V_25 , V_26 ) ;
case V_72 :
return F_20 ( V_24 , V_25 , V_26 ) ;
case V_73 :
return F_19 ( V_24 , V_25 , V_26 ) ;
case V_74 :
return F_14 ( V_24 , V_25 , V_26 ) ;
default:
return 0 ;
}
}
static int
F_35 ( struct V_1 * V_8 , enum V_68 type , T_4 V_25 ,
int V_26 , const char * * V_5 )
{
if ( type == V_72 && V_25 == V_50 ) {
* V_5 = V_75 ;
return 0 ;
}
return - V_55 ;
}
static int
F_36 ( struct V_1 * V_8 , enum V_68 type , T_4 V_25 ,
int V_26 , long * V_54 )
{
switch ( type ) {
case V_69 :
return F_25 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_70 :
return F_26 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_71 :
return F_27 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_72 :
return F_28 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_73 :
return F_29 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_74 :
return F_30 ( V_8 , V_25 , V_26 , V_54 ) ;
default:
return - V_55 ;
}
}
static int
F_37 ( struct V_1 * V_8 , enum V_68 type , T_4 V_25 ,
int V_26 , long V_54 )
{
switch ( type ) {
case V_70 :
return F_32 ( V_8 , V_25 , V_26 , V_54 ) ;
case V_73 :
return F_33 ( V_8 , V_25 , V_26 , V_54 ) ;
default:
return - V_55 ;
}
}
int
F_38 ( struct V_7 * V_8 )
{
#if F_39 ( V_76 ) || ( F_39 ( V_77 ) && F_39 ( V_78 ) )
struct V_9 * V_10 = V_9 ( V_8 ) ;
struct V_11 * V_12 = F_4 ( & V_10 -> V_13 . V_1 ) ;
const struct V_79 * V_80 [ V_81 ] ;
struct V_82 * V_83 ;
struct V_1 * V_84 ;
int V_21 = 0 ;
int V_85 = 0 ;
V_83 = V_10 -> V_83 = F_40 ( sizeof( * V_83 ) , V_86 ) ;
if ( ! V_83 )
return - V_87 ;
V_83 -> V_8 = V_8 ;
if ( V_12 && V_12 -> V_14 && V_12 -> V_19 ) {
if ( F_18 ( V_12 ) >= 0 )
V_80 [ V_85 ++ ] = & V_88 ;
if ( V_12 -> V_44 && V_12 -> V_44 ( V_12 ) >= 0 )
V_80 [ V_85 ++ ] = & V_89 ;
}
V_80 [ V_85 ] = 0 ;
V_84 = F_41 ( V_8 -> V_8 , L_3 , V_8 ,
& V_90 ,
V_80 ) ;
if ( F_42 ( V_84 ) ) {
V_21 = F_43 ( V_84 ) ;
F_44 ( V_10 , L_4 , V_21 ) ;
return V_21 ;
}
V_83 -> V_83 = V_84 ;
return 0 ;
#else
return 0 ;
#endif
}
void
F_45 ( struct V_7 * V_8 )
{
#if F_39 ( V_76 ) || ( F_39 ( V_77 ) && F_39 ( V_78 ) )
struct V_82 * V_83 = V_82 ( V_8 ) ;
if ( V_83 -> V_83 )
F_46 ( V_83 -> V_83 ) ;
V_9 ( V_8 ) -> V_83 = NULL ;
F_47 ( V_83 ) ;
#endif
}
