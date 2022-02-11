struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
V_2 -> V_4 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = 0 ;
return V_2 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
while ( ( V_9 = F_4 ( & V_2 -> V_6 ) ) != NULL ) {
V_11 = F_5 ( V_9 ) ;
F_6 ( V_11 ) ;
}
while ( ( V_9 = F_4 ( & V_2 -> V_5 ) ) != NULL ) {
V_11 = F_5 ( V_9 ) ;
F_6 ( V_11 ) ;
}
}
void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
}
int F_8 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 V_14 )
{
struct V_15 V_16 ;
struct V_10 * V_11 ;
int V_17 = 0 ;
V_11 = F_9 ( V_13 -> V_4 , V_13 , V_14 ) ;
if ( ! V_11 )
return - V_18 ;
V_11 = F_10 ( V_2 , V_11 ) ;
if ( ( V_11 ) && ( V_11 -> V_19 & V_20 ) ) {
F_2 ( & V_16 ) ;
F_11 ( & V_16 , F_12 ( V_11 ) ) ;
V_11 = F_13 ( V_2 , V_11 ) ;
}
if ( V_11 ) {
V_17 = ( V_11 -> V_19 & V_20 ) ? 1 : 0 ;
F_14 ( V_2 , V_11 ) ;
}
return V_17 ;
}
int F_15 ( struct V_21 * V_22 , struct V_3 * V_4 )
{
struct V_23 * V_24 = F_16 ( V_22 ) ;
if ( F_17 ( & V_24 -> V_7 ) ) {
if ( ! F_18 ( & V_24 -> V_25 ) ) {
F_19 ( & V_24 -> V_25 ,
& V_22 -> V_26 ) ;
return 1 ;
}
} else {
if ( ! F_18 ( & V_24 -> V_25 ) && V_4 ) {
struct V_8 * V_9 , * V_27 ;
struct V_10 * V_11 ;
F_20 (skb, &sp->pd_lobby, tmp) {
V_11 = F_5 ( V_9 ) ;
if ( V_11 -> V_4 == V_4 ) {
F_21 ( V_9 , & V_24 -> V_25 ) ;
F_11 ( & V_22 -> V_26 ,
V_9 ) ;
}
}
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_16 ( V_2 -> V_4 -> V_28 . V_22 ) ;
F_23 ( & V_24 -> V_7 ) ;
V_2 -> V_7 = 1 ;
}
static int F_24 ( struct V_1 * V_2 )
{
V_2 -> V_7 = 0 ;
F_25 ( V_2 ) ;
return F_15 ( V_2 -> V_4 -> V_28 . V_22 , V_2 -> V_4 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_21 * V_22 = V_2 -> V_4 -> V_28 . V_22 ;
struct V_23 * V_24 = F_16 ( V_22 ) ;
struct V_15 * V_29 , * V_30 ;
struct V_8 * V_9 = F_12 ( V_11 ) ;
int V_31 = 0 ;
V_30 = (struct V_15 * ) V_9 -> V_32 ;
if ( V_22 -> V_33 & V_34 &&
( V_22 -> V_33 & V_35 ||
! F_26 ( V_11 ) ) )
goto V_36;
if ( ! F_26 ( V_11 ) ) {
F_27 ( V_22 , V_9 ) ;
F_28 ( V_22 ) ;
}
if ( ! F_29 ( V_11 , & V_24 -> V_37 ) )
goto V_36;
if ( F_30 ( & V_24 -> V_7 ) == 0 ) {
V_29 = & V_22 -> V_26 ;
} else {
if ( V_2 -> V_7 ) {
if ( ( V_11 -> V_19 & V_38 ) ||
( V_39 ==
( V_11 -> V_19 & V_40 ) ) )
V_29 = & V_24 -> V_25 ;
else {
V_31 = V_11 -> V_19 & V_20 ;
V_29 = & V_22 -> V_26 ;
}
} else {
if ( V_24 -> V_41 )
V_29 = & V_22 -> V_26 ;
else
V_29 = & V_24 -> V_25 ;
}
}
if ( V_30 )
F_19 ( V_30 , V_29 ) ;
else
F_11 ( V_29 , V_9 ) ;
if ( V_31 )
F_24 ( V_2 ) ;
if ( V_29 == & V_22 -> V_26 && ! V_24 -> V_42 ) {
if ( ! F_31 ( V_22 ) )
V_24 -> V_42 = 1 ;
V_22 -> V_43 ( V_22 ) ;
}
return 1 ;
V_36:
if ( V_30 )
F_32 ( V_30 ) ;
else
F_6 ( V_11 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_8 * V_44 ;
struct V_10 * V_45 ;
T_2 V_46 , V_47 ;
V_46 = V_11 -> V_46 ;
V_44 = F_34 ( & V_2 -> V_5 ) ;
if ( ! V_44 ) {
F_11 ( & V_2 -> V_5 , F_12 ( V_11 ) ) ;
return;
}
V_45 = F_5 ( V_44 ) ;
V_47 = V_45 -> V_46 ;
if ( F_35 ( V_47 , V_46 ) ) {
F_11 ( & V_2 -> V_5 , F_12 ( V_11 ) ) ;
return;
}
F_36 (&ulpq->reasm, pos) {
V_45 = F_5 ( V_44 ) ;
V_47 = V_45 -> V_46 ;
if ( F_35 ( V_46 , V_47 ) )
break;
}
F_37 ( & V_2 -> V_5 , V_44 , F_12 ( V_11 ) ) ;
}
static struct V_10 * F_38 ( struct V_48 * V_48 ,
struct V_15 * V_29 , struct V_8 * V_49 ,
struct V_8 * V_50 )
{
struct V_8 * V_44 ;
struct V_8 * V_51 = NULL ;
struct V_10 * V_11 ;
struct V_8 * V_52 , * V_53 ;
struct V_8 * V_54 = F_39 ( V_49 ) -> V_55 ;
if ( V_49 == V_50 )
V_44 = NULL ;
else
V_44 = V_49 -> V_56 ;
for ( V_53 = V_54 ; V_54 ; V_53 = V_54 , V_54 = V_54 -> V_56 )
;
if ( V_53 )
V_53 -> V_56 = V_44 ;
else {
if ( F_40 ( V_49 ) ) {
V_51 = F_41 ( V_49 , V_57 ) ;
if ( ! V_51 )
return NULL ;
F_42 ( V_51 , V_49 -> V_22 ) ;
F_39 ( V_51 ) -> V_55 = V_44 ;
} else
F_39 ( V_49 ) -> V_55 = V_44 ;
}
F_21 ( V_49 , V_29 ) ;
if ( V_51 ) {
F_43 ( V_49 ) ;
V_49 = V_51 ;
}
while ( V_44 ) {
V_52 = V_44 -> V_56 ;
V_49 -> V_58 += V_44 -> V_58 ;
V_49 -> V_59 += V_44 -> V_58 ;
F_21 ( V_44 , V_29 ) ;
if ( V_44 == V_50 )
break;
V_44 -> V_56 = V_52 ;
V_44 = V_52 ;
}
V_11 = F_5 ( V_49 ) ;
F_44 ( V_48 , V_60 ) ;
return V_11 ;
}
static struct V_10 * F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_44 ;
struct V_10 * V_45 ;
struct V_8 * V_61 = NULL ;
T_2 V_47 , V_62 ;
struct V_10 * V_63 = NULL ;
struct V_8 * V_64 = NULL ;
struct V_8 * V_65 = NULL ;
T_3 V_66 = 0 ;
struct V_3 * V_4 ;
T_4 V_67 ;
V_62 = 0 ;
F_36 (&ulpq->reasm, pos) {
V_45 = F_5 ( V_44 ) ;
V_47 = V_45 -> V_46 ;
switch ( V_45 -> V_19 & V_40 ) {
case V_68 :
if ( V_44 == V_2 -> V_5 . V_56 ) {
V_64 = V_44 ;
V_65 = V_44 ;
V_66 = V_44 -> V_58 ;
} else {
V_64 = NULL ;
V_65 = NULL ;
V_66 = 0 ;
}
V_61 = V_44 ;
V_62 = V_47 + 1 ;
break;
case V_69 :
if ( ( V_61 ) && ( V_47 == V_62 ) ) {
V_62 ++ ;
if ( V_64 ) {
V_65 = V_44 ;
V_66 += V_44 -> V_58 ;
}
} else
V_61 = NULL ;
break;
case V_70 :
if ( V_61 && ( V_47 == V_62 ) )
goto V_71;
else
V_61 = NULL ;
break;
}
}
V_4 = V_2 -> V_4 ;
if ( V_64 ) {
if ( ! F_16 ( V_4 -> V_28 . V_22 ) -> V_41 &&
F_30 ( & F_16 ( V_4 -> V_28 . V_22 ) -> V_7 ) )
goto V_72;
V_45 = F_5 ( V_64 ) ;
V_67 = F_16 ( V_4 -> V_28 . V_22 ) -> V_67 ;
if ( V_67 && V_67 <= V_66 ) {
V_63 = F_38 ( F_46 ( V_4 -> V_28 . V_22 ) ,
& V_2 -> V_5 ,
V_64 ,
V_65 ) ;
if ( V_63 )
F_22 ( V_2 ) ;
}
}
V_72:
return V_63 ;
V_71:
V_63 = F_38 ( F_46 ( V_2 -> V_4 -> V_28 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_44 ) ;
if ( V_63 )
V_63 -> V_19 |= V_20 ;
goto V_72;
}
static struct V_10 * F_47 ( struct V_1 * V_2 )
{
struct V_8 * V_44 , * V_73 , * V_61 ;
struct V_10 * V_45 ;
T_2 V_47 , V_62 ;
int V_74 ;
struct V_10 * V_63 ;
if ( F_18 ( & V_2 -> V_5 ) )
return NULL ;
V_73 = V_61 = NULL ;
V_63 = NULL ;
V_62 = 0 ;
V_74 = 0 ;
F_36 (&ulpq->reasm, pos) {
V_45 = F_5 ( V_44 ) ;
V_47 = V_45 -> V_46 ;
switch ( V_45 -> V_19 & V_40 ) {
case V_68 :
if ( ! V_61 )
return NULL ;
goto V_72;
case V_69 :
if ( ! V_61 ) {
V_61 = V_44 ;
V_62 = V_47 + 1 ;
V_73 = V_44 ;
} else if ( V_62 == V_47 ) {
V_62 ++ ;
V_73 = V_44 ;
} else
goto V_72;
break;
case V_70 :
if ( ! V_61 )
V_61 = V_44 ;
else if ( V_47 != V_62 )
goto V_72;
V_73 = V_44 ;
V_74 = 1 ;
goto V_72;
default:
return NULL ;
}
}
V_72:
V_63 = F_38 ( F_46 ( V_2 -> V_4 -> V_28 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_73 ) ;
if ( V_63 && V_74 )
V_63 -> V_19 |= V_20 ;
return V_63 ;
}
static struct V_10 * F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_10 * V_63 = NULL ;
if ( V_39 == ( V_11 -> V_19 & V_40 ) ) {
V_11 -> V_19 |= V_20 ;
return V_11 ;
}
F_33 ( V_2 , V_11 ) ;
if ( ! V_2 -> V_7 )
V_63 = F_45 ( V_2 ) ;
else {
T_2 V_47 , V_75 ;
V_47 = V_11 -> V_46 ;
V_75 = F_48 ( & V_2 -> V_4 -> V_76 . V_77 ) ;
if ( F_49 ( V_47 , V_75 ) )
V_63 = F_47 ( V_2 ) ;
}
return V_63 ;
}
static struct V_10 * F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_44 , * V_73 , * V_61 ;
struct V_10 * V_45 ;
T_2 V_47 , V_62 ;
struct V_10 * V_63 ;
if ( F_18 ( & V_2 -> V_5 ) )
return NULL ;
V_73 = V_61 = NULL ;
V_63 = NULL ;
V_62 = 0 ;
F_36 (&ulpq->reasm, pos) {
V_45 = F_5 ( V_44 ) ;
V_47 = V_45 -> V_46 ;
switch ( V_45 -> V_19 & V_40 ) {
case V_68 :
if ( ! V_61 ) {
V_61 = V_44 ;
V_62 = V_47 + 1 ;
V_73 = V_44 ;
} else
goto V_72;
break;
case V_69 :
if ( ! V_61 )
return NULL ;
if ( V_47 == V_62 ) {
V_62 ++ ;
V_73 = V_44 ;
} else
goto V_72;
break;
case V_70 :
if ( ! V_61 )
return NULL ;
else
goto V_72;
break;
default:
return NULL ;
}
}
V_72:
V_63 = F_38 ( F_46 ( V_2 -> V_4 -> V_28 . V_22 ) ,
& V_2 -> V_5 , V_61 , V_73 ) ;
return V_63 ;
}
void F_51 ( struct V_1 * V_2 , T_2 V_78 )
{
struct V_8 * V_44 , * V_27 ;
struct V_10 * V_11 ;
T_2 V_46 ;
if ( F_18 ( & V_2 -> V_5 ) )
return;
F_52 (&ulpq->reasm, pos, tmp) {
V_11 = F_5 ( V_44 ) ;
V_46 = V_11 -> V_46 ;
if ( F_49 ( V_46 , V_78 ) ) {
F_21 ( V_44 , & V_2 -> V_5 ) ;
F_6 ( V_11 ) ;
} else
break;
}
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = NULL ;
struct V_15 V_16 ;
if ( F_18 ( & V_2 -> V_5 ) )
return;
while ( ( V_11 = F_45 ( V_2 ) ) != NULL ) {
if ( ( V_11 ) && ( V_11 -> V_19 & V_20 ) ) {
F_2 ( & V_16 ) ;
F_11 ( & V_16 , F_12 ( V_11 ) ) ;
V_11 = F_13 ( V_2 , V_11 ) ;
}
if ( V_11 )
F_14 ( V_2 , V_11 ) ;
}
}
static void F_53 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_15 * V_79 ;
struct V_8 * V_44 , * V_27 ;
struct V_10 * V_45 ;
struct V_80 * V_81 ;
T_5 V_82 , V_83 , V_84 ;
V_82 = V_11 -> V_81 ;
V_81 = & V_2 -> V_4 -> V_81 ;
V_79 = (struct V_15 * ) F_12 ( V_11 ) -> V_32 ;
F_20 (pos, &ulpq->lobby, tmp) {
V_45 = (struct V_10 * ) V_44 -> V_85 ;
V_83 = V_45 -> V_81 ;
V_84 = V_45 -> V_86 ;
if ( V_83 > V_82 )
break;
if ( V_83 < V_82 )
continue;
if ( V_84 != F_54 ( V_81 , V_87 , V_82 ) )
break;
F_55 ( V_81 , V_87 , V_82 ) ;
F_21 ( V_44 , & V_2 -> V_6 ) ;
F_11 ( V_79 , V_44 ) ;
}
}
static void F_56 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_8 * V_44 ;
struct V_10 * V_45 ;
T_5 V_82 , V_83 ;
T_5 V_86 , V_84 ;
V_44 = F_34 ( & V_2 -> V_6 ) ;
if ( ! V_44 ) {
F_11 ( & V_2 -> V_6 , F_12 ( V_11 ) ) ;
return;
}
V_82 = V_11 -> V_81 ;
V_86 = V_11 -> V_86 ;
V_45 = (struct V_10 * ) V_44 -> V_85 ;
V_83 = V_45 -> V_81 ;
V_84 = V_45 -> V_86 ;
if ( V_82 > V_83 ) {
F_11 ( & V_2 -> V_6 , F_12 ( V_11 ) ) ;
return;
}
if ( ( V_82 == V_83 ) && F_57 ( V_84 , V_86 ) ) {
F_11 ( & V_2 -> V_6 , F_12 ( V_11 ) ) ;
return;
}
F_36 (&ulpq->lobby, pos) {
V_45 = (struct V_10 * ) V_44 -> V_85 ;
V_83 = V_45 -> V_81 ;
V_84 = V_45 -> V_86 ;
if ( V_83 > V_82 )
break;
if ( V_83 == V_82 && F_57 ( V_86 , V_84 ) )
break;
}
F_37 ( & V_2 -> V_6 , V_44 , F_12 ( V_11 ) ) ;
}
static struct V_10 * F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
T_5 V_82 , V_86 ;
struct V_80 * V_81 ;
if ( V_88 & V_11 -> V_19 )
return V_11 ;
V_82 = V_11 -> V_81 ;
V_86 = V_11 -> V_86 ;
V_81 = & V_2 -> V_4 -> V_81 ;
if ( V_86 != F_54 ( V_81 , V_87 , V_82 ) ) {
F_56 ( V_2 , V_11 ) ;
return NULL ;
}
F_55 ( V_81 , V_87 , V_82 ) ;
F_53 ( V_2 , V_11 ) ;
return V_11 ;
}
static void F_58 ( struct V_1 * V_2 , T_5 V_82 )
{
struct V_8 * V_44 , * V_27 ;
struct V_10 * V_45 ;
struct V_10 * V_11 ;
struct V_80 * V_81 ;
struct V_15 V_16 ;
struct V_15 * V_6 = & V_2 -> V_6 ;
T_5 V_83 , V_84 ;
V_81 = & V_2 -> V_4 -> V_81 ;
F_2 ( & V_16 ) ;
V_11 = NULL ;
F_20 (pos, lobby, tmp) {
V_45 = (struct V_10 * ) V_44 -> V_85 ;
V_83 = V_45 -> V_81 ;
V_84 = V_45 -> V_86 ;
if ( V_83 > V_82 )
break;
if ( V_83 < V_82 )
continue;
if ( ! F_57 ( V_84 , F_54 ( V_81 , V_87 , V_83 ) ) )
break;
F_21 ( V_44 , V_6 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_44 ) ;
F_11 ( & V_16 , V_44 ) ;
}
if ( V_11 == NULL && V_44 != (struct V_8 * ) V_6 ) {
V_45 = (struct V_10 * ) V_44 -> V_85 ;
V_83 = V_45 -> V_81 ;
V_84 = V_45 -> V_86 ;
if ( V_83 == V_82 && V_84 == F_54 ( V_81 , V_87 , V_83 ) ) {
F_55 ( V_81 , V_87 , V_83 ) ;
F_21 ( V_44 , V_6 ) ;
F_11 ( & V_16 , V_44 ) ;
V_11 = F_5 ( V_44 ) ;
}
}
if ( V_11 ) {
F_53 ( V_2 , V_11 ) ;
F_14 ( V_2 , V_11 ) ;
}
}
void F_59 ( struct V_1 * V_2 , T_5 V_82 , T_5 V_86 )
{
struct V_80 * V_81 ;
V_81 = & V_2 -> V_4 -> V_81 ;
if ( F_57 ( V_86 , F_54 ( V_81 , V_87 , V_82 ) ) )
return;
F_60 ( V_81 , V_87 , V_82 , V_86 ) ;
F_58 ( V_2 , V_82 ) ;
}
static T_5 F_61 ( struct V_1 * V_2 ,
struct V_15 * V_54 , T_5 V_89 )
{
T_5 V_90 = 0 ;
T_2 V_46 , V_91 ;
struct V_8 * V_9 , * V_92 , * V_53 ;
struct V_10 * V_11 ;
struct V_93 * V_94 ;
V_94 = & V_2 -> V_4 -> V_76 . V_77 ;
while ( ( V_9 = F_34 ( V_54 ) ) != NULL ) {
V_11 = F_5 ( V_9 ) ;
V_46 = V_11 -> V_46 ;
if ( F_49 ( V_46 , F_48 ( V_94 ) ) )
break;
V_90 += F_62 ( V_9 ) ;
V_92 = F_39 ( V_9 ) -> V_55 ;
for ( V_53 = V_92 ; V_92 ; V_92 = V_92 -> V_56 ) {
V_53 = V_92 ;
V_90 += F_62 ( V_53 ) ;
}
if ( V_53 )
V_91 = F_5 ( V_53 ) -> V_46 ;
else
V_91 = V_46 ;
F_21 ( V_9 , V_54 ) ;
F_6 ( V_11 ) ;
while ( F_49 ( V_46 , V_91 ) ) {
F_63 ( V_94 , V_46 ) ;
V_46 ++ ;
}
if ( V_90 >= V_89 )
return V_90 ;
}
return V_90 ;
}
static T_5 F_64 ( struct V_1 * V_2 , T_5 V_89 )
{
return F_61 ( V_2 , & V_2 -> V_6 , V_89 ) ;
}
static T_5 F_65 ( struct V_1 * V_2 , T_5 V_89 )
{
return F_61 ( V_2 , & V_2 -> V_5 , V_89 ) ;
}
void F_66 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_10 * V_11 ;
struct V_3 * V_4 ;
struct V_23 * V_24 ;
T_2 V_47 ;
struct V_8 * V_9 ;
V_4 = V_2 -> V_4 ;
V_24 = F_16 ( V_4 -> V_28 . V_22 ) ;
if ( V_2 -> V_7 )
return;
V_9 = F_67 ( & V_4 -> V_2 . V_5 ) ;
if ( V_9 != NULL ) {
V_47 = F_5 ( V_9 ) -> V_46 ;
if ( ! F_49 ( V_47 , F_48 ( & V_4 -> V_76 . V_77 ) ) )
return;
}
if ( V_24 -> V_41 || F_30 ( & V_24 -> V_7 ) == 0 ) {
V_11 = F_50 ( V_2 ) ;
if ( V_11 ) {
F_14 ( V_2 , V_11 ) ;
F_22 ( V_2 ) ;
return;
}
}
}
void F_68 ( struct V_1 * V_2 , struct V_12 * V_13 ,
T_1 V_14 )
{
struct V_3 * V_4 ;
T_5 V_89 , V_90 ;
V_4 = V_2 -> V_4 ;
if ( V_13 ) {
V_89 = F_69 ( V_13 -> V_95 -> V_96 ) ;
V_89 -= sizeof( struct V_97 ) ;
} else
V_89 = V_98 ;
V_90 = 0 ;
if ( F_18 ( & V_4 -> V_28 . V_22 -> V_26 ) ) {
V_90 = F_64 ( V_2 , V_89 ) ;
if ( V_90 < V_89 ) {
V_90 += F_65 ( V_2 , V_89 - V_90 ) ;
}
}
if ( V_13 && ( V_90 >= V_89 ) ) {
int V_63 ;
V_63 = F_8 ( V_2 , V_13 , V_14 ) ;
if ( V_63 <= 0 )
F_66 ( V_2 , V_14 ) ;
else if ( V_63 == 1 )
F_25 ( V_2 ) ;
}
F_70 ( V_4 -> V_28 . V_22 ) ;
}
void F_71 ( struct V_1 * V_2 , T_1 V_14 )
{
struct V_10 * V_99 = NULL ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
if ( ! V_2 -> V_7 )
return;
V_22 = V_2 -> V_4 -> V_28 . V_22 ;
V_24 = F_16 ( V_22 ) ;
if ( F_72 ( V_100 ,
& F_16 ( V_22 ) -> V_37 ) )
V_99 = F_73 ( V_2 -> V_4 ,
V_101 ,
V_14 ) ;
if ( V_99 )
F_11 ( & V_22 -> V_26 , F_12 ( V_99 ) ) ;
if ( ( F_24 ( V_2 ) || V_99 ) && ! V_24 -> V_42 ) {
V_24 -> V_42 = 1 ;
V_22 -> V_43 ( V_22 ) ;
}
}
