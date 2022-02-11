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
return V_1 -> V_7 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
return - V_24 ;
}
T_1 F_11 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
struct V_17 * V_17 = F_12 ( V_1 ) ;
T_1 V_25 ;
F_13 ( & V_17 -> V_26 ) ;
switch ( V_9 ) {
case V_11 :
V_4 += F_7 ( V_17 ) ;
break;
case V_12 :
if ( V_4 == 0 ) {
V_25 = V_1 -> V_7 ;
goto V_27;
}
V_4 += V_1 -> V_7 ;
break;
case V_14 :
if ( V_4 >= V_17 -> V_28 ) {
V_25 = - V_15 ;
goto V_27;
}
break;
case V_16 :
if ( V_4 >= V_17 -> V_28 ) {
V_25 = - V_15 ;
goto V_27;
}
V_4 = V_17 -> V_28 ;
break;
}
V_25 = - V_6 ;
if ( V_4 >= 0 || F_1 ( V_1 ) ) {
if ( V_4 != V_1 -> V_7 ) {
V_1 -> V_7 = V_4 ;
V_1 -> V_8 = 0 ;
}
V_25 = V_4 ;
}
V_27:
F_14 ( & V_17 -> V_26 ) ;
return V_25 ;
}
T_1 F_15 ( struct V_1 * V_1 , T_1 V_4 , int V_9 )
{
T_1 (* F_16)( struct V_1 * , T_1 , int );
F_16 = F_10 ;
if ( V_1 -> V_2 & V_29 ) {
if ( V_1 -> V_30 && V_1 -> V_30 -> V_31 )
F_16 = V_1 -> V_30 -> V_31 ;
}
return F_16 ( V_1 , V_4 , V_9 ) ;
}
int F_17 ( int V_32 , struct V_1 * V_1 , const T_1 * V_33 , T_2 V_34 )
{
struct V_17 * V_17 ;
T_1 V_35 ;
int V_25 = - V_6 ;
V_17 = F_12 ( V_1 ) ;
if ( F_18 ( ( V_36 ) V_34 < 0 ) )
return V_25 ;
V_35 = * V_33 ;
if ( F_18 ( V_35 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
if ( V_34 >= - V_35 )
return - V_37 ;
} else if ( F_18 ( ( T_1 ) ( V_35 + V_34 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_25 ;
}
if ( F_18 ( V_17 -> V_38 && F_19 ( V_17 ) ) ) {
V_25 = F_20 (
V_32 == V_39 ? V_40 : V_41 ,
V_17 , V_1 , V_35 , V_34 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_21 ( V_1 ,
V_32 == V_39 ? V_42 : V_43 ) ;
if ( V_25 )
return V_25 ;
return V_34 > V_44 ? V_44 : V_34 ;
}
V_36 F_22 ( struct V_1 * V_45 , char T_3 * V_46 , T_2 V_47 , T_1 * V_33 )
{
struct V_48 V_49 = { . V_50 = V_46 , . V_51 = V_47 } ;
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_53 = V_45 -> V_30 -> V_56 ( & V_52 , & V_49 , 1 , V_52 . V_54 ) ;
if ( - V_57 == V_53 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
V_36 F_25 ( struct V_1 * V_1 , char T_3 * V_46 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_53 ;
if ( ! ( V_1 -> V_2 & V_58 ) )
return - V_59 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_60 && ! V_1 -> V_30 -> V_56 ) )
return - V_6 ;
if ( F_18 ( ! F_26 ( V_61 , V_46 , V_34 ) ) )
return - V_62 ;
V_53 = F_17 ( V_39 , V_1 , V_35 , V_34 ) ;
if ( V_53 >= 0 ) {
V_34 = V_53 ;
if ( V_1 -> V_30 -> V_60 )
V_53 = V_1 -> V_30 -> V_60 ( V_1 , V_46 , V_34 , V_35 ) ;
else
V_53 = F_22 ( V_1 , V_46 , V_34 , V_35 ) ;
if ( V_53 > 0 ) {
F_27 ( V_1 ) ;
F_28 ( V_63 , V_53 ) ;
}
F_29 ( V_63 ) ;
}
return V_53 ;
}
V_36 F_30 ( struct V_1 * V_45 , const char T_3 * V_46 , T_2 V_47 , T_1 * V_33 )
{
struct V_48 V_49 = { . V_50 = ( void T_3 * ) V_46 , . V_51 = V_47 } ;
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_53 = V_45 -> V_30 -> V_64 ( & V_52 , & V_49 , 1 , V_52 . V_54 ) ;
if ( - V_57 == V_53 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
V_36 F_31 ( struct V_1 * V_1 , const char * V_46 , T_2 V_34 , T_1 * V_35 )
{
T_4 V_65 ;
const char T_3 * V_66 ;
V_36 V_53 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_67 && ! V_1 -> V_30 -> V_64 ) )
return - V_6 ;
V_65 = F_32 () ;
F_33 ( F_34 () ) ;
V_66 = ( V_68 const char T_3 * ) V_46 ;
if ( V_34 > V_44 )
V_34 = V_44 ;
if ( V_1 -> V_30 -> V_67 )
V_53 = V_1 -> V_30 -> V_67 ( V_1 , V_66 , V_34 , V_35 ) ;
else
V_53 = F_30 ( V_1 , V_66 , V_34 , V_35 ) ;
F_33 ( V_65 ) ;
if ( V_53 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_63 , V_53 ) ;
}
F_37 ( V_63 ) ;
return V_53 ;
}
V_36 F_38 ( struct V_1 * V_1 , const char T_3 * V_46 , T_2 V_34 , T_1 * V_35 )
{
V_36 V_53 ;
if ( ! ( V_1 -> V_2 & V_69 ) )
return - V_59 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_67 && ! V_1 -> V_30 -> V_64 ) )
return - V_6 ;
if ( F_18 ( ! F_26 ( V_70 , V_46 , V_34 ) ) )
return - V_62 ;
V_53 = F_17 ( V_71 , V_1 , V_35 , V_34 ) ;
if ( V_53 >= 0 ) {
V_34 = V_53 ;
F_39 ( V_1 ) ;
if ( V_1 -> V_30 -> V_67 )
V_53 = V_1 -> V_30 -> V_67 ( V_1 , V_46 , V_34 , V_35 ) ;
else
V_53 = F_30 ( V_1 , V_46 , V_34 , V_35 ) ;
if ( V_53 > 0 ) {
F_35 ( V_1 ) ;
F_36 ( V_63 , V_53 ) ;
}
F_37 ( V_63 ) ;
F_40 ( V_1 ) ;
}
return V_53 ;
}
static inline T_1 F_41 ( struct V_1 * V_1 )
{
return V_1 -> V_7 ;
}
static inline void F_42 ( struct V_1 * V_1 , T_1 V_35 )
{
V_1 -> V_7 = V_35 ;
}
unsigned long F_43 ( struct V_48 * V_49 , unsigned long V_72 , T_2 V_73 )
{
unsigned long V_74 = 0 ;
T_2 V_47 = 0 ;
while ( V_74 < V_72 ) {
V_74 ++ ;
if ( V_47 + V_49 -> V_51 >= V_73 ) {
V_49 -> V_51 = V_73 - V_47 ;
break;
}
V_47 += V_49 -> V_51 ;
V_49 ++ ;
}
return V_74 ;
}
static V_36 F_44 ( struct V_1 * V_45 , const struct V_48 * V_49 ,
unsigned long V_72 , T_2 V_47 , T_1 * V_33 , T_5 F_16 )
{
struct V_52 V_52 ;
V_36 V_53 ;
F_23 ( & V_52 , V_45 ) ;
V_52 . V_54 = * V_33 ;
V_52 . V_55 = V_47 ;
V_53 = F_16 ( & V_52 , V_49 , V_72 , V_52 . V_54 ) ;
if ( V_53 == - V_57 )
V_53 = F_24 ( & V_52 ) ;
* V_33 = V_52 . V_54 ;
return V_53 ;
}
static V_36 F_45 ( struct V_1 * V_45 , struct V_48 * V_49 ,
unsigned long V_72 , T_1 * V_33 , T_6 F_16 )
{
struct V_48 * V_75 = V_49 ;
V_36 V_53 = 0 ;
while ( V_72 > 0 ) {
void T_3 * V_76 ;
T_2 V_47 ;
V_36 V_77 ;
V_76 = V_75 -> V_50 ;
V_47 = V_75 -> V_51 ;
V_75 ++ ;
V_72 -- ;
V_77 = F_16 ( V_45 , V_76 , V_47 , V_33 ) ;
if ( V_77 < 0 ) {
if ( ! V_53 )
V_53 = V_77 ;
break;
}
V_53 += V_77 ;
if ( V_77 != V_47 )
break;
}
return V_53 ;
}
V_36 F_46 ( int type , const struct V_48 T_3 * V_78 ,
unsigned long V_72 , unsigned long V_79 ,
struct V_48 * V_80 ,
struct V_48 * * V_81 )
{
unsigned long V_74 ;
V_36 V_53 ;
struct V_48 * V_49 = V_80 ;
if ( V_72 == 0 ) {
V_53 = 0 ;
goto V_27;
}
if ( V_72 > V_82 ) {
V_53 = - V_6 ;
goto V_27;
}
if ( V_72 > V_79 ) {
V_49 = F_47 ( V_72 * sizeof( struct V_48 ) , V_83 ) ;
if ( V_49 == NULL ) {
V_53 = - V_84 ;
goto V_27;
}
}
if ( F_48 ( V_49 , V_78 , V_72 * sizeof( * V_78 ) ) ) {
V_53 = - V_62 ;
goto V_27;
}
V_53 = 0 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
void T_3 * V_46 = V_49 [ V_74 ] . V_50 ;
V_36 V_47 = ( V_36 ) V_49 [ V_74 ] . V_51 ;
if ( V_47 < 0 ) {
V_53 = - V_6 ;
goto V_27;
}
if ( type >= 0
&& F_18 ( ! F_26 ( F_49 ( type ) , V_46 , V_47 ) ) ) {
V_53 = - V_62 ;
goto V_27;
}
if ( V_47 > V_44 - V_53 ) {
V_47 = V_44 - V_53 ;
V_49 [ V_74 ] . V_51 = V_47 ;
}
V_53 += V_47 ;
}
V_27:
* V_81 = V_49 ;
return V_53 ;
}
static V_36 F_50 ( int type , struct V_1 * V_1 ,
const struct V_48 T_3 * V_78 ,
unsigned long V_72 , T_1 * V_35 )
{
T_2 V_85 ;
struct V_48 V_86 [ V_87 ] ;
struct V_48 * V_49 = V_86 ;
V_36 V_53 ;
T_6 F_16 ;
T_5 V_88 ;
if ( ! V_1 -> V_30 ) {
V_53 = - V_6 ;
goto V_27;
}
V_53 = F_46 ( type , V_78 , V_72 ,
F_51 ( V_86 ) , V_86 , & V_49 ) ;
if ( V_53 <= 0 )
goto V_27;
V_85 = V_53 ;
V_53 = F_17 ( type , V_1 , V_35 , V_85 ) ;
if ( V_53 < 0 )
goto V_27;
V_88 = NULL ;
if ( type == V_39 ) {
F_16 = V_1 -> V_30 -> V_60 ;
V_88 = V_1 -> V_30 -> V_56 ;
} else {
F_16 = ( T_6 ) V_1 -> V_30 -> V_67 ;
V_88 = V_1 -> V_30 -> V_64 ;
F_39 ( V_1 ) ;
}
if ( V_88 )
V_53 = F_44 ( V_1 , V_49 , V_72 , V_85 ,
V_35 , V_88 ) ;
else
V_53 = F_45 ( V_1 , V_49 , V_72 , V_35 , F_16 ) ;
if ( type != V_39 )
F_40 ( V_1 ) ;
V_27:
if ( V_49 != V_86 )
F_52 ( V_49 ) ;
if ( ( V_53 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_27 ( V_1 ) ;
else
F_35 ( V_1 ) ;
}
return V_53 ;
}
V_36 F_53 ( struct V_1 * V_1 , const struct V_48 T_3 * V_89 ,
unsigned long V_90 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_58 ) )
return - V_59 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_56 && ! V_1 -> V_30 -> V_60 ) )
return - V_6 ;
return F_50 ( V_39 , V_1 , V_89 , V_90 , V_35 ) ;
}
V_36 F_54 ( struct V_1 * V_1 , const struct V_48 T_3 * V_89 ,
unsigned long V_90 , T_1 * V_35 )
{
if ( ! ( V_1 -> V_2 & V_69 ) )
return - V_59 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_64 && ! V_1 -> V_30 -> V_67 ) )
return - V_6 ;
return F_50 ( V_71 , V_1 , V_89 , V_90 , V_35 ) ;
}
static inline T_1 F_55 ( unsigned long V_91 , unsigned long V_92 )
{
#define F_56 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_91 << F_56 ) << F_56 ) | V_92 ;
}
static V_36 F_57 ( int type , struct V_1 * V_1 ,
const struct V_93 T_3 * V_78 ,
unsigned long V_72 , T_1 * V_35 )
{
T_7 V_85 ;
struct V_48 V_86 [ V_87 ] ;
struct V_48 * V_49 = V_86 ;
V_36 V_53 ;
T_6 F_16 ;
T_5 V_88 ;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 )
goto V_27;
V_53 = - V_62 ;
if ( ! F_26 ( V_70 , V_78 , V_72 * sizeof( * V_78 ) ) )
goto V_27;
V_53 = F_58 ( type , V_78 , V_72 ,
V_87 , V_86 , & V_49 ) ;
if ( V_53 <= 0 )
goto V_27;
V_85 = V_53 ;
V_53 = F_17 ( type , V_1 , V_35 , V_85 ) ;
if ( V_53 < 0 )
goto V_27;
V_88 = NULL ;
if ( type == V_39 ) {
F_16 = V_1 -> V_30 -> V_60 ;
V_88 = V_1 -> V_30 -> V_56 ;
} else {
F_16 = ( T_6 ) V_1 -> V_30 -> V_67 ;
V_88 = V_1 -> V_30 -> V_64 ;
F_39 ( V_1 ) ;
}
if ( V_88 )
V_53 = F_44 ( V_1 , V_49 , V_72 , V_85 ,
V_35 , V_88 ) ;
else
V_53 = F_45 ( V_1 , V_49 , V_72 , V_35 , F_16 ) ;
if ( type != V_39 )
F_40 ( V_1 ) ;
V_27:
if ( V_49 != V_86 )
F_52 ( V_49 ) ;
if ( ( V_53 + ( type == V_39 ) ) > 0 ) {
if ( type == V_39 )
F_27 ( V_1 ) ;
else
F_35 ( V_1 ) ;
}
return V_53 ;
}
static T_2 F_59 ( struct V_1 * V_1 ,
const struct V_93 T_3 * V_89 ,
unsigned long V_90 , T_1 * V_35 )
{
V_36 V_53 = - V_59 ;
if ( ! ( V_1 -> V_2 & V_58 ) )
goto V_27;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_56 && ! V_1 -> V_30 -> V_60 ) )
goto V_27;
V_53 = F_57 ( V_39 , V_1 , V_89 , V_90 , V_35 ) ;
V_27:
if ( V_53 > 0 )
F_28 ( V_63 , V_53 ) ;
F_29 ( V_63 ) ;
return V_53 ;
}
static T_2 F_60 ( struct V_1 * V_1 ,
const struct V_93 T_3 * V_89 ,
unsigned long V_90 , T_1 * V_35 )
{
V_36 V_53 = - V_59 ;
if ( ! ( V_1 -> V_2 & V_69 ) )
goto V_27;
V_53 = - V_6 ;
if ( ! V_1 -> V_30 || ( ! V_1 -> V_30 -> V_64 && ! V_1 -> V_30 -> V_67 ) )
goto V_27;
V_53 = F_57 ( V_71 , V_1 , V_89 , V_90 , V_35 ) ;
V_27:
if ( V_53 > 0 )
F_36 ( V_63 , V_53 ) ;
F_37 ( V_63 ) ;
return V_53 ;
}
static V_36 F_61 ( int V_94 , int V_95 , T_1 * V_33 ,
T_2 V_34 , T_1 V_96 )
{
struct V_97 V_98 , V_27 ;
struct V_17 * V_99 , * V_100 ;
T_1 V_35 ;
T_1 V_101 ;
V_36 V_25 ;
int V_102 ;
V_25 = - V_59 ;
V_98 = F_62 ( V_95 ) ;
if ( ! V_98 . V_1 )
goto V_27;
if ( ! ( V_98 . V_1 -> V_2 & V_58 ) )
goto V_103;
V_25 = - V_24 ;
if ( ! V_33 ) {
V_35 = V_98 . V_1 -> V_7 ;
} else {
V_35 = * V_33 ;
if ( ! ( V_98 . V_1 -> V_2 & V_104 ) )
goto V_103;
}
V_25 = F_17 ( V_39 , V_98 . V_1 , & V_35 , V_34 ) ;
if ( V_25 < 0 )
goto V_103;
V_34 = V_25 ;
V_25 = - V_59 ;
V_27 = F_62 ( V_94 ) ;
if ( ! V_27 . V_1 )
goto V_103;
if ( ! ( V_27 . V_1 -> V_2 & V_69 ) )
goto V_105;
V_25 = - V_6 ;
V_99 = F_12 ( V_98 . V_1 ) ;
V_100 = F_12 ( V_27 . V_1 ) ;
V_101 = V_27 . V_1 -> V_7 ;
V_25 = F_17 ( V_71 , V_27 . V_1 , & V_101 , V_34 ) ;
if ( V_25 < 0 )
goto V_105;
V_34 = V_25 ;
if ( ! V_96 )
V_96 = F_63 ( V_99 -> V_20 -> V_21 , V_100 -> V_20 -> V_21 ) ;
if ( F_18 ( V_35 + V_34 > V_96 ) ) {
V_25 = - V_37 ;
if ( V_35 >= V_96 )
goto V_105;
V_34 = V_96 - V_35 ;
}
V_102 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
F_39 ( V_27 . V_1 ) ;
V_25 = F_64 ( V_98 . V_1 , & V_35 , V_27 . V_1 , & V_101 , V_34 , V_102 ) ;
F_40 ( V_27 . V_1 ) ;
if ( V_25 > 0 ) {
F_28 ( V_63 , V_25 ) ;
F_36 ( V_63 , V_25 ) ;
F_27 ( V_98 . V_1 ) ;
F_35 ( V_27 . V_1 ) ;
V_27 . V_1 -> V_7 = V_101 ;
if ( V_33 )
* V_33 = V_35 ;
else
V_98 . V_1 -> V_7 = V_35 ;
}
F_29 ( V_63 ) ;
F_37 ( V_63 ) ;
if ( V_35 > V_96 )
V_25 = - V_37 ;
V_105:
F_65 ( V_27 ) ;
V_103:
F_65 ( V_98 ) ;
V_27:
return V_25 ;
}
