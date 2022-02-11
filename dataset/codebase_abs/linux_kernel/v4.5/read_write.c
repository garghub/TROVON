static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
T_1 F_2 ( struct V_1 * V_1 , T_1 V_4 , T_1 V_5 )
{
if ( V_4 < 0 && ! F_1 ( V_1 ) )
return - V_6 ;
if ( V_4 > V_5 )
return - V_6 ;
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
return V_4 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_4 , int V_9 ,
T_1 V_5 , T_1 V_10 )
{
switch ( V_9 ) {
case V_11 :
V_4 += V_10 ;
break;
case V_12 :
if ( V_4 == 0 )
return V_1 -> V_7 ;
F_4 ( & V_1 -> V_13 ) ;
V_4 = F_2 ( V_1 , V_1 -> V_7 + V_4 , V_5 ) ;
F_5 ( & V_1 -> V_13 ) ;
return V_4 ;
case V_14 :
if ( V_4 >= V_10 )
return - V_15 ;
break;
case V_16 :
if ( V_4 >= V_10 )
return - V_15 ;
V_4 = V_10 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = V_1 -> V_18 -> V_19 ;
return F_3 ( V_1 , V_4 , V_9 ,
V_17 -> V_20 -> V_21 ,
F_7 ( V_17 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_4 , int V_9 , T_1 V_22 )
{
switch ( V_9 ) {
case V_23 : case V_12 : case V_11 :
return F_3 ( V_1 , V_4 , V_9 ,
V_22 , V_22 ) ;
default:
return - V_6 ;
}
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
switch ( V_9 ) {
case V_23 : case V_12 :
return F_3 ( V_1 , V_4 , V_9 ,
V_24 , 0 ) ;
default:
return - V_6 ;
}
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_9 , T_1 V_22 )
{
switch ( V_9 ) {
case V_23 : case V_12 :
return F_3 ( V_1 , V_4 , V_9 ,
V_22 , 0 ) ;
default:
return - V_6 ;
}
}
T_1 F_11 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return V_1 -> V_7 ;
}
T_1 F_12 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return - V_25 ;
}
T_1 F_13 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
T_1 V_26 ;
F_15 ( V_17 ) ;
switch ( V_9 ) {
case V_11 :
V_4 += F_7 ( V_17 ) ;
break;
case V_12 :
if ( V_4 == 0 ) {
V_26 = V_1 -> V_7 ;
goto V_27;
}
V_4 += V_1 -> V_7 ;
break;
case V_14 :
if ( V_4 >= V_17 -> V_28 ) {
V_26 = - V_15 ;
goto V_27;
}
break;
case V_16 :
if ( V_4 >= V_17 -> V_28 ) {
V_26 = - V_15 ;
goto V_27;
}
V_4 = V_17 -> V_28 ;
break;
}
V_26 = - V_6 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
V_26 = V_4 ;
}
V_27:
F_16 ( V_17 ) ;
return V_26 ;
}
T_1 F_17 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
T_1 (* F_18)( struct V_1 * , T_1 , int );
F_18 = F_12 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 -> V_31 )
F_18 = V_1 -> V_30 -> V_31 ;
}
return F_18 ( V_1 , V_4 , V_9 ) ;
}
static inline struct V_32 F_19 ( int V_32 )
{
return F_20 ( F_21 ( V_32 ) ) ;
}
static inline void F_22 ( struct V_32 V_33 )
{
if ( V_33 . V_34 & V_35 )
F_23 ( & V_33 . V_1 -> V_36 ) ;
F_24 ( V_33 ) ;
}
T_2 F_25 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_42 )
return - V_6 ;
F_26 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_44 ;
V_41 = V_1 -> V_30 -> V_42 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_28 ( struct V_1 * V_1 , struct V_37 * V_38 , T_1 * V_39 )
{
struct V_40 V_40 ;
T_2 V_41 ;
if ( ! V_1 -> V_30 -> V_46 )
return - V_6 ;
F_26 ( & V_40 , V_1 ) ;
V_40 . V_43 = * V_39 ;
V_38 -> type |= V_47 ;
V_41 = V_1 -> V_30 -> V_46 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
int F_29 ( int V_48 , struct V_1 * V_1 , const T_1 * V_39 , T_3 V_49 )
{
struct V_17 * V_17 ;
T_1 V_50 ;
int V_26 = - V_6 ;
V_17 = F_14 ( V_1 ) ;
if ( F_30 ( ( T_2 ) V_49 < 0 ) )
return V_26 ;
V_50 = * V_39 ;
if ( F_30 ( V_50 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
if ( V_49 >= - V_50 )
return - V_51 ;
} else if ( F_30 ( ( T_1 ) ( V_50 + V_49 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_26 ;
}
if ( F_30 ( V_17 -> V_52 && F_31 ( V_17 ) ) ) {
V_26 = F_32 ( V_17 , V_1 , V_50 , V_50 + V_49 - 1 ,
V_48 == V_44 ? V_53 : V_54 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_26 = F_33 ( V_1 ,
V_48 == V_44 ? V_55 : V_56 ) ;
if ( V_26 )
return V_26 ;
return V_49 > V_57 ? V_57 : V_49 ;
}
static T_2 F_34 ( struct V_1 * V_58 , char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_26 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_35 ( & V_38 , V_44 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_42 ( & V_40 , & V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_36 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_65 )
return V_1 -> V_30 -> V_65 ( V_1 , V_59 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_42 )
return F_34 ( V_1 , V_59 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_37 ( struct V_1 * V_1 , char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
if ( F_30 ( ! F_38 ( V_69 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_29 ( V_44 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
V_41 = F_36 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_39 ( V_1 ) ;
F_40 ( V_71 , V_41 ) ;
}
F_41 ( V_71 ) ;
}
return V_41 ;
}
static T_2 F_42 ( struct V_1 * V_58 , const char T_4 * V_59 , T_3 V_60 , T_1 * V_39 )
{
struct V_61 V_62 = { . V_63 = ( void T_4 * ) V_59 , . V_64 = V_60 } ;
struct V_40 V_40 ;
struct V_37 V_38 ;
T_2 V_41 ;
F_26 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
F_35 ( & V_38 , V_47 , & V_62 , 1 , V_60 ) ;
V_41 = V_58 -> V_30 -> V_46 ( & V_40 , & V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
if ( V_41 > 0 )
* V_39 = V_40 . V_43 ;
return V_41 ;
}
T_2 F_43 ( struct V_1 * V_1 , const char T_4 * V_72 , T_3 V_49 ,
T_1 * V_50 )
{
if ( V_1 -> V_30 -> V_73 )
return V_1 -> V_30 -> V_73 ( V_1 , V_72 , V_49 , V_50 ) ;
else if ( V_1 -> V_30 -> V_46 )
return F_42 ( V_1 , V_72 , V_49 , V_50 ) ;
else
return - V_6 ;
}
T_2 F_44 ( struct V_1 * V_1 , const char * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_5 V_74 ;
const char T_4 * V_72 ;
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
V_74 = F_45 () ;
F_46 ( F_47 () ) ;
V_72 = ( V_76 const char T_4 * ) V_59 ;
if ( V_49 > V_57 )
V_49 = V_57 ;
V_41 = F_43 ( V_1 , V_72 , V_49 , V_50 ) ;
F_46 ( V_74 ) ;
if ( V_41 > 0 ) {
F_48 ( V_1 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_50 ( V_71 ) ;
return V_41 ;
}
T_2 F_51 ( struct V_1 * V_1 , const char T_4 * V_59 , T_3 V_49 , T_1 * V_50 )
{
T_2 V_41 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
if ( F_30 ( ! F_38 ( V_78 , V_59 , V_49 ) ) )
return - V_70 ;
V_41 = F_29 ( V_47 , V_1 , V_50 , V_49 ) ;
if ( V_41 >= 0 ) {
V_49 = V_41 ;
F_52 ( V_1 ) ;
V_41 = F_43 ( V_1 , V_59 , V_49 , V_50 ) ;
if ( V_41 > 0 ) {
F_48 ( V_1 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_50 ( V_71 ) ;
F_53 ( V_1 ) ;
}
return V_41 ;
}
static inline T_1 F_54 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_55 ( struct V_1 * V_1 , T_1 V_50 )
{
V_1 -> V_7 = V_50 ;
}
unsigned long F_56 ( struct V_61 * V_62 , unsigned long V_79 , T_3 V_80 )
{
unsigned long V_81 = 0 ;
T_3 V_60 = 0 ;
while ( V_81 < V_79 ) {
V_81 ++ ;
if ( V_60 + V_62 -> V_64 >= V_80 ) {
V_62 -> V_64 = V_80 - V_60 ;
break;
}
V_60 += V_62 -> V_64 ;
V_62 ++ ;
}
return V_81 ;
}
static T_2 F_57 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_6 F_18 )
{
struct V_40 V_40 ;
T_2 V_41 ;
F_26 ( & V_40 , V_58 ) ;
V_40 . V_43 = * V_39 ;
V_41 = F_18 ( & V_40 , V_38 ) ;
F_27 ( V_41 == - V_45 ) ;
* V_39 = V_40 . V_43 ;
return V_41 ;
}
static T_2 F_58 ( struct V_1 * V_58 , struct V_37 * V_38 ,
T_1 * V_39 , T_7 F_18 )
{
T_2 V_41 = 0 ;
while ( F_59 ( V_38 ) ) {
struct V_61 V_61 = F_60 ( V_38 ) ;
T_2 V_82 ;
V_82 = F_18 ( V_58 , V_61 . V_63 , V_61 . V_64 , V_39 ) ;
if ( V_82 < 0 ) {
if ( ! V_41 )
V_41 = V_82 ;
break;
}
V_41 += V_82 ;
if ( V_82 != V_61 . V_64 )
break;
F_61 ( V_38 , V_82 ) ;
}
return V_41 ;
}
T_2 F_62 ( int type , const struct V_61 T_4 * V_83 ,
unsigned long V_79 , unsigned long V_84 ,
struct V_61 * V_85 ,
struct V_61 * * V_86 )
{
unsigned long V_81 ;
T_2 V_41 ;
struct V_61 * V_62 = V_85 ;
if ( V_79 == 0 ) {
V_41 = 0 ;
goto V_27;
}
if ( V_79 > V_87 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( V_79 > V_84 ) {
V_62 = F_63 ( V_79 * sizeof( struct V_61 ) , V_88 ) ;
if ( V_62 == NULL ) {
V_41 = - V_89 ;
goto V_27;
}
}
if ( F_64 ( V_62 , V_83 , V_79 * sizeof( * V_83 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
V_41 = 0 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
void T_4 * V_59 = V_62 [ V_81 ] . V_63 ;
T_2 V_60 = ( T_2 ) V_62 [ V_81 ] . V_64 ;
if ( V_60 < 0 ) {
V_41 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_30 ( ! F_38 ( F_65 ( type ) , V_59 , V_60 ) ) ) {
V_41 = - V_70 ;
goto V_27;
}
if ( V_60 > V_57 - V_41 ) {
V_60 = V_57 - V_41 ;
V_62 [ V_81 ] . V_64 = V_60 ;
}
V_41 += V_60 ;
}
V_27:
* V_86 = V_62 ;
return V_41 ;
}
static T_2 F_66 ( int type , struct V_1 * V_1 ,
const struct V_61 T_4 * V_83 ,
unsigned long V_79 , T_1 * V_50 )
{
T_3 V_90 ;
struct V_61 V_91 [ V_92 ] ;
struct V_61 * V_62 = V_91 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_18 ;
T_6 V_93 ;
V_41 = F_67 ( type , V_83 , V_79 ,
F_68 ( V_91 ) , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_90 = F_59 ( & V_38 ) ;
if ( ! V_90 )
goto V_27;
V_41 = F_29 ( type , V_1 , V_50 , V_90 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_18 = V_1 -> V_30 -> V_65 ;
V_93 = V_1 -> V_30 -> V_42 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_93 = V_1 -> V_30 -> V_46 ;
F_52 ( V_1 ) ;
}
if ( V_93 )
V_41 = F_57 ( V_1 , & V_38 , V_50 , V_93 ) ;
else
V_41 = F_58 ( V_1 , & V_38 , V_50 , F_18 ) ;
if ( type != V_44 )
F_53 ( V_1 ) ;
V_27:
F_69 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_39 ( V_1 ) ;
else
F_48 ( V_1 ) ;
}
return V_41 ;
}
T_2 F_70 ( struct V_1 * V_1 , const struct V_61 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_6 ;
return F_66 ( V_44 , V_1 , V_94 , V_95 , V_50 ) ;
}
T_2 F_71 ( struct V_1 * V_1 , const struct V_61 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
if ( ! ( V_1 -> V_2 & V_77 ) )
return - V_67 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
return - V_6 ;
return F_66 ( V_47 , V_1 , V_94 , V_95 , V_50 ) ;
}
static inline T_1 F_72 ( unsigned long V_96 , unsigned long V_97 )
{
#define F_73 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_96 << F_73 ) << F_73 ) | V_97 ;
}
static T_2 F_74 ( int type , struct V_1 * V_1 ,
const struct V_98 T_4 * V_83 ,
unsigned long V_79 , T_1 * V_50 )
{
T_8 V_90 ;
struct V_61 V_91 [ V_92 ] ;
struct V_61 * V_62 = V_91 ;
struct V_37 V_38 ;
T_2 V_41 ;
T_7 F_18 ;
T_6 V_93 ;
V_41 = F_75 ( type , V_83 , V_79 ,
V_92 , & V_62 , & V_38 ) ;
if ( V_41 < 0 )
return V_41 ;
V_90 = F_59 ( & V_38 ) ;
if ( ! V_90 )
goto V_27;
V_41 = F_29 ( type , V_1 , V_50 , V_90 ) ;
if ( V_41 < 0 )
goto V_27;
if ( type == V_44 ) {
F_18 = V_1 -> V_30 -> V_65 ;
V_93 = V_1 -> V_30 -> V_42 ;
} else {
F_18 = ( T_7 ) V_1 -> V_30 -> V_73 ;
V_93 = V_1 -> V_30 -> V_46 ;
F_52 ( V_1 ) ;
}
if ( V_93 )
V_41 = F_57 ( V_1 , & V_38 , V_50 , V_93 ) ;
else
V_41 = F_58 ( V_1 , & V_38 , V_50 , F_18 ) ;
if ( type != V_44 )
F_53 ( V_1 ) ;
V_27:
F_69 ( V_62 ) ;
if ( ( V_41 + ( type == V_44 ) ) > 0 ) {
if ( type == V_44 )
F_39 ( V_1 ) ;
else
F_48 ( V_1 ) ;
}
return V_41 ;
}
static T_3 F_76 ( struct V_1 * V_1 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
goto V_27;
V_41 = F_74 ( V_44 , V_1 , V_94 , V_95 , V_50 ) ;
V_27:
if ( V_41 > 0 )
F_40 ( V_71 , V_41 ) ;
F_41 ( V_71 ) ;
return V_41 ;
}
static long F_77 ( unsigned long V_32 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 V_50 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_78 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_99 )
V_41 = F_76 ( V_33 . V_1 , V_94 , V_95 , & V_50 ) ;
F_24 ( V_33 ) ;
return V_41 ;
}
static T_3 F_79 ( struct V_1 * V_1 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 * V_50 )
{
T_2 V_41 = - V_67 ;
if ( ! ( V_1 -> V_2 & V_77 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! ( V_1 -> V_2 & V_75 ) )
goto V_27;
V_41 = F_74 ( V_47 , V_1 , V_94 , V_95 , V_50 ) ;
V_27:
if ( V_41 > 0 )
F_49 ( V_71 , V_41 ) ;
F_50 ( V_71 ) ;
return V_41 ;
}
static long F_80 ( unsigned long V_32 ,
const struct V_98 T_4 * V_94 ,
unsigned long V_95 , T_1 V_50 )
{
struct V_32 V_33 ;
T_2 V_41 ;
if ( V_50 < 0 )
return - V_6 ;
V_33 = F_78 ( V_32 ) ;
if ( ! V_33 . V_1 )
return - V_67 ;
V_41 = - V_25 ;
if ( V_33 . V_1 -> V_2 & V_100 )
V_41 = F_79 ( V_33 . V_1 , V_94 , V_95 , & V_50 ) ;
F_24 ( V_33 ) ;
return V_41 ;
}
static T_2 F_81 ( int V_101 , int V_102 , T_1 * V_39 ,
T_3 V_49 , T_1 V_103 )
{
struct V_32 V_104 , V_27 ;
struct V_17 * V_105 , * V_106 ;
T_1 V_50 ;
T_1 V_107 ;
T_2 V_26 ;
int V_108 ;
V_26 = - V_67 ;
V_104 = F_78 ( V_102 ) ;
if ( ! V_104 . V_1 )
goto V_27;
if ( ! ( V_104 . V_1 -> V_2 & V_66 ) )
goto V_109;
V_26 = - V_25 ;
if ( ! V_39 ) {
V_50 = V_104 . V_1 -> V_7 ;
} else {
V_50 = * V_39 ;
if ( ! ( V_104 . V_1 -> V_2 & V_99 ) )
goto V_109;
}
V_26 = F_29 ( V_44 , V_104 . V_1 , & V_50 , V_49 ) ;
if ( V_26 < 0 )
goto V_109;
V_49 = V_26 ;
V_26 = - V_67 ;
V_27 = F_78 ( V_101 ) ;
if ( ! V_27 . V_1 )
goto V_109;
if ( ! ( V_27 . V_1 -> V_2 & V_77 ) )
goto V_110;
V_26 = - V_6 ;
V_105 = F_14 ( V_104 . V_1 ) ;
V_106 = F_14 ( V_27 . V_1 ) ;
V_107 = V_27 . V_1 -> V_7 ;
V_26 = F_29 ( V_47 , V_27 . V_1 , & V_107 , V_49 ) ;
if ( V_26 < 0 )
goto V_110;
V_49 = V_26 ;
if ( ! V_103 )
V_103 = F_82 ( V_105 -> V_20 -> V_21 , V_106 -> V_20 -> V_21 ) ;
if ( F_30 ( V_50 + V_49 > V_103 ) ) {
V_26 = - V_51 ;
if ( V_50 >= V_103 )
goto V_110;
V_49 = V_103 - V_50 ;
}
V_108 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_52 ( V_27 . V_1 ) ;
V_26 = F_83 ( V_104 . V_1 , & V_50 , V_27 . V_1 , & V_107 , V_49 , V_108 ) ;
F_53 ( V_27 . V_1 ) ;
if ( V_26 > 0 ) {
F_40 ( V_71 , V_26 ) ;
F_49 ( V_71 , V_26 ) ;
F_39 ( V_104 . V_1 ) ;
F_48 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_107 ;
if ( V_39 )
* V_39 = V_50 ;
else
V_104 . V_1 -> V_7 = V_50 ;
}
F_41 ( V_71 ) ;
F_50 ( V_71 ) ;
if ( V_50 > V_103 )
V_26 = - V_51 ;
V_110:
F_24 ( V_27 ) ;
V_109:
F_24 ( V_104 ) ;
V_27:
return V_26 ;
}
T_2 F_84 ( struct V_1 * V_111 , T_1 V_112 ,
struct V_1 * V_113 , T_1 V_114 ,
T_3 V_60 , unsigned int V_34 )
{
struct V_17 * V_115 = F_14 ( V_111 ) ;
struct V_17 * V_116 = F_14 ( V_113 ) ;
T_2 V_41 ;
if ( V_34 != 0 )
return - V_6 ;
V_41 = F_29 ( V_44 , V_111 , & V_112 , V_60 ) ;
if ( V_41 >= 0 )
V_41 = F_29 ( V_47 , V_113 , & V_114 , V_60 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( ! ( V_111 -> V_2 & V_66 ) ||
! ( V_113 -> V_2 & V_77 ) ||
( V_113 -> V_117 & V_118 ) )
return - V_67 ;
if ( V_115 -> V_20 != V_116 -> V_20 )
return - V_119 ;
if ( V_60 == 0 )
return 0 ;
V_41 = F_85 ( V_113 ) ;
if ( V_41 )
return V_41 ;
V_41 = - V_120 ;
if ( V_113 -> V_30 -> V_121 )
V_41 = V_113 -> V_30 -> V_121 ( V_111 , V_112 , V_113 ,
V_114 , V_60 , V_34 ) ;
if ( V_41 == - V_120 )
V_41 = F_83 ( V_111 , & V_112 , V_113 , & V_114 ,
V_60 > V_57 ? V_57 : V_60 , 0 ) ;
if ( V_41 > 0 ) {
F_39 ( V_111 ) ;
F_40 ( V_71 , V_41 ) ;
F_48 ( V_113 ) ;
F_49 ( V_71 , V_41 ) ;
}
F_41 ( V_71 ) ;
F_50 ( V_71 ) ;
F_86 ( V_113 ) ;
return V_41 ;
}
static int F_87 ( struct V_1 * V_1 , T_1 V_50 , T_9 V_60 , bool V_73 )
{
struct V_17 * V_17 = F_14 ( V_1 ) ;
if ( F_30 ( V_50 < 0 ) )
return - V_6 ;
if ( F_30 ( ( T_1 ) ( V_50 + V_60 ) < 0 ) )
return - V_6 ;
if ( F_30 ( V_17 -> V_52 && F_31 ( V_17 ) ) ) {
T_1 V_122 = V_60 ? V_50 + V_60 - 1 : V_24 ;
int V_26 ;
V_26 = F_32 ( V_17 , V_1 , V_50 , V_122 ,
V_73 ? V_54 : V_53 ) ;
if ( V_26 < 0 )
return V_26 ;
}
return F_33 ( V_1 , V_73 ? V_56 : V_55 ) ;
}
int F_88 ( struct V_1 * V_111 , T_1 V_112 ,
struct V_1 * V_113 , T_1 V_114 , T_9 V_60 )
{
struct V_17 * V_115 = F_14 ( V_111 ) ;
struct V_17 * V_116 = F_14 ( V_113 ) ;
int V_41 ;
if ( V_115 -> V_20 != V_116 -> V_20 ||
V_111 -> V_123 . V_124 != V_113 -> V_123 . V_124 )
return - V_119 ;
if ( F_89 ( V_115 -> V_125 ) || F_89 ( V_116 -> V_125 ) )
return - V_126 ;
if ( ! F_90 ( V_115 -> V_125 ) || ! F_90 ( V_116 -> V_125 ) )
return - V_6 ;
if ( ! ( V_111 -> V_2 & V_66 ) ||
! ( V_113 -> V_2 & V_77 ) ||
( V_113 -> V_117 & V_118 ) )
return - V_67 ;
if ( ! V_111 -> V_30 -> V_127 )
return - V_120 ;
V_41 = F_87 ( V_111 , V_112 , V_60 , false ) ;
if ( V_41 )
return V_41 ;
V_41 = F_87 ( V_113 , V_114 , V_60 , true ) ;
if ( V_41 )
return V_41 ;
if ( V_112 + V_60 > F_7 ( V_115 ) )
return - V_6 ;
V_41 = F_85 ( V_113 ) ;
if ( V_41 )
return V_41 ;
V_41 = V_111 -> V_30 -> V_127 ( V_111 , V_112 ,
V_113 , V_114 , V_60 ) ;
if ( ! V_41 ) {
F_39 ( V_111 ) ;
F_48 ( V_113 ) ;
}
F_86 ( V_113 ) ;
return V_41 ;
}
int F_91 ( struct V_1 * V_1 , struct V_128 * V_129 )
{
struct V_130 * V_131 ;
struct V_17 * V_132 = F_14 ( V_1 ) ;
T_9 V_133 ;
T_9 V_60 ;
int V_134 ;
int V_41 ;
bool V_135 = F_92 ( V_136 ) ;
T_10 V_49 = V_129 -> V_137 ;
struct V_1 * V_138 ;
T_1 V_139 ;
T_2 V_140 ;
if ( ! ( V_1 -> V_2 & V_66 ) )
return - V_6 ;
if ( V_129 -> V_141 || V_129 -> V_142 )
return - V_6 ;
V_133 = V_129 -> V_143 ;
V_60 = V_129 -> V_144 ;
V_41 = - V_126 ;
if ( F_89 ( V_132 -> V_125 ) )
goto V_27;
V_41 = - V_6 ;
if ( ! F_90 ( V_132 -> V_125 ) )
goto V_27;
V_41 = F_87 ( V_1 , V_133 , V_60 , false ) ;
if ( V_41 < 0 )
goto V_27;
V_41 = 0 ;
for ( V_134 = 0 ; V_134 < V_49 ; V_134 ++ ) {
V_129 -> V_131 [ V_134 ] . V_145 = 0ULL ;
V_129 -> V_131 [ V_134 ] . V_146 = V_147 ;
}
for ( V_134 = 0 , V_131 = V_129 -> V_131 ; V_134 < V_49 ; V_134 ++ , V_131 ++ ) {
struct V_17 * V_148 ;
struct V_32 V_149 = F_78 ( V_131 -> V_150 ) ;
V_138 = V_149 . V_1 ;
if ( ! V_138 ) {
V_131 -> V_146 = - V_67 ;
goto V_151;
}
V_148 = F_14 ( V_138 ) ;
V_41 = F_85 ( V_138 ) ;
if ( V_41 ) {
V_131 -> V_146 = V_41 ;
goto V_151;
}
V_139 = V_131 -> V_152 ;
V_41 = F_87 ( V_138 , V_139 , V_60 , true ) ;
if ( V_41 < 0 ) {
V_131 -> V_146 = V_41 ;
goto V_153;
}
V_41 = 0 ;
if ( V_131 -> V_154 ) {
V_131 -> V_146 = - V_6 ;
} else if ( ! ( V_135 || ( V_138 -> V_2 & V_77 ) ) ) {
V_131 -> V_146 = - V_6 ;
} else if ( V_1 -> V_123 . V_124 != V_138 -> V_123 . V_124 ) {
V_131 -> V_146 = - V_119 ;
} else if ( F_89 ( V_148 -> V_125 ) ) {
V_131 -> V_146 = - V_126 ;
} else if ( V_138 -> V_30 -> V_155 == NULL ) {
V_131 -> V_146 = - V_6 ;
} else {
V_140 = V_138 -> V_30 -> V_155 ( V_1 , V_133 ,
V_60 , V_138 ,
V_131 -> V_152 ) ;
if ( V_140 == - V_156 )
V_131 -> V_146 = V_157 ;
else if ( V_140 < 0 )
V_131 -> V_146 = V_140 ;
else
V_131 -> V_145 += V_140 ;
}
V_153:
F_86 ( V_138 ) ;
V_151:
F_24 ( V_149 ) ;
if ( F_93 ( V_71 ) )
goto V_27;
}
V_27:
return V_41 ;
}
