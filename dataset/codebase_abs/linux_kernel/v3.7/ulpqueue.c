struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_4 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = 0 ;
return V_2 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
while ( ( V_10 = F_4 ( & V_2 -> V_6 ) ) != NULL ) {
V_12 = F_5 ( V_10 ) ;
F_6 ( V_12 ) ;
}
while ( ( V_10 = F_4 ( & V_2 -> V_5 ) ) != NULL ) {
V_12 = F_5 ( V_10 ) ;
F_6 ( V_12 ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
if ( V_2 -> V_8 )
F_8 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_13 * V_14 ,
T_1 V_15 )
{
struct V_16 V_17 ;
struct V_11 * V_12 ;
V_12 = F_10 ( V_14 -> V_4 , V_14 , V_15 ) ;
if ( ! V_12 )
return - V_18 ;
V_12 = F_11 ( V_2 , V_12 ) ;
if ( ( V_12 ) && ( V_12 -> V_19 & V_20 ) ) {
F_2 ( & V_17 ) ;
F_12 ( & V_17 , F_13 ( V_12 ) ) ;
V_12 = F_14 ( V_2 , V_12 ) ;
}
if ( V_12 )
F_15 ( V_2 , V_12 ) ;
return 0 ;
}
int F_16 ( struct V_21 * V_22 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_17 ( V_22 ) ;
if ( F_18 ( & V_24 -> V_7 ) ) {
if ( ! F_19 ( & V_24 -> V_25 ) ) {
struct V_26 * V_27 ;
F_20 ( & V_24 -> V_25 , & V_22 -> V_28 ) ;
V_27 = (struct V_26 * ) & F_17 ( V_22 ) -> V_25 ;
F_21 ( V_27 ) ;
return 1 ;
}
} else {
if ( ! F_19 ( & V_24 -> V_25 ) && V_4 ) {
struct V_9 * V_10 , * V_29 ;
struct V_11 * V_12 ;
F_22 (skb, &sp->pd_lobby, tmp) {
V_12 = F_5 ( V_10 ) ;
if ( V_12 -> V_4 == V_4 ) {
F_23 ( V_10 , & V_24 -> V_25 ) ;
F_12 ( & V_22 -> V_28 ,
V_10 ) ;
}
}
}
}
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_17 ( V_2 -> V_4 -> V_30 . V_22 ) ;
F_25 ( & V_24 -> V_7 ) ;
V_2 -> V_7 = 1 ;
}
static int F_26 ( struct V_1 * V_2 )
{
V_2 -> V_7 = 0 ;
F_27 ( V_2 ) ;
return F_16 ( V_2 -> V_4 -> V_30 . V_22 , V_2 -> V_4 ) ;
}
int F_15 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_21 * V_22 = V_2 -> V_4 -> V_30 . V_22 ;
struct V_16 * V_31 , * V_32 ;
struct V_9 * V_10 = F_13 ( V_12 ) ;
int V_33 = 0 ;
V_32 = (struct V_16 * ) V_10 -> V_34 ;
if ( F_28 ( V_22 , V_35 ) || ( V_22 -> V_36 & V_37 ) )
goto V_38;
if ( ! F_29 ( V_12 , & F_17 ( V_22 ) -> V_39 ) )
goto V_38;
if ( F_30 ( & F_17 ( V_22 ) -> V_7 ) == 0 ) {
V_31 = & V_22 -> V_28 ;
} else {
if ( V_2 -> V_7 ) {
if ( ( V_12 -> V_19 & V_40 ) ||
( V_41 ==
( V_12 -> V_19 & V_42 ) ) )
V_31 = & F_17 ( V_22 ) -> V_25 ;
else {
V_33 = V_12 -> V_19 & V_20 ;
V_31 = & V_22 -> V_28 ;
}
} else {
if ( F_17 ( V_22 ) -> V_43 )
V_31 = & V_22 -> V_28 ;
else
V_31 = & F_17 ( V_22 ) -> V_25 ;
}
}
if ( V_32 )
F_20 ( V_32 , V_31 ) ;
else
F_12 ( V_31 , V_10 ) ;
if ( V_33 )
F_26 ( V_2 ) ;
if ( V_31 == & V_22 -> V_28 )
V_22 -> V_44 ( V_22 , 0 ) ;
return 1 ;
V_38:
if ( V_32 )
F_31 ( V_32 ) ;
else
F_6 ( V_12 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_9 * V_45 ;
struct V_11 * V_46 ;
T_2 V_47 , V_48 ;
V_47 = V_12 -> V_47 ;
V_45 = F_33 ( & V_2 -> V_5 ) ;
if ( ! V_45 ) {
F_12 ( & V_2 -> V_5 , F_13 ( V_12 ) ) ;
return;
}
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
if ( F_34 ( V_48 , V_47 ) ) {
F_12 ( & V_2 -> V_5 , F_13 ( V_12 ) ) ;
return;
}
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
if ( F_34 ( V_47 , V_48 ) )
break;
}
F_36 ( & V_2 -> V_5 , V_45 , F_13 ( V_12 ) ) ;
}
static struct V_11 * F_37 ( struct V_49 * V_49 ,
struct V_16 * V_31 , struct V_9 * V_50 ,
struct V_9 * V_51 )
{
struct V_9 * V_45 ;
struct V_9 * V_52 = NULL ;
struct V_11 * V_12 ;
struct V_9 * V_53 , * V_54 ;
struct V_9 * V_27 = F_38 ( V_50 ) -> V_55 ;
if ( V_50 == V_51 )
V_45 = NULL ;
else
V_45 = V_50 -> V_56 ;
for ( V_54 = V_27 ; V_27 ; V_54 = V_27 , V_27 = V_27 -> V_56 ) ;
if ( V_54 )
V_54 -> V_56 = V_45 ;
else {
if ( F_39 ( V_50 ) ) {
V_52 = F_40 ( V_50 , V_57 ) ;
if ( ! V_52 )
return NULL ;
F_41 ( V_52 , V_50 -> V_22 ) ;
F_38 ( V_52 ) -> V_55 = V_45 ;
} else
F_38 ( V_50 ) -> V_55 = V_45 ;
}
F_23 ( V_50 , V_31 ) ;
if ( V_52 ) {
F_42 ( V_50 ) ;
V_50 = V_52 ;
}
while ( V_45 ) {
V_53 = V_45 -> V_56 ;
V_50 -> V_58 += V_45 -> V_58 ;
V_50 -> V_59 += V_45 -> V_58 ;
F_23 ( V_45 , V_31 ) ;
if ( V_45 == V_51 )
break;
V_45 -> V_56 = V_53 ;
V_45 = V_53 ;
}
V_12 = F_5 ( V_50 ) ;
F_43 ( V_49 , V_60 ) ;
return V_12 ;
}
static struct V_11 * F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_45 ;
struct V_11 * V_46 ;
struct V_9 * V_61 = NULL ;
T_2 V_48 , V_62 ;
struct V_11 * V_63 = NULL ;
struct V_9 * V_64 = NULL ;
struct V_9 * V_65 = NULL ;
T_3 V_66 = 0 ;
struct V_3 * V_4 ;
T_4 V_67 ;
V_62 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_68 :
if ( V_45 == V_2 -> V_5 . V_56 ) {
V_64 = V_45 ;
V_65 = V_45 ;
V_66 = V_45 -> V_58 ;
} else {
V_64 = NULL ;
V_65 = NULL ;
V_66 = 0 ;
}
V_61 = V_45 ;
V_62 = V_48 + 1 ;
break;
case V_69 :
if ( ( V_61 ) && ( V_48 == V_62 ) ) {
V_62 ++ ;
if ( V_64 ) {
V_65 = V_45 ;
V_66 += V_45 -> V_58 ;
}
} else
V_61 = NULL ;
break;
case V_70 :
if ( V_61 && ( V_48 == V_62 ) )
goto V_71;
else
V_61 = NULL ;
break;
}
}
V_4 = V_2 -> V_4 ;
if ( V_64 ) {
if ( ! F_17 ( V_4 -> V_30 . V_22 ) -> V_43 &&
F_30 ( & F_17 ( V_4 -> V_30 . V_22 ) -> V_7 ) )
goto V_72;
V_46 = F_5 ( V_64 ) ;
V_67 = F_17 ( V_4 -> V_30 . V_22 ) -> V_67 ;
if ( V_67 && V_67 <= V_66 ) {
V_63 = F_37 ( F_45 ( V_4 -> V_30 . V_22 ) ,
& V_2 -> V_5 ,
V_64 ,
V_65 ) ;
if ( V_63 )
F_24 ( V_2 ) ;
}
}
V_72:
return V_63 ;
V_71:
V_63 = F_37 ( F_45 ( V_2 -> V_4 -> V_30 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_45 ) ;
if ( V_63 )
V_63 -> V_19 |= V_20 ;
goto V_72;
}
static struct V_11 * F_46 ( struct V_1 * V_2 )
{
struct V_9 * V_45 , * V_73 , * V_61 ;
struct V_11 * V_46 ;
T_2 V_48 , V_62 ;
int V_74 ;
struct V_11 * V_63 ;
if ( F_19 ( & V_2 -> V_5 ) )
return NULL ;
V_73 = V_61 = NULL ;
V_63 = NULL ;
V_62 = 0 ;
V_74 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_69 :
if ( ! V_61 ) {
V_61 = V_45 ;
V_62 = V_48 + 1 ;
V_73 = V_45 ;
} else if ( V_62 == V_48 )
V_62 ++ ;
else
goto V_72;
break;
case V_70 :
if ( ! V_61 )
V_61 = V_45 ;
else if ( V_48 != V_62 )
goto V_72;
V_73 = V_45 ;
V_74 = 1 ;
goto V_72;
default:
return NULL ;
}
}
V_72:
V_63 = F_37 ( F_45 ( V_2 -> V_4 -> V_30 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_73 ) ;
if ( V_63 && V_74 )
V_63 -> V_19 |= V_20 ;
return V_63 ;
}
static struct V_11 * F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_63 = NULL ;
if ( V_41 == ( V_12 -> V_19 & V_42 ) ) {
V_12 -> V_19 |= V_20 ;
return V_12 ;
}
F_32 ( V_2 , V_12 ) ;
if ( ! V_2 -> V_7 )
V_63 = F_44 ( V_2 ) ;
else {
T_2 V_48 , V_75 ;
V_48 = V_12 -> V_47 ;
V_75 = F_47 ( & V_2 -> V_4 -> V_76 . V_77 ) ;
if ( F_48 ( V_48 , V_75 ) )
V_63 = F_46 ( V_2 ) ;
}
return V_63 ;
}
static struct V_11 * F_49 ( struct V_1 * V_2 )
{
struct V_9 * V_45 , * V_73 , * V_61 ;
struct V_11 * V_46 ;
T_2 V_48 , V_62 ;
struct V_11 * V_63 ;
if ( F_19 ( & V_2 -> V_5 ) )
return NULL ;
V_73 = V_61 = NULL ;
V_63 = NULL ;
V_62 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_68 :
if ( ! V_61 ) {
V_61 = V_45 ;
V_62 = V_48 + 1 ;
V_73 = V_45 ;
} else
goto V_72;
break;
case V_69 :
if ( ! V_61 )
return NULL ;
if ( V_48 == V_62 ) {
V_62 ++ ;
V_73 = V_45 ;
} else
goto V_72;
break;
default:
return NULL ;
}
}
V_72:
V_63 = F_37 ( F_45 ( V_2 -> V_4 -> V_30 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_73 ) ;
return V_63 ;
}
void F_50 ( struct V_1 * V_2 , T_2 V_78 )
{
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_12 ;
T_2 V_47 ;
if ( F_19 ( & V_2 -> V_5 ) )
return;
F_51 (&ulpq->reasm, pos, tmp) {
V_12 = F_5 ( V_45 ) ;
V_47 = V_12 -> V_47 ;
if ( F_48 ( V_47 , V_78 ) ) {
F_23 ( V_45 , & V_2 -> V_5 ) ;
F_6 ( V_12 ) ;
} else
break;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = NULL ;
struct V_16 V_17 ;
if ( F_19 ( & V_2 -> V_5 ) )
return;
while ( ( V_12 = F_44 ( V_2 ) ) != NULL ) {
if ( ( V_12 ) && ( V_12 -> V_19 & V_20 ) ) {
F_2 ( & V_17 ) ;
F_12 ( & V_17 , F_13 ( V_12 ) ) ;
V_12 = F_14 ( V_2 , V_12 ) ;
}
if ( V_12 )
F_15 ( V_2 , V_12 ) ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_16 * V_79 ;
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_46 ;
struct V_80 * V_81 ;
T_5 V_82 , V_83 , V_84 ;
V_82 = V_12 -> V_85 ;
V_81 = & V_2 -> V_4 -> V_86 -> V_81 ;
V_79 = (struct V_16 * ) F_13 ( V_12 ) -> V_34 ;
F_22 (pos, &ulpq->lobby, tmp) {
V_46 = (struct V_11 * ) V_45 -> V_87 ;
V_83 = V_46 -> V_85 ;
V_84 = V_46 -> V_88 ;
if ( V_83 > V_82 )
break;
if ( V_83 < V_82 )
continue;
if ( V_84 != F_53 ( V_81 , V_82 ) )
break;
F_54 ( V_81 , V_82 ) ;
F_23 ( V_45 , & V_2 -> V_6 ) ;
F_12 ( V_79 , V_45 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_9 * V_45 ;
struct V_11 * V_46 ;
T_5 V_82 , V_83 ;
T_5 V_88 , V_84 ;
V_45 = F_33 ( & V_2 -> V_6 ) ;
if ( ! V_45 ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
V_82 = V_12 -> V_85 ;
V_88 = V_12 -> V_88 ;
V_46 = (struct V_11 * ) V_45 -> V_87 ;
V_83 = V_46 -> V_85 ;
V_84 = V_46 -> V_88 ;
if ( V_82 > V_83 ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
if ( ( V_82 == V_83 ) && F_56 ( V_84 , V_88 ) ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
F_35 (&ulpq->lobby, pos) {
V_46 = (struct V_11 * ) V_45 -> V_87 ;
V_83 = V_46 -> V_85 ;
V_84 = V_46 -> V_88 ;
if ( V_83 > V_82 )
break;
if ( V_83 == V_82 && F_56 ( V_88 , V_84 ) )
break;
}
F_36 ( & V_2 -> V_6 , V_45 , F_13 ( V_12 ) ) ;
}
static struct V_11 * F_14 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_5 V_82 , V_88 ;
struct V_80 * V_81 ;
if ( V_89 & V_12 -> V_19 )
return V_12 ;
V_82 = V_12 -> V_85 ;
V_88 = V_12 -> V_88 ;
V_81 = & V_2 -> V_4 -> V_86 -> V_81 ;
if ( V_88 != F_53 ( V_81 , V_82 ) ) {
F_55 ( V_2 , V_12 ) ;
return NULL ;
}
F_54 ( V_81 , V_82 ) ;
F_52 ( V_2 , V_12 ) ;
return V_12 ;
}
static void F_57 ( struct V_1 * V_2 , T_5 V_82 )
{
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_46 ;
struct V_11 * V_12 ;
struct V_80 * V_81 ;
struct V_16 V_17 ;
struct V_16 * V_6 = & V_2 -> V_6 ;
T_5 V_83 , V_84 ;
V_81 = & V_2 -> V_4 -> V_86 -> V_81 ;
F_2 ( & V_17 ) ;
V_12 = NULL ;
F_22 (pos, lobby, tmp) {
V_46 = (struct V_11 * ) V_45 -> V_87 ;
V_83 = V_46 -> V_85 ;
V_84 = V_46 -> V_88 ;
if ( V_83 > V_82 )
break;
if ( V_83 < V_82 )
continue;
if ( ! F_56 ( V_84 , F_53 ( V_81 , V_83 ) ) )
break;
F_23 ( V_45 , V_6 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_45 ) ;
F_12 ( & V_17 , V_45 ) ;
}
if ( V_12 == NULL && V_45 != (struct V_9 * ) V_6 ) {
V_46 = (struct V_11 * ) V_45 -> V_87 ;
V_83 = V_46 -> V_85 ;
V_84 = V_46 -> V_88 ;
if ( V_83 == V_82 && V_84 == F_53 ( V_81 , V_83 ) ) {
F_54 ( V_81 , V_83 ) ;
F_23 ( V_45 , V_6 ) ;
F_12 ( & V_17 , V_45 ) ;
V_12 = F_5 ( V_45 ) ;
}
}
if ( V_12 ) {
F_52 ( V_2 , V_12 ) ;
F_15 ( V_2 , V_12 ) ;
}
}
void F_58 ( struct V_1 * V_2 , T_5 V_82 , T_5 V_88 )
{
struct V_80 * V_81 ;
V_81 = & V_2 -> V_4 -> V_86 -> V_81 ;
if ( F_56 ( V_88 , F_53 ( V_81 , V_82 ) ) )
return;
F_59 ( V_81 , V_82 , V_88 ) ;
F_57 ( V_2 , V_82 ) ;
}
static T_5 F_60 ( struct V_1 * V_2 ,
struct V_16 * V_27 , T_5 V_90 )
{
T_5 V_91 = 0 ;
T_2 V_47 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_92 * V_93 ;
V_93 = & V_2 -> V_4 -> V_76 . V_77 ;
while ( ( V_10 = F_61 ( V_27 ) ) != NULL ) {
V_91 += F_62 ( V_10 ) ;
V_12 = F_5 ( V_10 ) ;
V_47 = V_12 -> V_47 ;
F_6 ( V_12 ) ;
F_63 ( V_93 , V_47 ) ;
if ( V_91 >= V_90 )
return V_91 ;
}
return V_91 ;
}
static T_5 F_64 ( struct V_1 * V_2 , T_5 V_90 )
{
return F_60 ( V_2 , & V_2 -> V_6 , V_90 ) ;
}
static T_5 F_65 ( struct V_1 * V_2 , T_5 V_90 )
{
return F_60 ( V_2 , & V_2 -> V_5 , V_90 ) ;
}
void F_66 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
T_1 V_15 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
V_4 = V_2 -> V_4 ;
V_24 = F_17 ( V_4 -> V_30 . V_22 ) ;
if ( V_2 -> V_7 )
return;
if ( V_24 -> V_43 || F_30 ( & V_24 -> V_7 ) == 0 ) {
V_12 = F_49 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 , V_12 ) ;
F_24 ( V_2 ) ;
return;
}
}
}
void F_67 ( struct V_1 * V_2 , struct V_13 * V_14 ,
T_1 V_15 )
{
struct V_3 * V_4 ;
T_5 V_90 , V_91 ;
V_4 = V_2 -> V_4 ;
if ( V_14 ) {
V_90 = F_68 ( V_14 -> V_94 -> V_95 ) ;
V_90 -= sizeof( V_96 ) ;
} else
V_90 = V_97 ;
V_91 = 0 ;
if ( F_19 ( & V_4 -> V_30 . V_22 -> V_28 ) ) {
V_91 = F_64 ( V_2 , V_90 ) ;
if ( V_91 < V_90 ) {
V_91 += F_65 ( V_2 , V_90 - V_91 ) ;
}
}
if ( V_14 && ( V_91 >= V_90 ) ) {
T_2 V_47 ;
V_47 = F_69 ( V_14 -> V_98 . V_99 -> V_47 ) ;
F_70 ( & V_4 -> V_76 . V_77 , V_47 , V_14 -> V_100 ) ;
F_9 ( V_2 , V_14 , V_15 ) ;
F_66 ( V_2 , V_14 , V_15 ) ;
}
F_71 ( V_4 -> V_30 . V_22 ) ;
}
void F_72 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_11 * V_101 = NULL ;
struct V_21 * V_22 ;
if ( ! V_2 -> V_7 )
return;
V_22 = V_2 -> V_4 -> V_30 . V_22 ;
if ( F_73 ( V_102 ,
& F_17 ( V_22 ) -> V_39 ) )
V_101 = F_74 ( V_2 -> V_4 ,
V_103 ,
V_15 ) ;
if ( V_101 )
F_12 ( & V_22 -> V_28 , F_13 ( V_101 ) ) ;
if ( F_26 ( V_2 ) || V_101 )
V_22 -> V_44 ( V_22 , 0 ) ;
}
