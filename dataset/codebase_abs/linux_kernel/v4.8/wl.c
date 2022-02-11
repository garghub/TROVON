static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * * V_6 , * V_7 = NULL ;
V_6 = & V_4 -> V_5 ;
while ( * V_6 ) {
struct V_1 * V_8 ;
V_7 = * V_6 ;
V_8 = F_2 ( V_7 , struct V_1 , V_9 . V_10 ) ;
if ( V_2 -> V_11 < V_8 -> V_11 )
V_6 = & ( * V_6 ) -> V_12 ;
else if ( V_2 -> V_11 > V_8 -> V_11 )
V_6 = & ( * V_6 ) -> V_13 ;
else {
F_3 ( V_2 -> V_14 != V_8 -> V_14 ) ;
if ( V_2 -> V_14 < V_8 -> V_14 )
V_6 = & ( * V_6 ) -> V_12 ;
else
V_6 = & ( * V_6 ) -> V_13 ;
}
}
F_4 ( & V_2 -> V_9 . V_10 , V_7 , V_6 ) ;
F_5 ( & V_2 -> V_9 . V_10 , V_4 ) ;
}
static void F_6 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
V_16 -> V_17 [ V_2 -> V_14 ] = NULL ;
F_7 ( V_18 , V_2 ) ;
}
static int F_8 ( struct V_15 * V_16 )
{
int V_19 ;
struct V_20 * V_21 ;
F_9 () ;
F_10 ( & V_16 -> V_22 ) ;
F_11 ( & V_16 -> V_23 ) ;
if ( F_12 ( & V_16 -> V_24 ) ) {
F_13 ( & V_16 -> V_23 ) ;
F_14 ( & V_16 -> V_22 ) ;
return 0 ;
}
V_21 = F_15 ( V_16 -> V_24 . V_25 , struct V_20 , V_26 ) ;
F_16 ( & V_21 -> V_26 ) ;
V_16 -> V_27 -= 1 ;
F_3 ( V_16 -> V_27 >= 0 ) ;
F_13 ( & V_16 -> V_23 ) ;
V_19 = V_21 -> V_28 ( V_16 , V_21 , 0 ) ;
if ( V_19 )
F_17 ( V_16 , L_1 , V_19 ) ;
F_14 ( & V_16 -> V_22 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = V_4 -> V_5 ;
while ( V_6 ) {
struct V_1 * V_8 ;
V_8 = F_2 ( V_6 , struct V_1 , V_9 . V_10 ) ;
if ( V_2 -> V_14 == V_8 -> V_14 ) {
F_3 ( V_2 == V_8 ) ;
return 1 ;
}
if ( V_2 -> V_11 < V_8 -> V_11 )
V_6 = V_6 -> V_12 ;
else if ( V_2 -> V_11 > V_8 -> V_11 )
V_6 = V_6 -> V_13 ;
else {
F_3 ( V_2 -> V_14 != V_8 -> V_14 ) ;
if ( V_2 -> V_14 < V_8 -> V_14 )
V_6 = V_6 -> V_12 ;
else
V_6 = V_6 -> V_13 ;
}
}
return 0 ;
}
static void F_19 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
int V_29 = V_16 -> V_30 - 1 ;
if ( V_29 < 0 )
V_29 = V_31 - 1 ;
F_3 ( V_29 >= 0 && V_29 < V_31 ) ;
F_20 ( & V_2 -> V_9 . V_26 , & V_16 -> V_32 [ V_29 ] ) ;
F_21 ( L_2 , V_2 -> V_14 , V_2 -> V_11 ) ;
}
static struct V_1 * F_22 ( struct V_15 * V_16 ,
struct V_3 * V_4 , int V_33 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * V_34 = NULL ;
int V_35 ;
V_2 = F_2 ( F_23 ( V_4 ) , struct V_1 , V_9 . V_10 ) ;
V_35 = V_2 -> V_11 + V_33 ;
V_6 = V_4 -> V_5 ;
while ( V_6 ) {
struct V_1 * V_8 ;
V_8 = F_2 ( V_6 , struct V_1 , V_9 . V_10 ) ;
if ( V_8 -> V_11 >= V_35 )
V_6 = V_6 -> V_12 ;
else {
V_6 = V_6 -> V_13 ;
V_34 = V_2 ;
V_2 = V_8 ;
}
}
if ( V_34 && ! V_16 -> V_36 &&
! V_16 -> V_37 && V_2 -> V_14 < V_38 )
return V_34 ;
return V_2 ;
}
static struct V_1 * F_24 ( struct V_15 * V_16 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 , * V_39 , * V_40 ;
V_39 = F_2 ( F_23 ( V_4 ) , struct V_1 , V_9 . V_10 ) ;
V_40 = F_2 ( F_25 ( V_4 ) , struct V_1 , V_9 . V_10 ) ;
if ( V_40 -> V_11 - V_39 -> V_11 < V_41 ) {
V_2 = F_2 ( V_4 -> V_5 , struct V_1 , V_9 . V_10 ) ;
V_2 = F_26 ( V_16 , V_2 , V_4 ) ;
} else
V_2 = F_22 ( V_16 , V_4 , V_41 / 2 ) ;
return V_2 ;
}
static struct V_1 * F_27 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
V_2 = F_24 ( V_16 , & V_16 -> free ) ;
if ( ! V_2 ) {
F_17 ( V_16 , L_3 ) ;
return NULL ;
}
F_28 ( V_16 , V_2 , & V_16 -> free ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> free ) ;
V_16 -> V_42 -- ;
F_21 ( L_4 , V_2 -> V_14 , V_2 -> V_11 ) ;
return V_2 ;
}
static int F_30 ( struct V_15 * V_16 , int V_14 )
{
struct V_1 * V_2 ;
V_2 = V_16 -> V_17 [ V_14 ] ;
if ( ! V_2 )
return - V_43 ;
if ( F_31 ( V_16 , V_2 ) )
return - V_43 ;
F_16 ( & V_2 -> V_9 . V_26 ) ;
F_21 ( L_5 , V_2 -> V_14 ) ;
return 0 ;
}
static int F_32 ( struct V_15 * V_16 , struct V_1 * V_2 ,
int V_44 )
{
int V_19 ;
struct V_45 * V_46 ;
unsigned long long V_11 = V_2 -> V_11 ;
F_21 ( L_6 , V_2 -> V_14 , V_11 ) ;
V_19 = F_33 ( V_16 , V_2 -> V_14 , V_2 -> V_11 ) ;
if ( V_19 )
return - V_47 ;
V_46 = F_34 ( V_16 -> V_48 , V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_19 = F_35 ( V_16 , V_2 -> V_14 , V_44 ) ;
if ( V_19 < 0 )
goto V_51;
V_11 += V_19 ;
if ( V_11 > V_52 ) {
F_17 ( V_16 , L_7 ,
V_2 -> V_14 , V_11 ) ;
V_19 = - V_47 ;
goto V_51;
}
F_21 ( L_8 , V_2 -> V_14 , V_11 ) ;
V_46 -> V_11 = F_36 ( V_11 ) ;
V_19 = F_37 ( V_16 , V_2 -> V_14 , V_46 ) ;
if ( V_19 )
goto V_51;
V_2 -> V_11 = V_11 ;
F_11 ( & V_16 -> V_23 ) ;
if ( V_2 -> V_11 > V_16 -> V_53 )
V_16 -> V_53 = V_2 -> V_11 ;
F_13 ( & V_16 -> V_23 ) ;
V_51:
F_38 ( V_46 ) ;
return V_19 ;
}
static void F_39 ( struct V_15 * V_16 )
{
struct V_1 * V_2 , * V_54 ;
int V_55 ;
V_56:
V_55 = 0 ;
F_11 ( & V_16 -> V_23 ) ;
F_40 (e, tmp, &ubi->pq[ubi->pq_head], u.list) {
F_21 ( L_9 ,
V_2 -> V_14 , V_2 -> V_11 ) ;
F_16 ( & V_2 -> V_9 . V_26 ) ;
F_1 ( V_2 , & V_16 -> V_57 ) ;
if ( V_55 ++ > 32 ) {
F_13 ( & V_16 -> V_23 ) ;
F_9 () ;
goto V_56;
}
}
V_16 -> V_30 += 1 ;
if ( V_16 -> V_30 == V_31 )
V_16 -> V_30 = 0 ;
F_3 ( V_16 -> V_30 >= 0 && V_16 -> V_30 < V_31 ) ;
F_13 ( & V_16 -> V_23 ) ;
}
static void F_41 ( struct V_15 * V_16 , struct V_20 * V_21 )
{
F_11 ( & V_16 -> V_23 ) ;
F_20 ( & V_21 -> V_26 , & V_16 -> V_24 ) ;
F_3 ( V_16 -> V_27 >= 0 ) ;
V_16 -> V_27 += 1 ;
if ( V_16 -> V_58 && ! F_42 ( V_16 ) )
F_43 ( V_16 -> V_59 ) ;
F_13 ( & V_16 -> V_23 ) ;
}
static void F_44 ( struct V_15 * V_16 , struct V_20 * V_21 )
{
F_10 ( & V_16 -> V_22 ) ;
F_41 ( V_16 , V_21 ) ;
F_14 ( & V_16 -> V_22 ) ;
}
static int F_45 ( struct V_15 * V_16 , struct V_1 * V_2 ,
int V_60 , int V_61 , int V_44 )
{
struct V_20 * V_62 ;
F_3 ( V_2 ) ;
F_21 ( L_10 ,
V_2 -> V_14 , V_2 -> V_11 , V_44 ) ;
V_62 = F_46 ( sizeof( struct V_20 ) , V_49 ) ;
if ( ! V_62 )
return - V_50 ;
V_62 -> V_28 = & V_63 ;
V_62 -> V_2 = V_2 ;
V_62 -> V_60 = V_60 ;
V_62 -> V_61 = V_61 ;
V_62 -> V_44 = V_44 ;
F_44 ( V_16 , V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_15 * V_16 , struct V_1 * V_2 ,
int V_60 , int V_61 , int V_44 )
{
struct V_20 V_62 ;
F_21 ( L_11 , V_2 -> V_14 ) ;
V_62 . V_2 = V_2 ;
V_62 . V_60 = V_60 ;
V_62 . V_61 = V_61 ;
V_62 . V_44 = V_44 ;
return F_48 ( V_16 , & V_62 ) ;
}
static int F_49 ( struct V_15 * V_16 , int V_64 )
{
int V_19 = 0 ;
struct V_1 * V_8 ;
struct V_1 * V_65 ;
struct V_20 * V_21 ;
F_11 ( & V_16 -> V_23 ) ;
if ( V_16 -> V_66 )
goto V_67;
if ( ! V_16 -> V_68 . V_5 ) {
if ( ! V_16 -> V_57 . V_5 || ! V_16 -> free . V_5 )
goto V_67;
V_8 = F_2 ( F_23 ( & V_16 -> V_57 ) , struct V_1 , V_9 . V_10 ) ;
V_65 = F_22 ( V_16 , & V_16 -> free , V_41 ) ;
if ( ! ( V_65 -> V_11 - V_8 -> V_11 >= V_69 ) )
goto V_67;
F_21 ( L_12 ) ;
} else
F_21 ( L_13 ) ;
V_16 -> V_66 = 1 ;
F_13 ( & V_16 -> V_23 ) ;
V_21 = F_46 ( sizeof( struct V_20 ) , V_49 ) ;
if ( ! V_21 ) {
V_19 = - V_50 ;
goto V_70;
}
V_21 -> V_71 = 0 ;
V_21 -> V_28 = & V_72 ;
if ( V_64 )
F_41 ( V_16 , V_21 ) ;
else
F_44 ( V_16 , V_21 ) ;
return V_19 ;
V_70:
F_11 ( & V_16 -> V_23 ) ;
V_16 -> V_66 = 0 ;
V_67:
F_13 ( & V_16 -> V_23 ) ;
return V_19 ;
}
static int F_48 ( struct V_15 * V_16 , struct V_20 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
int V_14 = V_2 -> V_14 ;
int V_60 = V_62 -> V_60 ;
int V_61 = V_62 -> V_61 ;
int V_19 , V_73 = 0 ;
F_21 ( L_14 ,
V_14 , V_2 -> V_11 , V_62 -> V_60 , V_62 -> V_61 ) ;
V_19 = F_32 ( V_16 , V_2 , V_62 -> V_44 ) ;
if ( ! V_19 ) {
F_11 ( & V_16 -> V_23 ) ;
F_1 ( V_2 , & V_16 -> free ) ;
V_16 -> V_42 ++ ;
F_13 ( & V_16 -> V_23 ) ;
F_39 ( V_16 ) ;
V_19 = F_49 ( V_16 , 1 ) ;
return V_19 ;
}
F_17 ( V_16 , L_15 , V_14 , V_19 ) ;
if ( V_19 == - V_74 || V_19 == - V_50 || V_19 == - V_75 ||
V_19 == - V_76 ) {
int V_77 ;
V_77 = F_45 ( V_16 , V_2 , V_60 , V_61 , 0 ) ;
if ( V_77 ) {
F_6 ( V_16 , V_2 ) ;
V_19 = V_77 ;
goto V_78;
}
return V_19 ;
}
F_6 ( V_16 , V_2 ) ;
if ( V_19 != - V_79 )
goto V_78;
if ( ! V_16 -> V_80 ) {
F_17 ( V_16 , L_16 , V_14 ) ;
goto V_78;
}
F_11 ( & V_16 -> V_81 ) ;
if ( V_16 -> V_82 == 0 ) {
if ( V_16 -> V_83 == 0 ) {
F_13 ( & V_16 -> V_81 ) ;
F_17 ( V_16 , L_17 ) ;
goto V_78;
}
V_16 -> V_83 -= 1 ;
V_73 = 1 ;
}
F_13 ( & V_16 -> V_81 ) ;
F_50 ( V_16 , L_18 , V_14 ) ;
V_19 = F_51 ( V_16 , V_14 ) ;
if ( V_19 )
goto V_78;
F_11 ( & V_16 -> V_81 ) ;
if ( V_16 -> V_82 > 0 ) {
if ( V_73 ) {
V_16 -> V_83 += 1 ;
V_73 = 0 ;
}
V_16 -> V_82 -= 1 ;
}
V_16 -> V_84 += 1 ;
V_16 -> V_85 -= 1 ;
F_52 ( V_16 ) ;
if ( V_73 )
F_53 ( V_16 , L_19 ) ;
else if ( V_16 -> V_82 )
F_50 ( V_16 , L_20 ,
V_16 -> V_82 ) ;
else
F_53 ( V_16 , L_21 ) ;
F_13 ( & V_16 -> V_81 ) ;
return V_19 ;
V_78:
if ( V_73 ) {
F_11 ( & V_16 -> V_81 ) ;
V_16 -> V_83 += 1 ;
F_13 ( & V_16 -> V_81 ) ;
}
F_54 ( V_16 ) ;
return V_19 ;
}
static int V_63 ( struct V_15 * V_16 , struct V_20 * V_62 ,
int V_86 )
{
int V_87 ;
if ( V_86 ) {
struct V_1 * V_2 = V_62 -> V_2 ;
F_21 ( L_22 , V_2 -> V_14 , V_2 -> V_11 ) ;
F_38 ( V_62 ) ;
F_6 ( V_16 , V_2 ) ;
return 0 ;
}
V_87 = F_48 ( V_16 , V_62 ) ;
F_38 ( V_62 ) ;
return V_87 ;
}
int F_55 ( struct V_15 * V_16 , int V_60 , int V_61 ,
int V_14 , int V_44 )
{
int V_19 ;
struct V_1 * V_2 ;
F_21 ( L_23 , V_14 ) ;
F_3 ( V_14 >= 0 ) ;
F_3 ( V_14 < V_16 -> V_88 ) ;
F_10 ( & V_16 -> V_89 ) ;
V_90:
F_11 ( & V_16 -> V_23 ) ;
V_2 = V_16 -> V_17 [ V_14 ] ;
if ( V_2 == V_16 -> V_91 ) {
F_21 ( L_24 , V_14 ) ;
F_13 ( & V_16 -> V_23 ) ;
F_56 ( & V_16 -> V_92 ) ;
F_57 ( & V_16 -> V_92 ) ;
goto V_90;
} else if ( V_2 == V_16 -> V_93 ) {
F_21 ( L_25 , V_14 ) ;
F_3 ( ! V_16 -> V_94 ) ;
V_16 -> V_94 = 1 ;
F_13 ( & V_16 -> V_23 ) ;
F_14 ( & V_16 -> V_89 ) ;
return 0 ;
} else {
if ( F_18 ( V_2 , & V_16 -> V_57 ) ) {
F_28 ( V_16 , V_2 , & V_16 -> V_57 ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> V_57 ) ;
} else if ( F_18 ( V_2 , & V_16 -> V_68 ) ) {
F_28 ( V_16 , V_2 , & V_16 -> V_68 ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> V_68 ) ;
} else if ( F_18 ( V_2 , & V_16 -> V_95 ) ) {
F_28 ( V_16 , V_2 , & V_16 -> V_95 ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> V_95 ) ;
V_16 -> V_96 -= 1 ;
F_3 ( V_16 -> V_96 >= 0 ) ;
V_44 = 1 ;
} else {
V_19 = F_30 ( V_16 , V_2 -> V_14 ) ;
if ( V_19 ) {
F_17 ( V_16 , L_26 , V_14 ) ;
F_54 ( V_16 ) ;
F_13 ( & V_16 -> V_23 ) ;
F_14 ( & V_16 -> V_89 ) ;
return V_19 ;
}
}
}
F_13 ( & V_16 -> V_23 ) ;
V_19 = F_45 ( V_16 , V_2 , V_60 , V_61 , V_44 ) ;
if ( V_19 ) {
F_11 ( & V_16 -> V_23 ) ;
F_1 ( V_2 , & V_16 -> V_57 ) ;
F_13 ( & V_16 -> V_23 ) ;
}
F_14 ( & V_16 -> V_89 ) ;
return V_19 ;
}
int F_58 ( struct V_15 * V_16 , int V_14 )
{
struct V_1 * V_2 ;
F_50 ( V_16 , L_27 , V_14 ) ;
V_90:
F_11 ( & V_16 -> V_23 ) ;
V_2 = V_16 -> V_17 [ V_14 ] ;
if ( V_2 == V_16 -> V_91 || F_18 ( V_2 , & V_16 -> V_68 ) ||
F_18 ( V_2 , & V_16 -> V_95 ) ) {
F_13 ( & V_16 -> V_23 ) ;
return 0 ;
}
if ( V_2 == V_16 -> V_93 ) {
F_13 ( & V_16 -> V_23 ) ;
F_21 ( L_28 , V_14 ) ;
F_59 () ;
goto V_90;
}
if ( F_18 ( V_2 , & V_16 -> V_57 ) ) {
F_28 ( V_16 , V_2 , & V_16 -> V_57 ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> V_57 ) ;
} else {
int V_19 ;
V_19 = F_30 ( V_16 , V_2 -> V_14 ) ;
if ( V_19 ) {
F_17 ( V_16 , L_26 , V_14 ) ;
F_54 ( V_16 ) ;
F_13 ( & V_16 -> V_23 ) ;
return V_19 ;
}
}
F_1 ( V_2 , & V_16 -> V_68 ) ;
F_13 ( & V_16 -> V_23 ) ;
return F_49 ( V_16 , 0 ) ;
}
int F_60 ( struct V_15 * V_16 , int V_60 , int V_61 )
{
int V_19 = 0 ;
int V_97 = 1 ;
F_21 ( L_29 ,
V_60 , V_61 , V_16 -> V_27 ) ;
while ( V_97 ) {
struct V_20 * V_21 , * V_54 ;
V_97 = 0 ;
F_10 ( & V_16 -> V_22 ) ;
F_11 ( & V_16 -> V_23 ) ;
F_40 (wrk, tmp, &ubi->works, list) {
if ( ( V_60 == V_98 || V_21 -> V_60 == V_60 ) &&
( V_61 == V_98 || V_21 -> V_61 == V_61 ) ) {
F_16 ( & V_21 -> V_26 ) ;
V_16 -> V_27 -= 1 ;
F_3 ( V_16 -> V_27 >= 0 ) ;
F_13 ( & V_16 -> V_23 ) ;
V_19 = V_21 -> V_28 ( V_16 , V_21 , 0 ) ;
if ( V_19 ) {
F_14 ( & V_16 -> V_22 ) ;
return V_19 ;
}
F_11 ( & V_16 -> V_23 ) ;
V_97 = 1 ;
break;
}
}
F_13 ( & V_16 -> V_23 ) ;
F_14 ( & V_16 -> V_22 ) ;
}
F_61 ( & V_16 -> V_22 ) ;
F_62 ( & V_16 -> V_22 ) ;
return V_19 ;
}
static void F_63 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
struct V_5 * V_10 ;
struct V_1 * V_2 ;
V_10 = V_4 -> V_5 ;
while ( V_10 ) {
if ( V_10 -> V_12 )
V_10 = V_10 -> V_12 ;
else if ( V_10 -> V_13 )
V_10 = V_10 -> V_13 ;
else {
V_2 = F_2 ( V_10 , struct V_1 , V_9 . V_10 ) ;
V_10 = F_64 ( V_10 ) ;
if ( V_10 ) {
if ( V_10 -> V_12 == & V_2 -> V_9 . V_10 )
V_10 -> V_12 = NULL ;
else
V_10 -> V_13 = NULL ;
}
F_6 ( V_16 , V_2 ) ;
}
}
}
int F_65 ( void * V_9 )
{
int V_99 = 0 ;
struct V_15 * V_16 = V_9 ;
F_50 ( V_16 , L_30 ,
V_16 -> V_100 , F_66 ( V_101 ) ) ;
F_67 () ;
for (; ; ) {
int V_19 ;
if ( F_68 () )
break;
if ( F_69 () )
continue;
F_11 ( & V_16 -> V_23 ) ;
if ( F_12 ( & V_16 -> V_24 ) || V_16 -> V_102 ||
! V_16 -> V_58 || F_42 ( V_16 ) ) {
F_70 ( V_103 ) ;
F_13 ( & V_16 -> V_23 ) ;
F_71 () ;
continue;
}
F_13 ( & V_16 -> V_23 ) ;
V_19 = F_8 ( V_16 ) ;
if ( V_19 ) {
F_17 ( V_16 , L_31 ,
V_16 -> V_100 , V_19 ) ;
if ( V_99 ++ > V_104 ) {
F_50 ( V_16 , L_32 ,
V_16 -> V_100 , V_104 ) ;
F_54 ( V_16 ) ;
V_16 -> V_58 = 0 ;
continue;
}
} else
V_99 = 0 ;
F_9 () ;
}
F_21 ( L_33 , V_16 -> V_100 ) ;
return 0 ;
}
static void F_72 ( struct V_15 * V_16 )
{
#ifdef F_73
F_74 ( & V_16 -> V_105 ) ;
#endif
while ( ! F_12 ( & V_16 -> V_24 ) ) {
struct V_20 * V_21 ;
V_21 = F_15 ( V_16 -> V_24 . V_25 , struct V_20 , V_26 ) ;
F_16 ( & V_21 -> V_26 ) ;
V_21 -> V_28 ( V_16 , V_21 , 1 ) ;
V_16 -> V_27 -= 1 ;
F_3 ( V_16 -> V_27 >= 0 ) ;
}
}
int F_75 ( struct V_15 * V_16 , struct V_106 * V_107 )
{
int V_19 , V_108 , V_109 , V_110 = 0 ;
struct V_5 * V_111 , * V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 , * V_54 ;
struct V_1 * V_2 ;
V_16 -> V_57 = V_16 -> V_95 = V_16 -> free = V_16 -> V_68 = V_117 ;
F_76 ( & V_16 -> V_23 ) ;
F_77 ( & V_16 -> V_92 ) ;
F_78 ( & V_16 -> V_22 ) ;
V_16 -> V_53 = V_107 -> V_53 ;
F_79 ( & V_16 -> V_24 ) ;
sprintf ( V_16 -> V_100 , V_118 , V_16 -> V_119 ) ;
V_19 = - V_50 ;
V_16 -> V_17 = F_34 ( V_16 -> V_88 * sizeof( void * ) , V_120 ) ;
if ( ! V_16 -> V_17 )
return V_19 ;
for ( V_108 = 0 ; V_108 < V_31 ; V_108 ++ )
F_79 ( & V_16 -> V_32 [ V_108 ] ) ;
V_16 -> V_30 = 0 ;
V_16 -> V_42 = 0 ;
F_40 (aeb, tmp, &ai->erase, u.list) {
F_9 () ;
V_2 = F_80 ( V_18 , V_120 ) ;
if ( ! V_2 )
goto V_51;
V_2 -> V_14 = V_116 -> V_14 ;
V_2 -> V_11 = V_116 -> V_11 ;
V_16 -> V_17 [ V_2 -> V_14 ] = V_2 ;
if ( F_45 ( V_16 , V_2 , V_116 -> V_60 , V_116 -> V_61 , 0 ) ) {
F_6 ( V_16 , V_2 ) ;
goto V_51;
}
V_110 ++ ;
}
F_81 (aeb, &ai->free, u.list) {
F_9 () ;
V_2 = F_80 ( V_18 , V_120 ) ;
if ( ! V_2 )
goto V_51;
V_2 -> V_14 = V_116 -> V_14 ;
V_2 -> V_11 = V_116 -> V_11 ;
F_3 ( V_2 -> V_11 >= 0 ) ;
F_1 ( V_2 , & V_16 -> free ) ;
V_16 -> V_42 ++ ;
V_16 -> V_17 [ V_2 -> V_14 ] = V_2 ;
V_110 ++ ;
}
F_82 (rb1, av, &ai->volumes, rb) {
F_82 (rb2, aeb, &av->root, u.rb) {
F_9 () ;
V_2 = F_80 ( V_18 , V_120 ) ;
if ( ! V_2 )
goto V_51;
V_2 -> V_14 = V_116 -> V_14 ;
V_2 -> V_11 = V_116 -> V_11 ;
V_16 -> V_17 [ V_2 -> V_14 ] = V_2 ;
if ( ! V_116 -> V_68 ) {
F_21 ( L_34 ,
V_2 -> V_14 , V_2 -> V_11 ) ;
F_1 ( V_2 , & V_16 -> V_57 ) ;
} else {
F_21 ( L_35 ,
V_2 -> V_14 , V_2 -> V_11 ) ;
F_1 ( V_2 , & V_16 -> V_68 ) ;
}
V_110 ++ ;
}
}
F_81 (aeb, &ai->fastmap, u.list) {
F_9 () ;
V_2 = F_83 ( V_16 , V_116 -> V_14 ) ;
if ( V_2 ) {
F_3 ( ! V_16 -> V_17 [ V_2 -> V_14 ] ) ;
V_16 -> V_17 [ V_2 -> V_14 ] = V_2 ;
} else {
if ( V_16 -> V_17 [ V_116 -> V_14 ] )
continue;
V_2 = F_80 ( V_18 , V_120 ) ;
if ( ! V_2 )
goto V_51;
V_2 -> V_14 = V_116 -> V_14 ;
V_2 -> V_11 = V_116 -> V_11 ;
F_3 ( ! V_16 -> V_17 [ V_2 -> V_14 ] ) ;
V_16 -> V_17 [ V_2 -> V_14 ] = V_2 ;
if ( F_45 ( V_16 , V_2 , V_116 -> V_60 , V_116 -> V_61 , 0 ) ) {
F_6 ( V_16 , V_2 ) ;
goto V_51;
}
}
V_110 ++ ;
}
F_21 ( L_36 , V_110 ) ;
F_3 ( V_16 -> V_85 == V_110 ) ;
V_109 = V_121 ;
F_84 ( V_16 , & V_109 ) ;
if ( V_16 -> V_83 < V_109 ) {
F_17 ( V_16 , L_37 ,
V_16 -> V_83 , V_109 ) ;
if ( V_16 -> V_122 )
F_17 ( V_16 , L_38 ,
V_16 -> V_122 ) ;
V_19 = - V_123 ;
goto V_51;
}
V_16 -> V_83 -= V_109 ;
V_16 -> V_124 += V_109 ;
V_19 = F_49 ( V_16 , 0 ) ;
if ( V_19 )
goto V_51;
return 0 ;
V_51:
F_72 ( V_16 ) ;
F_63 ( V_16 , & V_16 -> V_57 ) ;
F_63 ( V_16 , & V_16 -> free ) ;
F_63 ( V_16 , & V_16 -> V_68 ) ;
F_38 ( V_16 -> V_17 ) ;
return V_19 ;
}
static void F_85 ( struct V_15 * V_16 )
{
int V_108 ;
struct V_1 * V_2 , * V_54 ;
for ( V_108 = 0 ; V_108 < V_31 ; ++ V_108 ) {
F_40 (e, tmp, &ubi->pq[i], u.list) {
F_16 ( & V_2 -> V_9 . V_26 ) ;
F_6 ( V_16 , V_2 ) ;
}
}
}
void F_86 ( struct V_15 * V_16 )
{
F_21 ( L_39 ) ;
F_87 ( V_16 ) ;
F_72 ( V_16 ) ;
F_85 ( V_16 ) ;
F_63 ( V_16 , & V_16 -> V_57 ) ;
F_63 ( V_16 , & V_16 -> V_95 ) ;
F_63 ( V_16 , & V_16 -> free ) ;
F_63 ( V_16 , & V_16 -> V_68 ) ;
F_38 ( V_16 -> V_17 ) ;
}
static int F_33 ( struct V_15 * V_16 , int V_14 , int V_11 )
{
int V_19 ;
long long V_125 ;
struct V_45 * V_46 ;
if ( ! F_88 ( V_16 ) )
return 0 ;
V_46 = F_34 ( V_16 -> V_48 , V_49 ) ;
if ( ! V_46 )
return - V_50 ;
V_19 = F_89 ( V_16 , V_14 , V_46 , 0 ) ;
if ( V_19 && V_19 != V_126 ) {
V_19 = 0 ;
goto V_51;
}
V_125 = F_90 ( V_46 -> V_11 ) ;
if ( V_11 != V_125 && V_125 - V_11 > 1 ) {
F_17 ( V_16 , L_40 , V_14 ) ;
F_17 ( V_16 , L_41 , V_125 , V_11 ) ;
F_91 () ;
V_19 = 1 ;
} else
V_19 = 0 ;
V_51:
F_38 ( V_46 ) ;
return V_19 ;
}
static int F_28 ( const struct V_15 * V_16 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! F_88 ( V_16 ) )
return 0 ;
if ( F_18 ( V_2 , V_4 ) )
return 0 ;
F_17 ( V_16 , L_42 ,
V_2 -> V_14 , V_2 -> V_11 , V_4 ) ;
F_91 () ;
return - V_47 ;
}
static int F_31 ( const struct V_15 * V_16 ,
struct V_1 * V_2 )
{
struct V_1 * V_6 ;
int V_108 ;
if ( ! F_88 ( V_16 ) )
return 0 ;
for ( V_108 = 0 ; V_108 < V_31 ; ++ V_108 )
F_81 (p, &ubi->pq[i], u.list)
if ( V_6 == V_2 )
return 0 ;
F_17 ( V_16 , L_43 ,
V_2 -> V_14 , V_2 -> V_11 ) ;
F_91 () ;
return - V_47 ;
}
static struct V_1 * F_92 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
V_2 = F_22 ( V_16 , & V_16 -> free , V_41 ) ;
F_28 ( V_16 , V_2 , & V_16 -> free ) ;
V_16 -> V_42 -- ;
F_3 ( V_16 -> V_42 >= 0 ) ;
F_29 ( & V_2 -> V_9 . V_10 , & V_16 -> free ) ;
return V_2 ;
}
static int F_93 ( struct V_15 * V_16 )
{
int V_19 ;
while ( ! V_16 -> free . V_5 && V_16 -> V_27 ) {
F_13 ( & V_16 -> V_23 ) ;
F_21 ( L_44 ) ;
V_19 = F_8 ( V_16 ) ;
F_11 ( & V_16 -> V_23 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
int F_94 ( struct V_15 * V_16 )
{
int V_19 ;
struct V_1 * V_2 ;
V_90:
F_10 ( & V_16 -> V_127 ) ;
F_11 ( & V_16 -> V_23 ) ;
if ( ! V_16 -> free . V_5 ) {
if ( V_16 -> V_27 == 0 ) {
F_17 ( V_16 , L_3 ) ;
F_3 ( F_12 ( & V_16 -> V_24 ) ) ;
F_13 ( & V_16 -> V_23 ) ;
return - V_123 ;
}
V_19 = F_93 ( V_16 ) ;
if ( V_19 < 0 ) {
F_13 ( & V_16 -> V_23 ) ;
return V_19 ;
}
F_13 ( & V_16 -> V_23 ) ;
F_14 ( & V_16 -> V_127 ) ;
goto V_90;
}
V_2 = F_27 ( V_16 ) ;
F_19 ( V_16 , V_2 ) ;
F_13 ( & V_16 -> V_23 ) ;
V_19 = F_95 ( V_16 , V_2 -> V_14 , V_16 -> V_128 ,
V_16 -> V_129 - V_16 -> V_128 ) ;
if ( V_19 ) {
F_17 ( V_16 , L_45 , V_2 -> V_14 ) ;
return V_19 ;
}
return V_2 -> V_14 ;
}
