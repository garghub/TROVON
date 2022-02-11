static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 & V_3 ;
}
static T_1 F_2 ( struct V_1 * V_1 , struct V_4 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
if ( V_5 < 0 && ! F_1 ( V_1 ) )
return - V_7 ;
if ( V_5 > V_6 )
return - V_7 ;
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
return V_5 ;
}
T_1
F_3 ( struct V_1 * V_1 , T_1 V_5 , int V_10 ,
T_1 V_6 , T_1 V_11 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
switch ( V_10 ) {
case V_14 :
V_5 += V_11 ;
break;
case V_15 :
if ( V_5 == 0 )
return V_1 -> V_8 ;
F_4 ( & V_1 -> V_16 ) ;
V_5 = F_2 ( V_1 , V_4 , V_1 -> V_8 + V_5 ,
V_6 ) ;
F_5 ( & V_1 -> V_16 ) ;
return V_5 ;
case V_17 :
if ( V_5 >= V_11 )
return - V_18 ;
break;
case V_19 :
if ( V_5 >= V_11 )
return - V_18 ;
V_5 = V_11 ;
break;
}
return F_2 ( V_1 , V_4 , V_5 , V_6 ) ;
}
T_1 F_6 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = V_1 -> V_12 -> V_13 ;
return F_3 ( V_1 , V_5 , V_10 ,
V_4 -> V_20 -> V_21 ,
F_7 ( V_4 ) ) ;
}
T_1 F_8 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return V_1 -> V_8 ;
}
T_1 F_9 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
return - V_22 ;
}
T_1 F_10 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
struct V_4 * V_4 = F_11 ( V_1 ) ;
T_1 V_23 ;
F_12 ( & V_4 -> V_24 ) ;
switch ( V_10 ) {
case V_14 :
V_5 += F_7 ( V_4 ) ;
break;
case V_15 :
if ( V_5 == 0 ) {
V_23 = V_1 -> V_8 ;
goto V_25;
}
V_5 += V_1 -> V_8 ;
break;
case V_17 :
if ( V_5 >= V_4 -> V_26 ) {
V_23 = - V_18 ;
goto V_25;
}
break;
case V_19 :
if ( V_5 >= V_4 -> V_26 ) {
V_23 = - V_18 ;
goto V_25;
}
V_5 = V_4 -> V_26 ;
break;
}
V_23 = - V_7 ;
if ( V_5 >= 0 || F_1 ( V_1 ) ) {
if ( V_5 != V_1 -> V_8 ) {
V_1 -> V_8 = V_5 ;
V_1 -> V_9 = 0 ;
}
V_23 = V_5 ;
}
V_25:
F_13 ( & V_4 -> V_24 ) ;
return V_23 ;
}
T_1 F_14 ( struct V_1 * V_1 , T_1 V_5 , int V_10 )
{
T_1 (* F_15)( struct V_1 * , T_1 , int );
F_15 = F_9 ;
if ( V_1 -> V_2 & V_27 ) {
if ( V_1 -> V_28 && V_1 -> V_28 -> V_29 )
F_15 = V_1 -> V_28 -> V_29 ;
}
return F_15 ( V_1 , V_5 , V_10 ) ;
}
int F_16 ( int V_30 , struct V_1 * V_1 , T_1 * V_31 , T_2 V_32 )
{
struct V_4 * V_4 ;
T_1 V_33 ;
int V_23 = - V_7 ;
V_4 = F_11 ( V_1 ) ;
if ( F_17 ( ( V_34 ) V_32 < 0 ) )
return V_23 ;
V_33 = * V_31 ;
if ( F_17 ( V_33 < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_23 ;
if ( V_32 >= - V_33 )
return - V_35 ;
} else if ( F_17 ( ( T_1 ) ( V_33 + V_32 ) < 0 ) ) {
if ( ! F_1 ( V_1 ) )
return V_23 ;
}
if ( F_17 ( V_4 -> V_36 && F_18 ( V_4 ) ) ) {
V_23 = F_19 (
V_30 == V_37 ? V_38 : V_39 ,
V_4 , V_1 , V_33 , V_32 ) ;
if ( V_23 < 0 )
return V_23 ;
}
V_23 = F_20 ( V_1 ,
V_30 == V_37 ? V_40 : V_41 ) ;
if ( V_23 )
return V_23 ;
return V_32 > V_42 ? V_42 : V_32 ;
}
V_34 F_21 ( struct V_1 * V_43 , char T_3 * V_44 , T_2 V_45 , T_1 * V_31 )
{
struct V_46 V_47 = { . V_48 = V_44 , . V_49 = V_45 } ;
struct V_50 V_50 ;
V_34 V_51 ;
F_22 ( & V_50 , V_43 ) ;
V_50 . V_52 = * V_31 ;
V_50 . V_53 = V_45 ;
V_50 . V_54 = V_45 ;
V_51 = V_43 -> V_28 -> V_55 ( & V_50 , & V_47 , 1 , V_50 . V_52 ) ;
if ( - V_56 == V_51 )
V_51 = F_23 ( & V_50 ) ;
* V_31 = V_50 . V_52 ;
return V_51 ;
}
V_34 F_24 ( struct V_1 * V_1 , char T_3 * V_44 , T_2 V_32 , T_1 * V_33 )
{
V_34 V_51 ;
if ( ! ( V_1 -> V_2 & V_57 ) )
return - V_58 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_59 && ! V_1 -> V_28 -> V_55 ) )
return - V_7 ;
if ( F_17 ( ! F_25 ( V_60 , V_44 , V_32 ) ) )
return - V_61 ;
V_51 = F_16 ( V_37 , V_1 , V_33 , V_32 ) ;
if ( V_51 >= 0 ) {
V_32 = V_51 ;
if ( V_1 -> V_28 -> V_59 )
V_51 = V_1 -> V_28 -> V_59 ( V_1 , V_44 , V_32 , V_33 ) ;
else
V_51 = F_21 ( V_1 , V_44 , V_32 , V_33 ) ;
if ( V_51 > 0 ) {
F_26 ( V_1 ) ;
F_27 ( V_62 , V_51 ) ;
}
F_28 ( V_62 ) ;
}
return V_51 ;
}
V_34 F_29 ( struct V_1 * V_43 , const char T_3 * V_44 , T_2 V_45 , T_1 * V_31 )
{
struct V_46 V_47 = { . V_48 = ( void T_3 * ) V_44 , . V_49 = V_45 } ;
struct V_50 V_50 ;
V_34 V_51 ;
F_22 ( & V_50 , V_43 ) ;
V_50 . V_52 = * V_31 ;
V_50 . V_53 = V_45 ;
V_50 . V_54 = V_45 ;
V_51 = V_43 -> V_28 -> V_63 ( & V_50 , & V_47 , 1 , V_50 . V_52 ) ;
if ( - V_56 == V_51 )
V_51 = F_23 ( & V_50 ) ;
* V_31 = V_50 . V_52 ;
return V_51 ;
}
V_34 F_30 ( struct V_1 * V_1 , const char * V_44 , T_2 V_32 , T_1 * V_33 )
{
T_4 V_64 ;
const char T_3 * V_65 ;
V_34 V_51 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_66 && ! V_1 -> V_28 -> V_63 ) )
return - V_7 ;
V_64 = F_31 () ;
F_32 ( F_33 () ) ;
V_65 = ( V_67 const char T_3 * ) V_44 ;
if ( V_32 > V_42 )
V_32 = V_42 ;
if ( V_1 -> V_28 -> V_66 )
V_51 = V_1 -> V_28 -> V_66 ( V_1 , V_65 , V_32 , V_33 ) ;
else
V_51 = F_29 ( V_1 , V_65 , V_32 , V_33 ) ;
F_32 ( V_64 ) ;
if ( V_51 > 0 ) {
F_34 ( V_1 ) ;
F_35 ( V_62 , V_51 ) ;
}
F_36 ( V_62 ) ;
return V_51 ;
}
V_34 F_37 ( struct V_1 * V_1 , const char T_3 * V_44 , T_2 V_32 , T_1 * V_33 )
{
V_34 V_51 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_58 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_66 && ! V_1 -> V_28 -> V_63 ) )
return - V_7 ;
if ( F_17 ( ! F_25 ( V_69 , V_44 , V_32 ) ) )
return - V_61 ;
V_51 = F_16 ( V_70 , V_1 , V_33 , V_32 ) ;
if ( V_51 >= 0 ) {
V_32 = V_51 ;
F_38 ( V_1 ) ;
if ( V_1 -> V_28 -> V_66 )
V_51 = V_1 -> V_28 -> V_66 ( V_1 , V_44 , V_32 , V_33 ) ;
else
V_51 = F_29 ( V_1 , V_44 , V_32 , V_33 ) ;
if ( V_51 > 0 ) {
F_34 ( V_1 ) ;
F_35 ( V_62 , V_51 ) ;
}
F_36 ( V_62 ) ;
F_39 ( V_1 ) ;
}
return V_51 ;
}
static inline T_1 F_40 ( struct V_1 * V_1 )
{
return V_1 -> V_8 ;
}
static inline void F_41 ( struct V_1 * V_1 , T_1 V_33 )
{
V_1 -> V_8 = V_33 ;
}
unsigned long F_42 ( struct V_46 * V_47 , unsigned long V_71 , T_2 V_72 )
{
unsigned long V_73 = 0 ;
T_2 V_45 = 0 ;
while ( V_73 < V_71 ) {
V_73 ++ ;
if ( V_45 + V_47 -> V_49 >= V_72 ) {
V_47 -> V_49 = V_72 - V_45 ;
break;
}
V_45 += V_47 -> V_49 ;
V_47 ++ ;
}
return V_73 ;
}
static V_34 F_43 ( struct V_1 * V_43 , const struct V_46 * V_47 ,
unsigned long V_71 , T_2 V_45 , T_1 * V_31 , T_5 F_15 )
{
struct V_50 V_50 ;
V_34 V_51 ;
F_22 ( & V_50 , V_43 ) ;
V_50 . V_52 = * V_31 ;
V_50 . V_53 = V_45 ;
V_50 . V_54 = V_45 ;
V_51 = F_15 ( & V_50 , V_47 , V_71 , V_50 . V_52 ) ;
if ( V_51 == - V_56 )
V_51 = F_23 ( & V_50 ) ;
* V_31 = V_50 . V_52 ;
return V_51 ;
}
static V_34 F_44 ( struct V_1 * V_43 , struct V_46 * V_47 ,
unsigned long V_71 , T_1 * V_31 , T_6 F_15 )
{
struct V_46 * V_74 = V_47 ;
V_34 V_51 = 0 ;
while ( V_71 > 0 ) {
void T_3 * V_75 ;
T_2 V_45 ;
V_34 V_76 ;
V_75 = V_74 -> V_48 ;
V_45 = V_74 -> V_49 ;
V_74 ++ ;
V_71 -- ;
V_76 = F_15 ( V_43 , V_75 , V_45 , V_31 ) ;
if ( V_76 < 0 ) {
if ( ! V_51 )
V_51 = V_76 ;
break;
}
V_51 += V_76 ;
if ( V_76 != V_45 )
break;
}
return V_51 ;
}
V_34 F_45 ( int type , const struct V_46 T_3 * V_77 ,
unsigned long V_71 , unsigned long V_78 ,
struct V_46 * V_79 ,
struct V_46 * * V_80 )
{
unsigned long V_73 ;
V_34 V_51 ;
struct V_46 * V_47 = V_79 ;
if ( V_71 == 0 ) {
V_51 = 0 ;
goto V_25;
}
if ( V_71 > V_81 ) {
V_51 = - V_7 ;
goto V_25;
}
if ( V_71 > V_78 ) {
V_47 = F_46 ( V_71 * sizeof( struct V_46 ) , V_82 ) ;
if ( V_47 == NULL ) {
V_51 = - V_83 ;
goto V_25;
}
}
if ( F_47 ( V_47 , V_77 , V_71 * sizeof( * V_77 ) ) ) {
V_51 = - V_61 ;
goto V_25;
}
V_51 = 0 ;
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
void T_3 * V_44 = V_47 [ V_73 ] . V_48 ;
V_34 V_45 = ( V_34 ) V_47 [ V_73 ] . V_49 ;
if ( V_45 < 0 ) {
V_51 = - V_7 ;
goto V_25;
}
if ( type >= 0
&& F_17 ( ! F_25 ( F_48 ( type ) , V_44 , V_45 ) ) ) {
V_51 = - V_61 ;
goto V_25;
}
if ( V_45 > V_42 - V_51 ) {
V_45 = V_42 - V_51 ;
V_47 [ V_73 ] . V_49 = V_45 ;
}
V_51 += V_45 ;
}
V_25:
* V_80 = V_47 ;
return V_51 ;
}
static V_34 F_49 ( int type , struct V_1 * V_1 ,
const struct V_46 T_3 * V_77 ,
unsigned long V_71 , T_1 * V_33 )
{
T_2 V_84 ;
struct V_46 V_85 [ V_86 ] ;
struct V_46 * V_47 = V_85 ;
V_34 V_51 ;
T_6 F_15 ;
T_5 V_87 ;
if ( ! V_1 -> V_28 ) {
V_51 = - V_7 ;
goto V_25;
}
V_51 = F_45 ( type , V_77 , V_71 ,
F_50 ( V_85 ) , V_85 , & V_47 ) ;
if ( V_51 <= 0 )
goto V_25;
V_84 = V_51 ;
V_51 = F_16 ( type , V_1 , V_33 , V_84 ) ;
if ( V_51 < 0 )
goto V_25;
V_87 = NULL ;
if ( type == V_37 ) {
F_15 = V_1 -> V_28 -> V_59 ;
V_87 = V_1 -> V_28 -> V_55 ;
} else {
F_15 = ( T_6 ) V_1 -> V_28 -> V_66 ;
V_87 = V_1 -> V_28 -> V_63 ;
F_38 ( V_1 ) ;
}
if ( V_87 )
V_51 = F_43 ( V_1 , V_47 , V_71 , V_84 ,
V_33 , V_87 ) ;
else
V_51 = F_44 ( V_1 , V_47 , V_71 , V_33 , F_15 ) ;
if ( type != V_37 )
F_39 ( V_1 ) ;
V_25:
if ( V_47 != V_85 )
F_51 ( V_47 ) ;
if ( ( V_51 + ( type == V_37 ) ) > 0 ) {
if ( type == V_37 )
F_26 ( V_1 ) ;
else
F_34 ( V_1 ) ;
}
return V_51 ;
}
V_34 F_52 ( struct V_1 * V_1 , const struct V_46 T_3 * V_88 ,
unsigned long V_89 , T_1 * V_33 )
{
if ( ! ( V_1 -> V_2 & V_57 ) )
return - V_58 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_55 && ! V_1 -> V_28 -> V_59 ) )
return - V_7 ;
return F_49 ( V_37 , V_1 , V_88 , V_89 , V_33 ) ;
}
V_34 F_53 ( struct V_1 * V_1 , const struct V_46 T_3 * V_88 ,
unsigned long V_89 , T_1 * V_33 )
{
if ( ! ( V_1 -> V_2 & V_68 ) )
return - V_58 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_63 && ! V_1 -> V_28 -> V_66 ) )
return - V_7 ;
return F_49 ( V_70 , V_1 , V_88 , V_89 , V_33 ) ;
}
static inline T_1 F_54 ( unsigned long V_90 , unsigned long V_91 )
{
#define F_55 (BITS_PER_LONG / 2)
return ( ( ( T_1 ) V_90 << F_55 ) << F_55 ) | V_91 ;
}
static V_34 F_56 ( int type , struct V_1 * V_1 ,
const struct V_92 T_3 * V_77 ,
unsigned long V_71 , T_1 * V_33 )
{
T_7 V_84 ;
struct V_46 V_85 [ V_86 ] ;
struct V_46 * V_47 = V_85 ;
V_34 V_51 ;
T_6 F_15 ;
T_5 V_87 ;
V_51 = - V_7 ;
if ( ! V_1 -> V_28 )
goto V_25;
V_51 = - V_61 ;
if ( ! F_25 ( V_69 , V_77 , V_71 * sizeof( * V_77 ) ) )
goto V_25;
V_51 = F_57 ( type , V_77 , V_71 ,
V_86 , V_85 , & V_47 ) ;
if ( V_51 <= 0 )
goto V_25;
V_84 = V_51 ;
V_51 = F_16 ( type , V_1 , V_33 , V_84 ) ;
if ( V_51 < 0 )
goto V_25;
V_87 = NULL ;
if ( type == V_37 ) {
F_15 = V_1 -> V_28 -> V_59 ;
V_87 = V_1 -> V_28 -> V_55 ;
} else {
F_15 = ( T_6 ) V_1 -> V_28 -> V_66 ;
V_87 = V_1 -> V_28 -> V_63 ;
F_38 ( V_1 ) ;
}
if ( V_87 )
V_51 = F_43 ( V_1 , V_47 , V_71 , V_84 ,
V_33 , V_87 ) ;
else
V_51 = F_44 ( V_1 , V_47 , V_71 , V_33 , F_15 ) ;
if ( type != V_37 )
F_39 ( V_1 ) ;
V_25:
if ( V_47 != V_85 )
F_51 ( V_47 ) ;
if ( ( V_51 + ( type == V_37 ) ) > 0 ) {
if ( type == V_37 )
F_26 ( V_1 ) ;
else
F_34 ( V_1 ) ;
}
return V_51 ;
}
static T_2 F_58 ( struct V_1 * V_1 ,
const struct V_92 T_3 * V_88 ,
unsigned long V_89 , T_1 * V_33 )
{
V_34 V_51 = - V_58 ;
if ( ! ( V_1 -> V_2 & V_57 ) )
goto V_25;
V_51 = - V_7 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_55 && ! V_1 -> V_28 -> V_59 ) )
goto V_25;
V_51 = F_56 ( V_37 , V_1 , V_88 , V_89 , V_33 ) ;
V_25:
if ( V_51 > 0 )
F_27 ( V_62 , V_51 ) ;
F_28 ( V_62 ) ;
return V_51 ;
}
static T_2 F_59 ( struct V_1 * V_1 ,
const struct V_92 T_3 * V_88 ,
unsigned long V_89 , T_1 * V_33 )
{
V_34 V_51 = - V_58 ;
if ( ! ( V_1 -> V_2 & V_68 ) )
goto V_25;
V_51 = - V_7 ;
if ( ! V_1 -> V_28 || ( ! V_1 -> V_28 -> V_63 && ! V_1 -> V_28 -> V_66 ) )
goto V_25;
V_51 = F_56 ( V_70 , V_1 , V_88 , V_89 , V_33 ) ;
V_25:
if ( V_51 > 0 )
F_35 ( V_62 , V_51 ) ;
F_36 ( V_62 ) ;
return V_51 ;
}
static V_34 F_60 ( int V_93 , int V_94 , T_1 * V_31 ,
T_2 V_32 , T_1 V_95 )
{
struct V_96 V_97 , V_25 ;
struct V_4 * V_98 , * V_99 ;
T_1 V_33 ;
T_1 V_100 ;
V_34 V_23 ;
int V_101 ;
V_23 = - V_58 ;
V_97 = F_61 ( V_94 ) ;
if ( ! V_97 . V_1 )
goto V_25;
if ( ! ( V_97 . V_1 -> V_2 & V_57 ) )
goto V_102;
V_23 = - V_22 ;
if ( ! V_31 ) {
V_33 = V_97 . V_1 -> V_8 ;
} else {
V_33 = * V_31 ;
if ( ! ( V_97 . V_1 -> V_2 & V_103 ) )
goto V_102;
}
V_23 = F_16 ( V_37 , V_97 . V_1 , & V_33 , V_32 ) ;
if ( V_23 < 0 )
goto V_102;
V_32 = V_23 ;
V_23 = - V_58 ;
V_25 = F_61 ( V_93 ) ;
if ( ! V_25 . V_1 )
goto V_102;
if ( ! ( V_25 . V_1 -> V_2 & V_68 ) )
goto V_104;
V_23 = - V_7 ;
V_98 = F_11 ( V_97 . V_1 ) ;
V_99 = F_11 ( V_25 . V_1 ) ;
V_100 = V_25 . V_1 -> V_8 ;
V_23 = F_16 ( V_70 , V_25 . V_1 , & V_100 , V_32 ) ;
if ( V_23 < 0 )
goto V_104;
V_32 = V_23 ;
if ( ! V_95 )
V_95 = F_62 ( V_98 -> V_20 -> V_21 , V_99 -> V_20 -> V_21 ) ;
if ( F_17 ( V_33 + V_32 > V_95 ) ) {
V_23 = - V_35 ;
if ( V_33 >= V_95 )
goto V_104;
V_32 = V_95 - V_33 ;
}
V_101 = 0 ;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
V_23 = F_63 ( V_97 . V_1 , & V_33 , V_25 . V_1 , & V_100 , V_32 , V_101 ) ;
if ( V_23 > 0 ) {
F_27 ( V_62 , V_23 ) ;
F_35 ( V_62 , V_23 ) ;
F_26 ( V_97 . V_1 ) ;
F_34 ( V_25 . V_1 ) ;
V_25 . V_1 -> V_8 = V_100 ;
if ( V_31 )
* V_31 = V_33 ;
else
V_97 . V_1 -> V_8 = V_33 ;
}
F_28 ( V_62 ) ;
F_36 ( V_62 ) ;
if ( V_33 > V_95 )
V_23 = - V_35 ;
V_104:
F_64 ( V_25 ) ;
V_102:
F_64 ( V_97 ) ;
V_25:
return V_23 ;
}
