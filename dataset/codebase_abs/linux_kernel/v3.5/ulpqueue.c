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
static struct V_11 * F_37 ( struct V_16 * V_31 , struct V_9 * V_49 , struct V_9 * V_50 )
{
struct V_9 * V_45 ;
struct V_9 * V_51 = NULL ;
struct V_11 * V_12 ;
struct V_9 * V_52 , * V_53 ;
struct V_9 * V_27 = F_38 ( V_49 ) -> V_54 ;
if ( V_49 == V_50 )
V_45 = NULL ;
else
V_45 = V_49 -> V_55 ;
for ( V_53 = V_27 ; V_27 ; V_53 = V_27 , V_27 = V_27 -> V_55 ) ;
if ( V_53 )
V_53 -> V_55 = V_45 ;
else {
if ( F_39 ( V_49 ) ) {
V_51 = F_40 ( V_49 , V_56 ) ;
if ( ! V_51 )
return NULL ;
F_41 ( V_51 , V_49 -> V_22 ) ;
F_38 ( V_51 ) -> V_54 = V_45 ;
} else
F_38 ( V_49 ) -> V_54 = V_45 ;
}
F_23 ( V_49 , V_31 ) ;
if ( V_51 ) {
F_42 ( V_49 ) ;
V_49 = V_51 ;
}
while ( V_45 ) {
V_52 = V_45 -> V_55 ;
V_49 -> V_57 += V_45 -> V_57 ;
V_49 -> V_58 += V_45 -> V_57 ;
F_23 ( V_45 , V_31 ) ;
if ( V_45 == V_50 )
break;
V_45 -> V_55 = V_52 ;
V_45 = V_52 ;
}
V_12 = F_5 ( V_49 ) ;
F_43 ( V_59 ) ;
return V_12 ;
}
static struct V_11 * F_44 ( struct V_1 * V_2 )
{
struct V_9 * V_45 ;
struct V_11 * V_46 ;
struct V_9 * V_60 = NULL ;
T_2 V_48 , V_61 ;
struct V_11 * V_62 = NULL ;
struct V_9 * V_63 = NULL ;
struct V_9 * V_64 = NULL ;
T_3 V_65 = 0 ;
struct V_3 * V_4 ;
T_4 V_66 ;
V_61 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_67 :
if ( V_45 == V_2 -> V_5 . V_55 ) {
V_63 = V_45 ;
V_64 = V_45 ;
V_65 = V_45 -> V_57 ;
} else {
V_63 = NULL ;
V_64 = NULL ;
V_65 = 0 ;
}
V_60 = V_45 ;
V_61 = V_48 + 1 ;
break;
case V_68 :
if ( ( V_60 ) && ( V_48 == V_61 ) ) {
V_61 ++ ;
if ( V_63 ) {
V_64 = V_45 ;
V_65 += V_45 -> V_57 ;
}
} else
V_60 = NULL ;
break;
case V_69 :
if ( V_60 && ( V_48 == V_61 ) )
goto V_70;
else
V_60 = NULL ;
break;
}
}
V_4 = V_2 -> V_4 ;
if ( V_63 ) {
if ( ! F_17 ( V_4 -> V_30 . V_22 ) -> V_43 &&
F_30 ( & F_17 ( V_4 -> V_30 . V_22 ) -> V_7 ) )
goto V_71;
V_46 = F_5 ( V_63 ) ;
V_66 = F_17 ( V_4 -> V_30 . V_22 ) -> V_66 ;
if ( V_66 && V_66 <= V_65 ) {
V_62 = F_37 ( & V_2 -> V_5 ,
V_63 ,
V_64 ) ;
if ( V_62 )
F_24 ( V_2 ) ;
}
}
V_71:
return V_62 ;
V_70:
V_62 = F_37 ( & V_2 -> V_5 , V_60 , V_45 ) ;
if ( V_62 )
V_62 -> V_19 |= V_20 ;
goto V_71;
}
static struct V_11 * F_45 ( struct V_1 * V_2 )
{
struct V_9 * V_45 , * V_72 , * V_60 ;
struct V_11 * V_46 ;
T_2 V_48 , V_61 ;
int V_73 ;
struct V_11 * V_62 ;
if ( F_19 ( & V_2 -> V_5 ) )
return NULL ;
V_72 = V_60 = NULL ;
V_62 = NULL ;
V_61 = 0 ;
V_73 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_68 :
if ( ! V_60 ) {
V_60 = V_45 ;
V_61 = V_48 + 1 ;
V_72 = V_45 ;
} else if ( V_61 == V_48 )
V_61 ++ ;
else
goto V_71;
break;
case V_69 :
if ( ! V_60 )
V_60 = V_45 ;
else if ( V_48 != V_61 )
goto V_71;
V_72 = V_45 ;
V_73 = 1 ;
goto V_71;
default:
return NULL ;
}
}
V_71:
V_62 = F_37 ( & V_2 -> V_5 , V_60 , V_72 ) ;
if ( V_62 && V_73 )
V_62 -> V_19 |= V_20 ;
return V_62 ;
}
static struct V_11 * F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_11 * V_62 = NULL ;
if ( V_41 == ( V_12 -> V_19 & V_42 ) ) {
V_12 -> V_19 |= V_20 ;
return V_12 ;
}
F_32 ( V_2 , V_12 ) ;
if ( ! V_2 -> V_7 )
V_62 = F_44 ( V_2 ) ;
else {
T_2 V_48 , V_74 ;
V_48 = V_12 -> V_47 ;
V_74 = F_46 ( & V_2 -> V_4 -> V_75 . V_76 ) ;
if ( F_47 ( V_48 , V_74 ) )
V_62 = F_45 ( V_2 ) ;
}
return V_62 ;
}
static struct V_11 * F_48 ( struct V_1 * V_2 )
{
struct V_9 * V_45 , * V_72 , * V_60 ;
struct V_11 * V_46 ;
T_2 V_48 , V_61 ;
struct V_11 * V_62 ;
if ( F_19 ( & V_2 -> V_5 ) )
return NULL ;
V_72 = V_60 = NULL ;
V_62 = NULL ;
V_61 = 0 ;
F_35 (&ulpq->reasm, pos) {
V_46 = F_5 ( V_45 ) ;
V_48 = V_46 -> V_47 ;
switch ( V_46 -> V_19 & V_42 ) {
case V_67 :
if ( ! V_60 ) {
V_60 = V_45 ;
V_61 = V_48 + 1 ;
V_72 = V_45 ;
} else
goto V_71;
break;
case V_68 :
if ( ! V_60 )
return NULL ;
if ( V_48 == V_61 ) {
V_61 ++ ;
V_72 = V_45 ;
} else
goto V_71;
break;
default:
return NULL ;
}
}
V_71:
V_62 = F_37 ( & V_2 -> V_5 , V_60 , V_72 ) ;
return V_62 ;
}
void F_49 ( struct V_1 * V_2 , T_2 V_77 )
{
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_12 ;
T_2 V_47 ;
if ( F_19 ( & V_2 -> V_5 ) )
return;
F_50 (&ulpq->reasm, pos, tmp) {
V_12 = F_5 ( V_45 ) ;
V_47 = V_12 -> V_47 ;
if ( F_47 ( V_47 , V_77 ) ) {
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
static void F_51 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_16 * V_78 ;
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_46 ;
struct V_79 * V_80 ;
T_5 V_81 , V_82 , V_83 ;
V_81 = V_12 -> V_84 ;
V_80 = & V_2 -> V_4 -> V_85 -> V_80 ;
V_78 = (struct V_16 * ) F_13 ( V_12 ) -> V_34 ;
F_22 (pos, &ulpq->lobby, tmp) {
V_46 = (struct V_11 * ) V_45 -> V_86 ;
V_82 = V_46 -> V_84 ;
V_83 = V_46 -> V_87 ;
if ( V_82 > V_81 )
break;
if ( V_82 < V_81 )
continue;
if ( V_83 != F_52 ( V_80 , V_81 ) )
break;
F_53 ( V_80 , V_81 ) ;
F_23 ( V_45 , & V_2 -> V_6 ) ;
F_12 ( V_78 , V_45 ) ;
}
}
static void F_54 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_9 * V_45 ;
struct V_11 * V_46 ;
T_5 V_81 , V_82 ;
T_5 V_87 , V_83 ;
V_45 = F_33 ( & V_2 -> V_6 ) ;
if ( ! V_45 ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
V_81 = V_12 -> V_84 ;
V_87 = V_12 -> V_87 ;
V_46 = (struct V_11 * ) V_45 -> V_86 ;
V_82 = V_46 -> V_84 ;
V_83 = V_46 -> V_87 ;
if ( V_81 > V_82 ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
if ( ( V_81 == V_82 ) && F_55 ( V_83 , V_87 ) ) {
F_12 ( & V_2 -> V_6 , F_13 ( V_12 ) ) ;
return;
}
F_35 (&ulpq->lobby, pos) {
V_46 = (struct V_11 * ) V_45 -> V_86 ;
V_82 = V_46 -> V_84 ;
V_83 = V_46 -> V_87 ;
if ( V_82 > V_81 )
break;
if ( V_82 == V_81 && F_55 ( V_87 , V_83 ) )
break;
}
F_36 ( & V_2 -> V_6 , V_45 , F_13 ( V_12 ) ) ;
}
static struct V_11 * F_14 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
T_5 V_81 , V_87 ;
struct V_79 * V_80 ;
if ( V_88 & V_12 -> V_19 )
return V_12 ;
V_81 = V_12 -> V_84 ;
V_87 = V_12 -> V_87 ;
V_80 = & V_2 -> V_4 -> V_85 -> V_80 ;
if ( V_87 != F_52 ( V_80 , V_81 ) ) {
F_54 ( V_2 , V_12 ) ;
return NULL ;
}
F_53 ( V_80 , V_81 ) ;
F_51 ( V_2 , V_12 ) ;
return V_12 ;
}
static void F_56 ( struct V_1 * V_2 , T_5 V_81 )
{
struct V_9 * V_45 , * V_29 ;
struct V_11 * V_46 ;
struct V_11 * V_12 ;
struct V_79 * V_80 ;
struct V_16 V_17 ;
struct V_16 * V_6 = & V_2 -> V_6 ;
T_5 V_82 , V_83 ;
V_80 = & V_2 -> V_4 -> V_85 -> V_80 ;
F_2 ( & V_17 ) ;
V_12 = NULL ;
F_22 (pos, lobby, tmp) {
V_46 = (struct V_11 * ) V_45 -> V_86 ;
V_82 = V_46 -> V_84 ;
V_83 = V_46 -> V_87 ;
if ( V_82 > V_81 )
break;
if ( V_82 < V_81 )
continue;
if ( ! F_55 ( V_83 , F_52 ( V_80 , V_82 ) ) )
break;
F_23 ( V_45 , V_6 ) ;
if ( ! V_12 )
V_12 = F_5 ( V_45 ) ;
F_12 ( & V_17 , V_45 ) ;
}
if ( V_12 == NULL && V_45 != (struct V_9 * ) V_6 ) {
V_46 = (struct V_11 * ) V_45 -> V_86 ;
V_82 = V_46 -> V_84 ;
V_83 = V_46 -> V_87 ;
if ( V_82 == V_81 && V_83 == F_52 ( V_80 , V_82 ) ) {
F_53 ( V_80 , V_82 ) ;
F_23 ( V_45 , V_6 ) ;
F_12 ( & V_17 , V_45 ) ;
V_12 = F_5 ( V_45 ) ;
}
}
if ( V_12 ) {
F_51 ( V_2 , V_12 ) ;
F_15 ( V_2 , V_12 ) ;
}
}
void F_57 ( struct V_1 * V_2 , T_5 V_81 , T_5 V_87 )
{
struct V_79 * V_80 ;
V_80 = & V_2 -> V_4 -> V_85 -> V_80 ;
if ( F_55 ( V_87 , F_52 ( V_80 , V_81 ) ) )
return;
F_58 ( V_80 , V_81 , V_87 ) ;
F_56 ( V_2 , V_81 ) ;
}
static T_5 F_59 ( struct V_1 * V_2 ,
struct V_16 * V_27 , T_5 V_89 )
{
T_5 V_90 = 0 ;
T_2 V_47 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_91 * V_92 ;
V_92 = & V_2 -> V_4 -> V_75 . V_76 ;
while ( ( V_10 = F_60 ( V_27 ) ) != NULL ) {
V_90 += F_61 ( V_10 ) ;
V_12 = F_5 ( V_10 ) ;
V_47 = V_12 -> V_47 ;
F_6 ( V_12 ) ;
F_62 ( V_92 , V_47 ) ;
if ( V_90 >= V_89 )
return V_90 ;
}
return V_90 ;
}
static T_5 F_63 ( struct V_1 * V_2 , T_5 V_89 )
{
return F_59 ( V_2 , & V_2 -> V_6 , V_89 ) ;
}
static T_5 F_64 ( struct V_1 * V_2 , T_5 V_89 )
{
return F_59 ( V_2 , & V_2 -> V_5 , V_89 ) ;
}
void F_65 ( struct V_1 * V_2 ,
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
V_12 = F_48 ( V_2 ) ;
if ( V_12 ) {
F_15 ( V_2 , V_12 ) ;
F_24 ( V_2 ) ;
return;
}
}
}
void F_66 ( struct V_1 * V_2 , struct V_13 * V_14 ,
T_1 V_15 )
{
struct V_3 * V_4 ;
T_5 V_89 , V_90 ;
V_4 = V_2 -> V_4 ;
if ( V_14 ) {
V_89 = F_67 ( V_14 -> V_93 -> V_94 ) ;
V_89 -= sizeof( V_95 ) ;
} else
V_89 = V_96 ;
V_90 = 0 ;
if ( F_19 ( & V_4 -> V_30 . V_22 -> V_28 ) ) {
V_90 = F_63 ( V_2 , V_89 ) ;
if ( V_90 < V_89 ) {
V_90 += F_64 ( V_2 , V_89 - V_90 ) ;
}
}
if ( V_14 && ( V_90 >= V_89 ) ) {
T_2 V_47 ;
V_47 = F_68 ( V_14 -> V_97 . V_98 -> V_47 ) ;
F_69 ( & V_4 -> V_75 . V_76 , V_47 , V_14 -> V_99 ) ;
F_9 ( V_2 , V_14 , V_15 ) ;
F_65 ( V_2 , V_14 , V_15 ) ;
}
F_70 ( V_4 -> V_30 . V_22 ) ;
}
void F_71 ( struct V_1 * V_2 , T_1 V_15 )
{
struct V_11 * V_100 = NULL ;
struct V_21 * V_22 ;
if ( ! V_2 -> V_7 )
return;
V_22 = V_2 -> V_4 -> V_30 . V_22 ;
if ( F_72 ( V_101 ,
& F_17 ( V_22 ) -> V_39 ) )
V_100 = F_73 ( V_2 -> V_4 ,
V_102 ,
V_15 ) ;
if ( V_100 )
F_12 ( & V_22 -> V_28 , F_13 ( V_100 ) ) ;
if ( F_26 ( V_2 ) || V_100 )
V_22 -> V_44 ( V_22 , 0 ) ;
}
