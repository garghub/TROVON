static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( ! F_2 ( V_2 ) || F_3 ( V_2 , V_3 ) )
return 0 ;
return F_4 ( V_2 , 0 , 0 , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_5 )
{
struct V_6 * V_7 ;
int V_8 ;
V_8 = F_1 ( V_2 , V_9 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
if ( V_2 -> V_10 == V_11 )
V_2 -> V_12 = F_7 ( V_2 -> V_12 , F_8 ( V_2 -> V_13
+ V_14 , V_15 , 0 ) ) ;
V_7 = (struct V_6 * ) ( V_2 -> V_13 + V_14 ) ;
* V_5 = V_7 -> V_16 ;
memmove ( V_2 -> V_13 + V_15 , V_2 -> V_13 , 2 * V_17 ) ;
F_9 ( V_2 , V_15 ) ;
F_10 ( V_2 , V_7 ) ;
V_2 -> V_18 += V_15 ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_19 ;
int V_8 ;
if ( F_13 ( F_14 ( V_2 ) ) ) {
V_2 -> V_20 = 0 ;
} else {
if ( F_6 ( V_2 -> V_21 != F_15 ( V_22 ) ||
V_2 -> V_23 < V_9 ) )
return 0 ;
V_8 = F_5 ( V_2 , & V_19 ) ;
if ( V_8 )
return V_8 ;
}
if ( F_13 ( V_2 -> V_21 != F_15 ( V_22 ) ||
V_2 -> V_23 < V_9 ) )
return 0 ;
V_8 = F_5 ( V_2 , & V_19 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
F_16 ( V_2 , F_17 ( V_19 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
if ( F_6 ( F_14 ( V_2 ) ) ) {
T_2 V_26 ;
V_26 = F_19 ( V_2 ) ;
if ( ! F_20 ( V_2 , V_26 ) )
return - V_27 ;
if ( V_2 -> V_10 == V_11 )
V_2 -> V_12 = F_21 ( V_2 -> V_12 , F_8 ( V_2 -> V_13
+ V_14 , V_15 , 0 ) ) ;
}
F_16 ( V_2 , F_17 ( V_25 -> V_20 ) & ~ V_28 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
const struct V_29 * V_30 )
{
int V_8 ;
V_8 = F_1 ( V_2 , V_14 ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
memcpy ( F_23 ( V_2 ) -> V_31 , V_30 -> V_32 , V_17 ) ;
memcpy ( F_23 ( V_2 ) -> V_33 , V_30 -> V_34 , V_17 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_3 * V_37 , T_3 V_38 )
{
int V_39 = V_2 -> V_23 - F_25 ( V_2 ) ;
if ( V_36 -> V_21 == V_40 ) {
if ( F_13 ( V_39 >= sizeof( struct V_41 ) ) )
F_26 ( & F_27 ( V_2 ) -> V_42 , V_2 ,
* V_37 , V_38 , 1 ) ;
} else if ( V_36 -> V_21 == V_43 ) {
if ( F_13 ( V_39 >= sizeof( struct V_44 ) ) ) {
struct V_44 * V_45 = F_28 ( V_2 ) ;
if ( V_45 -> V_42 || V_2 -> V_10 == V_46 ) {
F_26 ( & V_45 -> V_42 , V_2 ,
* V_37 , V_38 , 1 ) ;
if ( ! V_45 -> V_42 )
V_45 -> V_42 = V_47 ;
}
}
}
F_29 ( & V_36 -> V_42 , * V_37 , V_38 ) ;
V_2 -> V_48 = 0 ;
* V_37 = V_38 ;
}
static void F_30 ( struct V_1 * V_2 , struct V_35 * V_36 , T_4 V_49 )
{
F_31 ( & V_36 -> V_42 , F_15 ( V_36 -> V_50 << 8 ) , F_15 ( V_49 << 8 ) ) ;
V_36 -> V_50 = V_49 ;
}
static int F_32 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_35 * V_36 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_33 ( V_2 ) +
sizeof( struct V_35 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_36 = F_34 ( V_2 ) ;
if ( V_52 -> V_53 != V_36 -> V_54 )
F_24 ( V_2 , V_36 , & V_36 -> V_54 , V_52 -> V_53 ) ;
if ( V_52 -> V_55 != V_36 -> V_56 )
F_24 ( V_2 , V_36 , & V_36 -> V_56 , V_52 -> V_55 ) ;
if ( V_52 -> V_57 != V_36 -> V_58 )
F_35 ( V_36 , 0 , V_52 -> V_57 ) ;
if ( V_52 -> V_59 != V_36 -> V_50 )
F_30 ( V_2 , V_36 , V_52 -> V_59 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 , T_1 * V_60 ,
T_1 V_61 , T_5 * V_42 )
{
F_37 ( V_42 , V_2 , * V_60 , V_61 , 0 ) ;
* V_60 = V_61 ;
V_2 -> V_48 = 0 ;
}
static void F_38 ( struct V_1 * V_2 , T_1 * V_60 , T_1 V_61 )
{
struct V_44 * V_45 = F_28 ( V_2 ) ;
if ( V_45 -> V_42 && V_2 -> V_10 != V_46 ) {
F_36 ( V_2 , V_60 , V_61 , & V_45 -> V_42 ) ;
if ( ! V_45 -> V_42 )
V_45 -> V_42 = V_47 ;
} else {
* V_60 = V_61 ;
V_2 -> V_48 = 0 ;
}
}
static int F_39 ( struct V_1 * V_2 , const struct V_62 * V_63 )
{
struct V_44 * V_45 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_44 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_45 = F_28 ( V_2 ) ;
if ( V_63 -> V_64 != V_45 -> V_65 )
F_38 ( V_2 , & V_45 -> V_65 , V_63 -> V_64 ) ;
if ( V_63 -> V_66 != V_45 -> V_67 )
F_38 ( V_2 , & V_45 -> V_67 , V_63 -> V_66 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const struct V_68 * V_69 )
{
struct V_41 * V_70 ;
int V_8 ;
V_8 = F_1 ( V_2 , F_25 ( V_2 ) +
sizeof( struct V_41 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
V_70 = F_27 ( V_2 ) ;
if ( V_69 -> V_71 != V_70 -> V_65 )
F_36 ( V_2 , & V_70 -> V_65 , V_69 -> V_71 , & V_70 -> V_42 ) ;
if ( V_69 -> V_72 != V_70 -> V_67 )
F_36 ( V_2 , & V_70 -> V_67 , V_69 -> V_72 , & V_70 -> V_42 ) ;
return 0 ;
}
static int F_41 ( struct V_73 * V_74 , struct V_1 * V_2 , int V_75 )
{
struct V_76 * V_76 ;
if ( F_6 ( ! V_2 ) )
return - V_27 ;
V_76 = F_42 ( V_74 -> V_77 [ V_75 ] ) ;
if ( F_6 ( ! V_76 ) ) {
F_43 ( V_2 ) ;
return - V_78 ;
}
F_44 ( V_76 , V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_73 * V_74 , struct V_1 * V_2 ,
const struct V_79 * V_80 )
{
struct V_81 V_82 ;
const struct V_79 * V_83 ;
int V_84 ;
V_82 . V_85 = V_86 ;
V_82 . V_87 = & F_46 ( V_2 ) -> V_88 -> V_87 ;
V_82 . V_89 = NULL ;
V_82 . V_90 = 0 ;
for ( V_83 = F_47 ( V_80 ) , V_84 = F_48 ( V_80 ) ; V_84 > 0 ;
V_83 = F_49 ( V_83 , & V_84 ) ) {
switch ( F_50 ( V_83 ) ) {
case V_91 :
V_82 . V_89 = V_83 ;
break;
case V_92 :
V_82 . V_90 = F_51 ( V_83 ) ;
break;
}
}
return F_52 ( V_74 , V_2 , & V_82 ) ;
}
static int F_53 ( struct V_73 * V_74 , struct V_1 * V_2 ,
const struct V_79 * V_80 )
{
const struct V_79 * V_93 = NULL ;
const struct V_79 * V_83 ;
int V_84 ;
for ( V_83 = F_47 ( V_80 ) , V_84 = F_48 ( V_80 ) ; V_84 > 0 ;
V_83 = F_49 ( V_83 , & V_84 ) ) {
switch ( F_50 ( V_83 ) ) {
case V_94 :
if ( F_54 () >= F_51 ( V_83 ) )
return 0 ;
break;
case V_95 :
V_93 = V_83 ;
break;
}
}
return F_55 ( V_74 , V_2 , F_47 ( V_93 ) ,
F_48 ( V_93 ) , true ) ;
}
static int F_56 ( struct V_1 * V_2 ,
const struct V_79 * V_96 )
{
int V_8 = 0 ;
switch ( F_50 ( V_96 ) ) {
case V_97 :
V_2 -> V_98 = F_51 ( V_96 ) ;
break;
case V_99 :
V_8 = F_22 ( V_2 , F_47 ( V_96 ) ) ;
break;
case V_100 :
V_8 = F_32 ( V_2 , F_47 ( V_96 ) ) ;
break;
case V_101 :
V_8 = F_40 ( V_2 , F_47 ( V_96 ) ) ;
break;
case V_102 :
V_8 = F_39 ( V_2 , F_47 ( V_96 ) ) ;
break;
}
return V_8 ;
}
static int F_55 ( struct V_73 * V_74 , struct V_1 * V_2 ,
const struct V_79 * V_80 , int V_23 , bool V_103 )
{
int V_104 = - 1 ;
const struct V_79 * V_83 ;
int V_84 ;
for ( V_83 = V_80 , V_84 = V_23 ; V_84 > 0 ;
V_83 = F_49 ( V_83 , & V_84 ) ) {
int V_8 = 0 ;
if ( V_104 != - 1 ) {
F_41 ( V_74 , F_57 ( V_2 , V_4 ) , V_104 ) ;
V_104 = - 1 ;
}
switch ( F_50 ( V_83 ) ) {
case V_105 :
V_104 = F_51 ( V_83 ) ;
break;
case V_106 :
F_45 ( V_74 , V_2 , V_83 ) ;
break;
case V_107 :
V_8 = F_18 ( V_2 , F_47 ( V_83 ) ) ;
if ( F_6 ( V_8 ) )
return V_8 ;
break;
case V_108 :
V_8 = F_12 ( V_2 ) ;
break;
case V_109 :
V_8 = F_56 ( V_2 , F_47 ( V_83 ) ) ;
break;
case V_110 :
V_8 = F_53 ( V_74 , V_2 , V_83 ) ;
break;
}
if ( F_6 ( V_8 ) ) {
F_43 ( V_2 ) ;
return V_8 ;
}
}
if ( V_104 != - 1 ) {
if ( V_103 )
V_2 = F_57 ( V_2 , V_4 ) ;
F_41 ( V_74 , V_2 , V_104 ) ;
} else if ( ! V_103 )
F_58 ( V_2 ) ;
return 0 ;
}
int F_59 ( struct V_73 * V_74 , struct V_1 * V_2 )
{
struct V_111 * V_112 = F_42 ( F_46 ( V_2 ) -> V_88 -> V_113 ) ;
return F_55 ( V_74 , V_2 , V_112 -> V_114 ,
V_112 -> V_115 , false ) ;
}
