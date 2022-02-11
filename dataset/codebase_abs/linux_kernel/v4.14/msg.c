static unsigned int F_1 ( unsigned int V_1 )
{
return ( V_1 + 3 ) & ~ 3u ;
}
struct V_2 * F_2 ( T_1 V_3 , T_2 V_4 )
{
struct V_2 * V_5 ;
unsigned int V_6 = ( V_7 + V_3 + 3 ) & ~ 3u ;
V_5 = F_3 ( V_6 , V_4 ) ;
if ( V_5 ) {
F_4 ( V_5 , V_7 ) ;
F_5 ( V_5 , V_3 ) ;
V_5 -> V_8 = NULL ;
}
return V_5 ;
}
void F_6 ( T_1 V_9 , struct V_10 * V_11 , T_1 V_12 , T_1 type ,
T_1 V_13 , T_1 V_14 )
{
memset ( V_11 , 0 , V_13 ) ;
F_7 ( V_11 ) ;
F_8 ( V_11 , V_12 ) ;
F_9 ( V_11 , V_13 ) ;
F_10 ( V_11 , V_13 ) ;
F_11 ( V_11 , V_9 ) ;
F_12 ( V_11 , type ) ;
if ( V_13 > V_15 ) {
F_13 ( V_11 , V_9 ) ;
F_14 ( V_11 , V_14 ) ;
}
}
struct V_2 * F_15 ( T_3 V_12 , T_3 type ,
T_3 V_16 , T_3 V_17 , T_1 V_14 ,
T_1 V_18 , T_1 V_19 , T_1 V_20 , int V_21 )
{
struct V_10 * V_22 ;
struct V_2 * V_23 ;
V_23 = F_2 ( V_16 + V_17 , V_24 ) ;
if ( F_16 ( ! V_23 ) )
return NULL ;
V_22 = F_17 ( V_23 ) ;
F_6 ( V_18 , V_22 , V_12 , type , V_16 , V_14 ) ;
F_10 ( V_22 , V_16 + V_17 ) ;
F_18 ( V_22 , V_20 ) ;
F_19 ( V_22 , V_19 ) ;
F_20 ( V_22 , V_21 ) ;
if ( V_16 > V_15 ) {
F_13 ( V_22 , V_18 ) ;
F_14 ( V_22 , V_14 ) ;
}
return V_23 ;
}
int F_21 ( struct V_2 * * V_25 , struct V_2 * * V_23 )
{
struct V_2 * V_26 = * V_25 ;
struct V_2 * V_27 = * V_23 ;
struct V_2 * V_28 = NULL ;
struct V_10 * V_22 ;
T_1 V_29 ;
int V_30 ;
bool V_31 ;
if ( ! V_27 )
goto V_32;
V_22 = F_17 ( V_27 ) ;
V_29 = F_22 ( V_22 ) ;
V_27 -> V_8 = NULL ;
F_23 ( V_27 , F_24 ( V_22 ) ) ;
if ( V_29 == V_33 ) {
if ( F_16 ( V_26 ) )
goto V_32;
if ( F_16 ( F_25 ( V_27 , V_24 ) ) )
goto V_32;
V_26 = * V_25 = V_27 ;
* V_23 = NULL ;
F_26 ( V_26 ) -> V_28 = NULL ;
if ( F_27 ( V_26 ) ) {
F_28 (head, tail) {
F_26 ( V_26 ) -> V_28 = V_28 ;
}
} else {
F_29 ( V_26 ) ;
}
return 0 ;
}
if ( ! V_26 )
goto V_32;
if ( F_30 ( V_26 , V_27 , & V_31 , & V_30 ) ) {
F_31 ( V_27 , V_31 ) ;
} else {
V_28 = F_26 ( V_26 ) -> V_28 ;
if ( ! F_32 ( V_26 ) )
F_33 ( V_26 ) -> V_34 = V_27 ;
else
V_28 -> V_8 = V_27 ;
V_26 -> V_35 += V_27 -> V_35 ;
V_26 -> V_36 += V_27 -> V_37 ;
V_26 -> V_37 += V_27 -> V_37 ;
F_26 ( V_26 ) -> V_28 = V_27 ;
}
if ( V_29 == V_38 ) {
F_26 ( V_26 ) -> V_39 = false ;
if ( F_16 ( ! F_34 ( V_26 ) ) )
goto V_32;
* V_23 = V_26 ;
F_26 ( V_26 ) -> V_28 = NULL ;
* V_25 = NULL ;
return 1 ;
}
* V_23 = NULL ;
return 0 ;
V_32:
F_35 ( * V_23 ) ;
F_35 ( * V_25 ) ;
* V_23 = * V_25 = NULL ;
return 0 ;
}
bool F_34 ( struct V_2 * V_5 )
{
struct V_10 * V_22 ;
int V_40 , V_41 ;
if ( F_16 ( F_26 ( V_5 ) -> V_39 ) )
return true ;
if ( F_16 ( ! F_36 ( V_5 , V_42 ) ) )
return false ;
V_41 = F_24 ( F_17 ( V_5 ) ) ;
if ( F_16 ( V_41 < V_42 ) || ( V_41 > V_43 ) )
return false ;
if ( F_16 ( ! F_36 ( V_5 , V_41 ) ) )
return false ;
V_22 = F_17 ( V_5 ) ;
if ( F_16 ( F_37 ( V_22 ) != V_44 ) )
return false ;
V_40 = F_38 ( V_22 ) ;
if ( F_16 ( V_40 < V_41 ) )
return false ;
if ( F_16 ( ( V_40 - V_41 ) > V_45 ) )
return false ;
if ( F_16 ( V_5 -> V_37 < V_40 ) )
return false ;
F_26 ( V_5 ) -> V_39 = true ;
return true ;
}
int F_39 ( struct V_10 * V_46 , struct V_47 * V_11 ,
int V_48 , int V_49 , int V_50 , struct V_51 * V_52 )
{
int V_53 = F_24 ( V_46 ) ;
int V_40 = V_53 + V_49 ;
int V_54 = 1 ;
int V_55 ;
int V_56 = V_50 ;
int V_57 = V_49 ;
struct V_10 V_58 ;
struct V_2 * V_5 ;
char * V_59 ;
int V_60 ;
F_10 ( V_46 , V_40 ) ;
if ( F_40 ( V_40 <= V_50 ) ) {
V_5 = F_2 ( V_40 , V_61 ) ;
if ( F_16 ( ! V_5 ) )
return - V_62 ;
F_41 ( V_5 ) ;
F_42 ( V_52 , V_5 ) ;
F_43 ( V_5 , V_46 , V_53 ) ;
V_59 = V_5 -> V_63 + V_53 ;
if ( F_44 ( V_59 , V_49 , & V_11 -> V_64 ) )
return V_49 ;
V_60 = - V_65 ;
goto error;
}
F_6 ( F_45 ( V_46 ) , & V_58 , V_66 ,
V_33 , V_67 , F_46 ( V_46 ) ) ;
F_10 ( & V_58 , V_50 ) ;
F_47 ( & V_58 , V_54 ) ;
F_48 ( & V_58 , F_49 ( V_46 ) ) ;
V_5 = F_2 ( V_50 , V_61 ) ;
if ( ! V_5 )
return - V_62 ;
F_41 ( V_5 ) ;
F_42 ( V_52 , V_5 ) ;
V_59 = V_5 -> V_63 ;
F_43 ( V_5 , & V_58 , V_67 ) ;
V_59 += V_67 ;
V_56 -= V_67 ;
F_50 ( V_5 , V_67 , V_46 , V_53 ) ;
V_59 += V_53 ;
V_56 -= V_53 ;
do {
if ( V_57 < V_56 )
V_56 = V_57 ;
if ( ! F_44 ( V_59 , V_56 , & V_11 -> V_64 ) ) {
V_60 = - V_65 ;
goto error;
}
V_57 -= V_56 ;
if ( ! V_57 )
break;
if ( V_57 < ( V_50 - V_67 ) )
V_55 = V_57 + V_67 ;
else
V_55 = V_50 ;
V_5 = F_2 ( V_55 , V_61 ) ;
if ( ! V_5 ) {
V_60 = - V_62 ;
goto error;
}
F_41 ( V_5 ) ;
F_42 ( V_52 , V_5 ) ;
F_12 ( & V_58 , V_68 ) ;
F_10 ( & V_58 , V_55 ) ;
F_47 ( & V_58 , ++ V_54 ) ;
F_43 ( V_5 , & V_58 , V_67 ) ;
V_59 = V_5 -> V_63 + V_67 ;
V_56 = V_55 - V_67 ;
} while ( 1 );
F_12 ( F_17 ( V_5 ) , V_38 ) ;
return V_49 ;
error:
F_51 ( V_52 ) ;
F_52 ( V_52 ) ;
return V_60 ;
}
bool F_53 ( struct V_2 * V_5 , struct V_10 * V_22 , T_1 V_69 )
{
struct V_10 * V_70 ;
unsigned int V_71 ;
unsigned int V_40 = F_38 ( V_22 ) ;
T_1 V_72 , V_73 ;
T_1 V_74 = V_69 - V_67 ;
if ( F_40 ( F_54 ( V_22 ) == V_66 ) )
return false ;
if ( ! V_5 )
return false ;
V_70 = F_17 ( V_5 ) ;
V_71 = F_38 ( V_70 ) ;
V_72 = F_1 ( V_71 ) ;
V_73 = V_72 - V_71 ;
if ( F_16 ( F_54 ( V_22 ) == V_75 ) )
return false ;
if ( F_16 ( F_54 ( V_22 ) == V_76 ) )
return false ;
if ( F_16 ( F_54 ( V_70 ) != V_77 ) )
return false ;
if ( F_16 ( F_55 ( V_5 ) < ( V_73 + V_40 ) ) )
return false ;
if ( F_16 ( V_74 < ( V_72 + V_40 ) ) )
return false ;
if ( ( F_49 ( V_22 ) < V_78 ) &&
( F_49 ( V_70 ) == V_78 ) )
return false ;
F_5 ( V_5 , V_73 + V_40 ) ;
F_50 ( V_5 , V_72 , V_22 , V_40 ) ;
F_10 ( V_70 , V_72 + V_40 ) ;
F_56 ( V_70 , F_57 ( V_70 ) + 1 ) ;
return true ;
}
bool F_58 ( struct V_2 * V_5 , struct V_2 * * V_79 , int * V_80 )
{
struct V_10 * V_22 ;
int V_81 , V_48 ;
* V_79 = NULL ;
if ( F_16 ( F_59 ( V_5 ) ) )
goto V_82;
V_22 = F_17 ( V_5 ) ;
V_48 = F_24 ( V_22 ) + * V_80 ;
if ( F_16 ( V_48 > ( F_38 ( V_22 ) - V_42 ) ) )
goto V_82;
* V_79 = F_60 ( V_5 , V_24 ) ;
if ( F_16 ( ! * V_79 ) )
goto V_82;
F_23 ( * V_79 , V_48 ) ;
V_81 = F_38 ( F_17 ( * V_79 ) ) ;
F_61 ( * V_79 , V_81 ) ;
if ( F_16 ( ! F_34 ( * V_79 ) ) )
goto V_82;
* V_80 += F_1 ( V_81 ) ;
return true ;
V_82:
F_35 ( V_5 ) ;
F_35 ( * V_79 ) ;
* V_79 = NULL ;
return false ;
}
bool F_62 ( struct V_2 * * V_5 , struct V_10 * V_22 ,
T_1 V_69 , T_1 V_14 )
{
struct V_2 * V_83 ;
struct V_10 * V_70 ;
T_1 V_40 = F_38 ( V_22 ) ;
T_1 V_74 = V_69 - V_67 ;
if ( F_54 ( V_22 ) == V_66 )
return false ;
if ( F_54 ( V_22 ) == V_75 )
return false ;
if ( F_54 ( V_22 ) == V_76 )
return false ;
if ( V_40 > ( V_74 / 2 ) )
return false ;
V_83 = F_2 ( V_74 , V_24 ) ;
if ( ! V_83 )
return false ;
F_61 ( V_83 , V_67 ) ;
V_70 = F_17 ( V_83 ) ;
F_6 ( F_45 ( V_22 ) , V_70 , V_77 , 0 ,
V_67 , V_14 ) ;
if ( F_63 ( V_22 ) )
F_48 ( V_70 , V_84 ) ;
else
F_48 ( V_70 , V_78 ) ;
F_64 ( V_70 , F_65 ( V_22 ) ) ;
F_66 ( V_70 , F_67 ( V_22 ) ) ;
F_68 ( V_70 , F_69 ( V_22 ) ) ;
F_53 ( V_83 , V_22 , V_69 ) ;
* V_5 = V_83 ;
return true ;
}
bool F_70 ( T_1 V_9 , struct V_2 * * V_5 , int V_32 )
{
struct V_2 * V_83 = * V_5 ;
struct V_10 * V_85 ;
struct V_10 V_86 ;
int V_87 ;
if ( F_59 ( V_83 ) )
goto exit;
V_85 = F_17 ( V_83 ) ;
V_87 = F_71 ( T_3 , F_72 ( V_85 ) , V_88 ) ;
if ( F_73 ( V_85 ) )
goto exit;
if ( F_74 ( V_85 ) )
goto exit;
memcpy ( & V_86 , V_85 , F_24 ( V_85 ) ) ;
if ( F_75 ( V_85 ) ) {
* V_5 = F_2 ( V_89 + V_87 , V_24 ) ;
if ( ! * V_5 )
goto exit;
memcpy ( ( * V_5 ) -> V_63 + V_89 , F_76 ( V_85 ) , V_87 ) ;
F_35 ( V_83 ) ;
V_83 = * V_5 ;
V_85 = F_17 ( V_83 ) ;
memcpy ( V_85 , & V_86 , V_89 ) ;
F_9 ( V_85 , V_89 ) ;
}
if ( F_77 ( V_83 ) &&
F_78 ( V_83 , V_7 , V_90 , V_24 ) )
goto exit;
V_85 = F_17 ( V_83 ) ;
F_20 ( V_85 , V_32 ) ;
F_79 ( V_85 , 0 ) ;
F_18 ( V_85 , F_80 ( & V_86 ) ) ;
F_19 ( V_85 , F_81 ( & V_86 ) ) ;
F_14 ( V_85 , F_45 ( & V_86 ) ) ;
F_11 ( V_85 , V_9 ) ;
F_13 ( V_85 , V_9 ) ;
F_10 ( V_85 , F_24 ( V_85 ) + V_87 ) ;
F_61 ( V_83 , F_38 ( V_85 ) ) ;
F_41 ( V_83 ) ;
return true ;
exit:
F_35 ( V_83 ) ;
* V_5 = NULL ;
return false ;
}
bool F_82 ( struct V_91 * V_91 , struct V_2 * V_5 , int * V_32 )
{
struct V_10 * V_22 = F_17 ( V_5 ) ;
T_1 V_19 , V_14 ;
T_1 V_18 = F_83 ( V_91 ) ;
if ( ! F_63 ( V_22 ) )
return false ;
if ( ! F_84 ( V_22 ) )
return false ;
if ( F_74 ( V_22 ) )
return false ;
* V_32 = V_92 ;
if ( F_59 ( V_5 ) )
return false ;
V_22 = F_17 ( V_5 ) ;
if ( F_85 ( V_22 ) )
return false ;
V_14 = F_86 ( V_91 , F_87 ( V_22 ) ) ;
V_19 = F_88 ( V_91 , F_89 ( V_22 ) ,
F_90 ( V_22 ) , & V_14 ) ;
if ( ! V_19 )
return false ;
F_91 ( V_22 ) ;
if ( V_14 != V_18 )
F_11 ( V_22 , V_18 ) ;
F_14 ( V_22 , V_14 ) ;
F_19 ( V_22 , V_19 ) ;
* V_32 = V_93 ;
if ( ! F_77 ( V_5 ) )
return true ;
if ( F_78 ( V_5 , V_7 , V_90 , V_24 ) )
return false ;
return true ;
}
bool F_92 ( struct V_51 * V_52 , struct V_51 * V_94 )
{
struct V_2 * V_5 , * V_83 ;
struct V_2 * V_27 = NULL ;
struct V_2 * V_26 = NULL ;
int V_95 ;
if ( F_93 ( V_52 ) == 1 ) {
V_5 = F_94 ( V_52 ) ;
V_95 = F_95 ( V_5 ) + F_24 ( F_17 ( V_5 ) ) ;
V_83 = F_96 ( V_5 , V_95 , V_24 ) ;
if ( ! V_83 )
return false ;
F_42 ( V_94 , V_83 ) ;
return true ;
}
F_97 (list, skb) {
V_27 = F_60 ( V_5 , V_24 ) ;
if ( ! V_27 )
goto error;
V_27 -> V_8 = NULL ;
if ( F_21 ( & V_26 , & V_27 ) )
break;
if ( ! V_26 )
goto error;
}
F_42 ( V_94 , V_27 ) ;
return true ;
error:
F_98 ( L_1 ) ;
F_35 ( V_26 ) ;
return false ;
}
bool F_99 ( T_1 V_96 , struct V_51 * V_22 ,
struct V_51 * V_97 )
{
struct V_2 * V_5 , * V_83 ;
F_97 (msg, skb) {
V_83 = F_100 ( V_5 , V_24 ) ;
if ( ! V_83 ) {
F_51 ( V_97 ) ;
return false ;
}
F_14 ( F_17 ( V_83 ) , V_96 ) ;
F_42 ( V_97 , V_83 ) ;
}
return true ;
}
void F_101 ( struct V_51 * V_52 , T_4 V_98 ,
struct V_2 * V_5 )
{
struct V_2 * V_83 , * V_99 ;
if ( F_102 ( V_52 ) || F_103 ( V_98 , F_104 ( F_94 ( V_52 ) ) ) ) {
F_105 ( V_52 , V_5 ) ;
return;
}
if ( F_106 ( V_98 , F_104 ( F_107 ( V_52 ) ) ) ) {
F_42 ( V_52 , V_5 ) ;
return;
}
F_108 (list, _skb, tmp) {
if ( F_106 ( V_98 , F_104 ( V_83 ) ) )
continue;
if ( V_98 == F_104 ( V_83 ) )
break;
F_109 ( V_52 , V_83 , V_5 ) ;
return;
}
F_35 ( V_5 ) ;
}
