static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 ) ;
}
static int F_4 ( struct V_3 * V_4 , int V_6 )
{
int V_7 ;
if ( ! V_4 -> V_8 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_8 -> V_9 ; V_7 ++ )
if ( V_4 -> V_8 -> V_10 [ V_7 ] -> V_6 == V_6 )
return 1 ;
return 0 ;
}
static int F_4 ( struct V_3 * V_4 , int V_6 )
{
return 0 ;
}
static void F_5 ( struct V_11 * V_10 , struct V_12 * V_13 )
{
struct V_14 * * V_15 , * V_16 = NULL ;
V_15 = & V_13 -> V_14 ;
while ( * V_15 ) {
struct V_11 * V_17 ;
V_16 = * V_15 ;
V_17 = F_6 ( V_16 , struct V_11 , V_18 . V_19 ) ;
if ( V_10 -> V_20 < V_17 -> V_20 )
V_15 = & ( * V_15 ) -> V_21 ;
else if ( V_10 -> V_20 > V_17 -> V_20 )
V_15 = & ( * V_15 ) -> V_22 ;
else {
F_7 ( V_10 -> V_6 != V_17 -> V_6 ) ;
if ( V_10 -> V_6 < V_17 -> V_6 )
V_15 = & ( * V_15 ) -> V_21 ;
else
V_15 = & ( * V_15 ) -> V_22 ;
}
}
F_8 ( & V_10 -> V_18 . V_19 , V_16 , V_15 ) ;
F_9 ( & V_10 -> V_18 . V_19 , V_13 ) ;
}
static int F_10 ( struct V_3 * V_4 )
{
int V_23 ;
struct V_24 * V_2 ;
F_11 () ;
F_12 ( & V_4 -> V_25 ) ;
F_13 ( & V_4 -> V_26 ) ;
if ( F_14 ( & V_4 -> V_27 ) ) {
F_15 ( & V_4 -> V_26 ) ;
F_16 ( & V_4 -> V_25 ) ;
return 0 ;
}
V_2 = F_17 ( V_4 -> V_27 . V_28 , struct V_24 , V_29 ) ;
F_18 ( & V_2 -> V_29 ) ;
V_4 -> V_30 -= 1 ;
F_7 ( V_4 -> V_30 >= 0 ) ;
F_15 ( & V_4 -> V_26 ) ;
V_23 = V_2 -> V_31 ( V_4 , V_2 , 0 ) ;
if ( V_23 )
F_19 ( L_1 , V_23 ) ;
F_16 ( & V_4 -> V_25 ) ;
return V_23 ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_23 ;
while ( ! V_4 -> free . V_14 ) {
F_15 ( & V_4 -> V_26 ) ;
F_21 ( L_2 ) ;
V_23 = F_10 ( V_4 ) ;
F_13 ( & V_4 -> V_26 ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_22 ( struct V_11 * V_10 , struct V_12 * V_13 )
{
struct V_14 * V_15 ;
V_15 = V_13 -> V_14 ;
while ( V_15 ) {
struct V_11 * V_17 ;
V_17 = F_6 ( V_15 , struct V_11 , V_18 . V_19 ) ;
if ( V_10 -> V_6 == V_17 -> V_6 ) {
F_7 ( V_10 == V_17 ) ;
return 1 ;
}
if ( V_10 -> V_20 < V_17 -> V_20 )
V_15 = V_15 -> V_21 ;
else if ( V_10 -> V_20 > V_17 -> V_20 )
V_15 = V_15 -> V_22 ;
else {
F_7 ( V_10 -> V_6 != V_17 -> V_6 ) ;
if ( V_10 -> V_6 < V_17 -> V_6 )
V_15 = V_15 -> V_21 ;
else
V_15 = V_15 -> V_22 ;
}
}
return 0 ;
}
static void F_23 ( struct V_3 * V_4 , struct V_11 * V_10 )
{
int V_32 = V_4 -> V_33 - 1 ;
if ( V_32 < 0 )
V_32 = V_34 - 1 ;
F_7 ( V_32 >= 0 && V_32 < V_34 ) ;
F_24 ( & V_10 -> V_18 . V_29 , & V_4 -> V_35 [ V_32 ] ) ;
F_21 ( L_3 , V_10 -> V_6 , V_10 -> V_20 ) ;
}
static struct V_11 * F_25 ( struct V_3 * V_4 ,
struct V_12 * V_13 , int V_36 )
{
struct V_14 * V_15 ;
struct V_11 * V_10 , * V_37 = NULL ;
int V_38 ;
V_10 = F_6 ( F_26 ( V_13 ) , struct V_11 , V_18 . V_19 ) ;
V_38 = V_10 -> V_20 + V_36 ;
V_15 = V_13 -> V_14 ;
while ( V_15 ) {
struct V_11 * V_17 ;
V_17 = F_6 ( V_15 , struct V_11 , V_18 . V_19 ) ;
if ( V_17 -> V_20 >= V_38 )
V_15 = V_15 -> V_21 ;
else {
V_15 = V_15 -> V_22 ;
V_37 = V_10 ;
V_10 = V_17 ;
}
}
if ( V_37 && ! V_4 -> V_39 &&
! V_4 -> V_8 && V_10 -> V_6 < V_40 )
return V_37 ;
return V_10 ;
}
static struct V_11 * F_27 ( struct V_3 * V_4 ,
struct V_12 * V_13 )
{
struct V_11 * V_10 , * V_41 , * V_42 ;
V_41 = F_6 ( F_26 ( V_13 ) , struct V_11 , V_18 . V_19 ) ;
V_42 = F_6 ( F_28 ( V_13 ) , struct V_11 , V_18 . V_19 ) ;
if ( V_42 -> V_20 - V_41 -> V_20 < V_43 ) {
V_10 = F_6 ( V_13 -> V_14 , struct V_11 , V_18 . V_19 ) ;
#ifdef F_29
if ( V_10 && ! V_4 -> V_39 && ! V_4 -> V_8 &&
V_10 -> V_6 < V_40 )
V_10 = F_6 ( F_30 ( V_13 -> V_14 ) ,
struct V_11 , V_18 . V_19 ) ;
#endif
} else
V_10 = F_25 ( V_4 , V_13 , V_43 / 2 ) ;
return V_10 ;
}
static struct V_11 * F_31 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_11 * V_10 , * V_44 = NULL ;
int V_45 = V_46 ;
F_32 (p, e, root, u.rb) {
if ( V_10 -> V_6 < V_40 && V_10 -> V_20 < V_45 ) {
V_44 = V_10 ;
V_45 = V_10 -> V_20 ;
}
}
return V_44 ;
}
static int F_33 ( struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_11 * V_10 ;
F_32 (p, e, root, u.rb)
if ( V_10 -> V_6 < V_40 )
return 1 ;
return 0 ;
}
struct V_11 * F_34 ( struct V_3 * V_4 , int V_47 )
{
struct V_11 * V_10 = NULL ;
if ( ! V_4 -> free . V_14 || ( V_4 -> V_48 - V_4 -> V_49 < 1 ) )
goto V_50;
if ( V_47 )
V_10 = F_31 ( & V_4 -> free ) ;
else
V_10 = F_27 ( V_4 , & V_4 -> free ) ;
if ( ! V_10 )
goto V_50;
F_35 ( V_4 , V_10 , & V_4 -> free ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> free ) ;
V_4 -> V_48 -- ;
V_50:
return V_10 ;
}
static int F_37 ( struct V_3 * V_4 )
{
int V_23 ;
struct V_11 * V_10 ;
V_51:
if ( ! V_4 -> free . V_14 ) {
if ( V_4 -> V_30 == 0 ) {
F_19 ( L_4 ) ;
F_7 ( F_14 ( & V_4 -> V_27 ) ) ;
return - V_52 ;
}
V_23 = F_20 ( V_4 ) ;
if ( V_23 < 0 )
return V_23 ;
goto V_51;
}
V_10 = F_27 ( V_4 , & V_4 -> free ) ;
if ( ! V_10 ) {
F_19 ( L_4 ) ;
return - V_52 ;
}
F_35 ( V_4 , V_10 , & V_4 -> free ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> free ) ;
V_4 -> V_48 -- ;
F_21 ( L_5 , V_10 -> V_6 , V_10 -> V_20 ) ;
#ifndef F_29
F_23 ( V_4 , V_10 ) ;
#endif
return V_10 -> V_6 ;
}
static void F_38 ( struct V_3 * V_4 ,
struct V_53 * V_54 )
{
int V_7 ;
struct V_11 * V_10 ;
for ( V_7 = V_54 -> V_55 ; V_7 < V_54 -> V_56 ; V_7 ++ ) {
V_10 = V_4 -> V_57 [ V_54 -> V_58 [ V_7 ] ] ;
F_5 ( V_10 , & V_4 -> free ) ;
V_4 -> V_48 ++ ;
}
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_11 * V_10 ;
struct V_53 * V_54 = & V_4 -> V_59 ;
F_38 ( V_4 , V_54 ) ;
for ( V_54 -> V_56 = 0 ; V_54 -> V_56 < V_54 -> V_60 ; V_54 -> V_56 ++ ) {
if ( ! V_4 -> free . V_14 ||
( V_4 -> V_48 - V_4 -> V_49 < 5 ) )
break;
V_10 = F_25 ( V_4 , & V_4 -> free , V_43 ) ;
F_35 ( V_4 , V_10 , & V_4 -> free ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> free ) ;
V_4 -> V_48 -- ;
V_54 -> V_58 [ V_54 -> V_56 ] = V_10 -> V_6 ;
}
V_54 -> V_55 = 0 ;
}
static void F_40 ( struct V_3 * V_4 )
{
struct V_53 * V_54 = & V_4 -> V_61 ;
F_38 ( V_4 , V_54 ) ;
for ( V_54 -> V_56 = 0 ; V_54 -> V_56 < V_54 -> V_60 ; V_54 -> V_56 ++ ) {
V_54 -> V_58 [ V_54 -> V_56 ] = F_37 ( V_4 ) ;
if ( V_54 -> V_58 [ V_54 -> V_56 ] < 0 )
break;
}
V_54 -> V_55 = 0 ;
}
void F_41 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_26 ) ;
F_39 ( V_4 ) ;
F_40 ( V_4 ) ;
F_15 ( & V_4 -> V_26 ) ;
}
int F_42 ( struct V_3 * V_4 )
{
int V_62 ;
struct V_53 * V_54 = & V_4 -> V_61 ;
struct V_53 * V_63 = & V_4 -> V_59 ;
if ( ! V_54 -> V_56 || ! V_63 -> V_56 || V_54 -> V_55 == V_54 -> V_56 ||
V_63 -> V_55 == V_63 -> V_56 )
F_3 ( V_4 ) ;
if ( ! V_54 -> V_56 )
V_62 = - V_52 ;
else {
F_13 ( & V_4 -> V_26 ) ;
V_62 = V_54 -> V_58 [ V_54 -> V_55 ++ ] ;
F_23 ( V_4 , V_4 -> V_57 [ V_62 ] ) ;
F_15 ( & V_4 -> V_26 ) ;
}
return V_62 ;
}
static struct V_11 * F_43 ( struct V_3 * V_4 )
{
struct V_53 * V_54 = & V_4 -> V_59 ;
int V_6 ;
if ( V_54 -> V_55 == V_54 -> V_56 || ! V_54 -> V_56 ) {
F_44 ( & V_4 -> V_5 ) ;
return NULL ;
} else {
V_6 = V_54 -> V_58 [ V_54 -> V_55 ++ ] ;
return V_4 -> V_57 [ V_6 ] ;
}
}
static struct V_11 * F_43 ( struct V_3 * V_4 )
{
struct V_11 * V_10 ;
V_10 = F_25 ( V_4 , & V_4 -> free , V_43 ) ;
F_35 ( V_4 , V_10 , & V_4 -> free ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> free ) ;
return V_10 ;
}
int F_42 ( struct V_3 * V_4 )
{
int V_64 , V_23 ;
F_13 ( & V_4 -> V_26 ) ;
V_64 = F_37 ( V_4 ) ;
F_15 ( & V_4 -> V_26 ) ;
V_23 = F_45 ( V_4 , V_64 , V_4 -> V_65 ,
V_4 -> V_66 - V_4 -> V_65 ) ;
if ( V_23 ) {
F_19 ( L_6 , V_64 ) ;
return V_23 ;
}
return V_64 ;
}
static int F_46 ( struct V_3 * V_4 , int V_6 )
{
struct V_11 * V_10 ;
V_10 = V_4 -> V_57 [ V_6 ] ;
if ( ! V_10 )
return - V_67 ;
if ( F_47 ( V_4 , V_10 ) )
return - V_67 ;
F_18 ( & V_10 -> V_18 . V_29 ) ;
F_21 ( L_7 , V_10 -> V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 , struct V_11 * V_10 ,
int V_68 )
{
int V_23 ;
struct V_69 * V_70 ;
unsigned long long V_20 = V_10 -> V_20 ;
F_21 ( L_8 , V_10 -> V_6 , V_20 ) ;
V_23 = F_49 ( V_4 , V_10 -> V_6 , V_10 -> V_20 ) ;
if ( V_23 )
return - V_71 ;
V_70 = F_50 ( V_4 -> V_72 , V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_23 = F_51 ( V_4 , V_10 -> V_6 , V_68 ) ;
if ( V_23 < 0 )
goto V_75;
V_20 += V_23 ;
if ( V_20 > V_46 ) {
F_19 ( L_9 ,
V_10 -> V_6 , V_20 ) ;
V_23 = - V_71 ;
goto V_75;
}
F_21 ( L_10 , V_10 -> V_6 , V_20 ) ;
V_70 -> V_20 = F_52 ( V_20 ) ;
V_23 = F_53 ( V_4 , V_10 -> V_6 , V_70 ) ;
if ( V_23 )
goto V_75;
V_10 -> V_20 = V_20 ;
F_13 ( & V_4 -> V_26 ) ;
if ( V_10 -> V_20 > V_4 -> V_45 )
V_4 -> V_45 = V_10 -> V_20 ;
F_15 ( & V_4 -> V_26 ) ;
V_75:
F_54 ( V_70 ) ;
return V_23 ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_11 * V_10 , * V_76 ;
int V_77 ;
V_78:
V_77 = 0 ;
F_13 ( & V_4 -> V_26 ) ;
F_56 (e, tmp, &ubi->pq[ubi->pq_head], u.list) {
F_21 ( L_11 ,
V_10 -> V_6 , V_10 -> V_20 ) ;
F_18 ( & V_10 -> V_18 . V_29 ) ;
F_5 ( V_10 , & V_4 -> V_55 ) ;
if ( V_77 ++ > 32 ) {
F_15 ( & V_4 -> V_26 ) ;
F_11 () ;
goto V_78;
}
}
V_4 -> V_33 += 1 ;
if ( V_4 -> V_33 == V_34 )
V_4 -> V_33 = 0 ;
F_7 ( V_4 -> V_33 >= 0 && V_4 -> V_33 < V_34 ) ;
F_15 ( & V_4 -> V_26 ) ;
}
static void F_57 ( struct V_3 * V_4 , struct V_24 * V_2 )
{
F_13 ( & V_4 -> V_26 ) ;
F_24 ( & V_2 -> V_29 , & V_4 -> V_27 ) ;
F_7 ( V_4 -> V_30 >= 0 ) ;
V_4 -> V_30 += 1 ;
if ( V_4 -> V_79 && ! F_58 ( V_4 ) )
F_59 ( V_4 -> V_80 ) ;
F_15 ( & V_4 -> V_26 ) ;
}
static void F_60 ( struct V_3 * V_4 , struct V_24 * V_2 )
{
F_12 ( & V_4 -> V_25 ) ;
F_57 ( V_4 , V_2 ) ;
F_16 ( & V_4 -> V_25 ) ;
}
int F_61 ( struct V_24 * V_2 )
{
return V_2 -> V_31 == V_81 ;
}
static int F_62 ( struct V_3 * V_4 , struct V_11 * V_10 ,
int V_82 , int V_83 , int V_68 )
{
struct V_24 * V_84 ;
F_7 ( V_10 ) ;
F_7 ( ! F_4 ( V_4 , V_10 -> V_6 ) ) ;
F_21 ( L_12 ,
V_10 -> V_6 , V_10 -> V_20 , V_68 ) ;
V_84 = F_63 ( sizeof( struct V_24 ) , V_73 ) ;
if ( ! V_84 )
return - V_74 ;
V_84 -> V_31 = & V_81 ;
V_84 -> V_10 = V_10 ;
V_84 -> V_82 = V_82 ;
V_84 -> V_83 = V_83 ;
V_84 -> V_68 = V_68 ;
F_60 ( V_4 , V_84 ) ;
return 0 ;
}
static int F_64 ( struct V_3 * V_4 , struct V_11 * V_10 ,
int V_82 , int V_83 , int V_68 )
{
struct V_24 * V_84 ;
F_21 ( L_13 , V_10 -> V_6 ) ;
V_84 = F_63 ( sizeof( struct V_24 ) , V_73 ) ;
if ( ! V_84 )
return - V_74 ;
V_84 -> V_10 = V_10 ;
V_84 -> V_82 = V_82 ;
V_84 -> V_83 = V_83 ;
V_84 -> V_68 = V_68 ;
return V_81 ( V_4 , V_84 , 0 ) ;
}
int F_65 ( struct V_3 * V_4 , struct V_11 * V_85 ,
int V_83 , int V_68 )
{
struct V_11 * V_10 ;
int V_82 , V_6 = V_85 -> V_6 ;
F_21 ( L_14 , V_6 ) ;
F_7 ( V_6 >= 0 ) ;
F_7 ( V_6 < V_4 -> V_86 ) ;
F_13 ( & V_4 -> V_26 ) ;
V_10 = V_4 -> V_57 [ V_6 ] ;
if ( ! V_10 ) {
V_10 = V_85 ;
F_7 ( V_10 -> V_20 >= 0 ) ;
V_4 -> V_57 [ V_6 ] = V_10 ;
} else {
V_10 -> V_20 = V_85 -> V_20 ;
F_54 ( V_85 ) ;
}
F_15 ( & V_4 -> V_26 ) ;
V_82 = V_83 ? V_87 : V_88 ;
return F_62 ( V_4 , V_10 , V_82 , V_83 , V_68 ) ;
}
static int F_66 ( struct V_3 * V_4 , int V_89 )
{
int V_23 = 0 ;
struct V_11 * V_17 ;
struct V_11 * V_90 ;
struct V_24 * V_2 ;
F_13 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_91 )
goto V_92;
if ( ! V_4 -> V_93 . V_14 ) {
if ( ! V_4 -> V_55 . V_14 || ! V_4 -> free . V_14 )
goto V_92;
V_17 = F_6 ( F_26 ( & V_4 -> V_55 ) , struct V_11 , V_18 . V_19 ) ;
V_90 = F_25 ( V_4 , & V_4 -> free , V_43 ) ;
if ( ! ( V_90 -> V_20 - V_17 -> V_20 >= V_94 ) )
goto V_92;
F_21 ( L_15 ) ;
} else
F_21 ( L_16 ) ;
V_4 -> V_91 = 1 ;
F_15 ( & V_4 -> V_26 ) ;
V_2 = F_63 ( sizeof( struct V_24 ) , V_73 ) ;
if ( ! V_2 ) {
V_23 = - V_74 ;
goto V_95;
}
V_2 -> V_47 = 0 ;
V_2 -> V_31 = & V_96 ;
if ( V_89 )
F_57 ( V_4 , V_2 ) ;
else
F_60 ( V_4 , V_2 ) ;
return V_23 ;
V_95:
F_13 ( & V_4 -> V_26 ) ;
V_4 -> V_91 = 0 ;
V_92:
F_15 ( & V_4 -> V_26 ) ;
return V_23 ;
}
int F_67 ( struct V_3 * V_4 )
{
struct V_24 * V_2 ;
F_13 ( & V_4 -> V_26 ) ;
if ( V_4 -> V_91 ) {
F_15 ( & V_4 -> V_26 ) ;
return 0 ;
}
V_4 -> V_91 = 1 ;
F_15 ( & V_4 -> V_26 ) ;
V_2 = F_63 ( sizeof( struct V_24 ) , V_73 ) ;
if ( ! V_2 ) {
F_13 ( & V_4 -> V_26 ) ;
V_4 -> V_91 = 0 ;
F_15 ( & V_4 -> V_26 ) ;
return - V_74 ;
}
V_2 -> V_47 = 1 ;
V_2 -> V_31 = & V_96 ;
F_60 ( V_4 , V_2 ) ;
return 0 ;
}
static int V_81 ( struct V_3 * V_4 , struct V_24 * V_84 ,
int V_97 )
{
struct V_11 * V_10 = V_84 -> V_10 ;
int V_6 = V_10 -> V_6 ;
int V_82 = V_84 -> V_82 ;
int V_83 = V_84 -> V_83 ;
int V_23 , V_98 = 0 ;
if ( V_97 ) {
F_21 ( L_17 , V_6 , V_10 -> V_20 ) ;
F_54 ( V_84 ) ;
F_68 ( V_99 , V_10 ) ;
return 0 ;
}
F_21 ( L_18 ,
V_6 , V_10 -> V_20 , V_84 -> V_82 , V_84 -> V_83 ) ;
F_7 ( ! F_4 ( V_4 , V_10 -> V_6 ) ) ;
V_23 = F_48 ( V_4 , V_10 , V_84 -> V_68 ) ;
if ( ! V_23 ) {
F_54 ( V_84 ) ;
F_13 ( & V_4 -> V_26 ) ;
F_5 ( V_10 , & V_4 -> free ) ;
V_4 -> V_48 ++ ;
F_15 ( & V_4 -> V_26 ) ;
F_55 ( V_4 ) ;
V_23 = F_66 ( V_4 , 1 ) ;
return V_23 ;
}
F_19 ( L_19 , V_6 , V_23 ) ;
F_54 ( V_84 ) ;
if ( V_23 == - V_100 || V_23 == - V_74 || V_23 == - V_101 ||
V_23 == - V_102 ) {
int V_103 ;
V_103 = F_62 ( V_4 , V_10 , V_82 , V_83 , 0 ) ;
if ( V_103 ) {
V_23 = V_103 ;
goto V_104;
}
return V_23 ;
}
F_68 ( V_99 , V_10 ) ;
if ( V_23 != - V_105 )
goto V_104;
if ( ! V_4 -> V_106 ) {
F_19 ( L_20 , V_6 ) ;
goto V_104;
}
F_13 ( & V_4 -> V_107 ) ;
if ( V_4 -> V_49 == 0 ) {
if ( V_4 -> V_108 == 0 ) {
F_15 ( & V_4 -> V_107 ) ;
F_19 ( L_21 ) ;
goto V_104;
}
V_4 -> V_108 -= 1 ;
V_98 = 1 ;
}
F_15 ( & V_4 -> V_107 ) ;
F_69 ( L_22 , V_6 ) ;
V_23 = F_70 ( V_4 , V_6 ) ;
if ( V_23 )
goto V_104;
F_13 ( & V_4 -> V_107 ) ;
if ( V_4 -> V_49 > 0 ) {
if ( V_98 ) {
V_4 -> V_108 += 1 ;
V_98 = 0 ;
}
V_4 -> V_49 -= 1 ;
}
V_4 -> V_109 += 1 ;
V_4 -> V_110 -= 1 ;
F_71 ( V_4 ) ;
if ( V_98 )
F_72 ( L_23 ) ;
else if ( V_4 -> V_49 )
F_69 ( L_24 , V_4 -> V_49 ) ;
else
F_72 ( L_25 ) ;
F_15 ( & V_4 -> V_107 ) ;
return V_23 ;
V_104:
if ( V_98 ) {
F_13 ( & V_4 -> V_107 ) ;
V_4 -> V_108 += 1 ;
F_15 ( & V_4 -> V_107 ) ;
}
F_73 ( V_4 ) ;
return V_23 ;
}
int F_74 ( struct V_3 * V_4 , int V_82 , int V_83 ,
int V_6 , int V_68 )
{
int V_23 ;
struct V_11 * V_10 ;
F_21 ( L_14 , V_6 ) ;
F_7 ( V_6 >= 0 ) ;
F_7 ( V_6 < V_4 -> V_86 ) ;
V_51:
F_13 ( & V_4 -> V_26 ) ;
V_10 = V_4 -> V_57 [ V_6 ] ;
if ( V_10 == V_4 -> V_111 ) {
F_21 ( L_26 , V_6 ) ;
F_15 ( & V_4 -> V_26 ) ;
F_75 ( & V_4 -> V_112 ) ;
F_76 ( & V_4 -> V_112 ) ;
goto V_51;
} else if ( V_10 == V_4 -> V_113 ) {
F_21 ( L_27 , V_6 ) ;
F_7 ( ! V_4 -> V_114 ) ;
V_4 -> V_114 = 1 ;
F_15 ( & V_4 -> V_26 ) ;
return 0 ;
} else {
if ( F_22 ( V_10 , & V_4 -> V_55 ) ) {
F_35 ( V_4 , V_10 , & V_4 -> V_55 ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> V_55 ) ;
} else if ( F_22 ( V_10 , & V_4 -> V_93 ) ) {
F_35 ( V_4 , V_10 , & V_4 -> V_93 ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> V_93 ) ;
} else if ( F_22 ( V_10 , & V_4 -> V_115 ) ) {
F_35 ( V_4 , V_10 , & V_4 -> V_115 ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> V_115 ) ;
V_4 -> V_116 -= 1 ;
F_7 ( V_4 -> V_116 >= 0 ) ;
V_68 = 1 ;
} else {
V_23 = F_46 ( V_4 , V_10 -> V_6 ) ;
if ( V_23 ) {
F_19 ( L_28 , V_6 ) ;
F_73 ( V_4 ) ;
F_15 ( & V_4 -> V_26 ) ;
return V_23 ;
}
}
}
F_15 ( & V_4 -> V_26 ) ;
V_23 = F_62 ( V_4 , V_10 , V_82 , V_83 , V_68 ) ;
if ( V_23 ) {
F_13 ( & V_4 -> V_26 ) ;
F_5 ( V_10 , & V_4 -> V_55 ) ;
F_15 ( & V_4 -> V_26 ) ;
}
return V_23 ;
}
int F_77 ( struct V_3 * V_4 , int V_6 )
{
struct V_11 * V_10 ;
F_69 ( L_29 , V_6 ) ;
V_51:
F_13 ( & V_4 -> V_26 ) ;
V_10 = V_4 -> V_57 [ V_6 ] ;
if ( V_10 == V_4 -> V_111 || F_22 ( V_10 , & V_4 -> V_93 ) ||
F_22 ( V_10 , & V_4 -> V_115 ) ) {
F_15 ( & V_4 -> V_26 ) ;
return 0 ;
}
if ( V_10 == V_4 -> V_113 ) {
F_15 ( & V_4 -> V_26 ) ;
F_21 ( L_30 , V_6 ) ;
F_78 () ;
goto V_51;
}
if ( F_22 ( V_10 , & V_4 -> V_55 ) ) {
F_35 ( V_4 , V_10 , & V_4 -> V_55 ) ;
F_36 ( & V_10 -> V_18 . V_19 , & V_4 -> V_55 ) ;
} else {
int V_23 ;
V_23 = F_46 ( V_4 , V_10 -> V_6 ) ;
if ( V_23 ) {
F_19 ( L_28 , V_6 ) ;
F_73 ( V_4 ) ;
F_15 ( & V_4 -> V_26 ) ;
return V_23 ;
}
}
F_5 ( V_10 , & V_4 -> V_93 ) ;
F_15 ( & V_4 -> V_26 ) ;
return F_66 ( V_4 , 0 ) ;
}
int F_79 ( struct V_3 * V_4 , int V_82 , int V_83 )
{
int V_23 = 0 ;
int V_117 = 1 ;
F_21 ( L_31 ,
V_82 , V_83 , V_4 -> V_30 ) ;
while ( V_117 ) {
struct V_24 * V_2 ;
V_117 = 0 ;
F_12 ( & V_4 -> V_25 ) ;
F_13 ( & V_4 -> V_26 ) ;
F_80 (wrk, &ubi->works, list) {
if ( ( V_82 == V_118 || V_2 -> V_82 == V_82 ) &&
( V_83 == V_118 || V_2 -> V_83 == V_83 ) ) {
F_18 ( & V_2 -> V_29 ) ;
V_4 -> V_30 -= 1 ;
F_7 ( V_4 -> V_30 >= 0 ) ;
F_15 ( & V_4 -> V_26 ) ;
V_23 = V_2 -> V_31 ( V_4 , V_2 , 0 ) ;
if ( V_23 ) {
F_16 ( & V_4 -> V_25 ) ;
return V_23 ;
}
F_13 ( & V_4 -> V_26 ) ;
V_117 = 1 ;
break;
}
}
F_15 ( & V_4 -> V_26 ) ;
F_16 ( & V_4 -> V_25 ) ;
}
F_81 ( & V_4 -> V_25 ) ;
F_82 ( & V_4 -> V_25 ) ;
return V_23 ;
}
static void F_83 ( struct V_12 * V_13 )
{
struct V_14 * V_19 ;
struct V_11 * V_10 ;
V_19 = V_13 -> V_14 ;
while ( V_19 ) {
if ( V_19 -> V_21 )
V_19 = V_19 -> V_21 ;
else if ( V_19 -> V_22 )
V_19 = V_19 -> V_22 ;
else {
V_10 = F_6 ( V_19 , struct V_11 , V_18 . V_19 ) ;
V_19 = F_84 ( V_19 ) ;
if ( V_19 ) {
if ( V_19 -> V_21 == & V_10 -> V_18 . V_19 )
V_19 -> V_21 = NULL ;
else
V_19 -> V_22 = NULL ;
}
F_68 ( V_99 , V_10 ) ;
}
}
}
int F_85 ( void * V_18 )
{
int V_119 = 0 ;
struct V_3 * V_4 = V_18 ;
F_69 ( L_32 ,
V_4 -> V_120 , F_86 ( V_121 ) ) ;
F_87 () ;
for (; ; ) {
int V_23 ;
if ( F_88 () )
break;
if ( F_89 () )
continue;
F_13 ( & V_4 -> V_26 ) ;
if ( F_14 ( & V_4 -> V_27 ) || V_4 -> V_122 ||
! V_4 -> V_79 || F_58 ( V_4 ) ) {
F_90 ( V_123 ) ;
F_15 ( & V_4 -> V_26 ) ;
F_91 () ;
continue;
}
F_15 ( & V_4 -> V_26 ) ;
V_23 = F_10 ( V_4 ) ;
if ( V_23 ) {
F_19 ( L_33 ,
V_4 -> V_120 , V_23 ) ;
if ( V_119 ++ > V_124 ) {
F_69 ( L_34 ,
V_4 -> V_120 , V_124 ) ;
F_73 ( V_4 ) ;
V_4 -> V_79 = 0 ;
continue;
}
} else
V_119 = 0 ;
F_11 () ;
}
F_21 ( L_35 , V_4 -> V_120 ) ;
return 0 ;
}
static void F_92 ( struct V_3 * V_4 )
{
while ( ! F_14 ( & V_4 -> V_27 ) ) {
struct V_24 * V_2 ;
V_2 = F_17 ( V_4 -> V_27 . V_28 , struct V_24 , V_29 ) ;
F_18 ( & V_2 -> V_29 ) ;
V_2 -> V_31 ( V_4 , V_2 , 1 ) ;
V_4 -> V_30 -= 1 ;
F_7 ( V_4 -> V_30 >= 0 ) ;
}
}
int F_93 ( struct V_3 * V_4 , struct V_125 * V_126 )
{
int V_23 , V_7 , V_127 , V_128 = 0 ;
struct V_14 * V_129 , * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 , * V_76 ;
struct V_11 * V_10 ;
V_4 -> V_55 = V_4 -> V_115 = V_4 -> free = V_4 -> V_93 = V_135 ;
F_94 ( & V_4 -> V_26 ) ;
F_95 ( & V_4 -> V_112 ) ;
F_96 ( & V_4 -> V_25 ) ;
V_4 -> V_45 = V_126 -> V_45 ;
F_97 ( & V_4 -> V_27 ) ;
#ifdef F_29
F_98 ( & V_4 -> V_5 , F_1 ) ;
#endif
sprintf ( V_4 -> V_120 , V_136 , V_4 -> V_137 ) ;
V_23 = - V_74 ;
V_4 -> V_57 = F_50 ( V_4 -> V_86 * sizeof( void * ) , V_138 ) ;
if ( ! V_4 -> V_57 )
return V_23 ;
for ( V_7 = 0 ; V_7 < V_34 ; V_7 ++ )
F_97 ( & V_4 -> V_35 [ V_7 ] ) ;
V_4 -> V_33 = 0 ;
F_56 (aeb, tmp, &ai->erase, u.list) {
F_11 () ;
V_10 = F_99 ( V_99 , V_138 ) ;
if ( ! V_10 )
goto V_75;
V_10 -> V_6 = V_134 -> V_6 ;
V_10 -> V_20 = V_134 -> V_20 ;
F_7 ( ! F_4 ( V_4 , V_10 -> V_6 ) ) ;
V_4 -> V_57 [ V_10 -> V_6 ] = V_10 ;
if ( F_62 ( V_4 , V_10 , V_134 -> V_82 , V_134 -> V_83 , 0 ) ) {
F_68 ( V_99 , V_10 ) ;
goto V_75;
}
V_128 ++ ;
}
V_4 -> V_48 = 0 ;
F_80 (aeb, &ai->free, u.list) {
F_11 () ;
V_10 = F_99 ( V_99 , V_138 ) ;
if ( ! V_10 )
goto V_75;
V_10 -> V_6 = V_134 -> V_6 ;
V_10 -> V_20 = V_134 -> V_20 ;
F_7 ( V_10 -> V_20 >= 0 ) ;
F_7 ( ! F_4 ( V_4 , V_10 -> V_6 ) ) ;
F_5 ( V_10 , & V_4 -> free ) ;
V_4 -> V_48 ++ ;
V_4 -> V_57 [ V_10 -> V_6 ] = V_10 ;
V_128 ++ ;
}
F_32 (rb1, av, &ai->volumes, rb) {
F_32 (rb2, aeb, &av->root, u.rb) {
F_11 () ;
V_10 = F_99 ( V_99 , V_138 ) ;
if ( ! V_10 )
goto V_75;
V_10 -> V_6 = V_134 -> V_6 ;
V_10 -> V_20 = V_134 -> V_20 ;
V_4 -> V_57 [ V_10 -> V_6 ] = V_10 ;
if ( ! V_134 -> V_93 ) {
F_21 ( L_36 ,
V_10 -> V_6 , V_10 -> V_20 ) ;
F_5 ( V_10 , & V_4 -> V_55 ) ;
} else {
F_21 ( L_37 ,
V_10 -> V_6 , V_10 -> V_20 ) ;
F_5 ( V_10 , & V_4 -> V_93 ) ;
}
V_128 ++ ;
}
}
F_21 ( L_38 , V_128 ) ;
if ( V_4 -> V_8 )
F_7 ( V_4 -> V_110 == \
V_128 + V_4 -> V_8 -> V_9 ) ;
else
F_7 ( V_4 -> V_110 == V_128 ) ;
V_127 = V_139 ;
#ifdef F_29
V_127 += ( V_4 -> V_140 / V_4 -> V_141 ) * 2 ;
#endif
if ( V_4 -> V_108 < V_127 ) {
F_19 ( L_39 ,
V_4 -> V_108 , V_127 ) ;
if ( V_4 -> V_142 )
F_19 ( L_40 ,
V_4 -> V_142 ) ;
goto V_75;
}
V_4 -> V_108 -= V_127 ;
V_4 -> V_143 += V_127 ;
V_23 = F_66 ( V_4 , 0 ) ;
if ( V_23 )
goto V_75;
return 0 ;
V_75:
F_92 ( V_4 ) ;
F_83 ( & V_4 -> V_55 ) ;
F_83 ( & V_4 -> free ) ;
F_83 ( & V_4 -> V_93 ) ;
F_54 ( V_4 -> V_57 ) ;
return V_23 ;
}
static void F_100 ( struct V_3 * V_4 )
{
int V_7 ;
struct V_11 * V_10 , * V_76 ;
for ( V_7 = 0 ; V_7 < V_34 ; ++ V_7 ) {
F_56 (e, tmp, &ubi->pq[i], u.list) {
F_18 ( & V_10 -> V_18 . V_29 ) ;
F_68 ( V_99 , V_10 ) ;
}
}
}
void F_101 ( struct V_3 * V_4 )
{
F_21 ( L_41 ) ;
F_92 ( V_4 ) ;
F_100 ( V_4 ) ;
F_83 ( & V_4 -> V_55 ) ;
F_83 ( & V_4 -> V_115 ) ;
F_83 ( & V_4 -> free ) ;
F_83 ( & V_4 -> V_93 ) ;
F_54 ( V_4 -> V_57 ) ;
}
static int F_49 ( struct V_3 * V_4 , int V_6 , int V_20 )
{
int V_23 ;
long long V_144 ;
struct V_69 * V_70 ;
if ( ! F_102 ( V_4 ) )
return 0 ;
V_70 = F_50 ( V_4 -> V_72 , V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_23 = F_103 ( V_4 , V_6 , V_70 , 0 ) ;
if ( V_23 && V_23 != V_145 ) {
V_23 = 0 ;
goto V_75;
}
V_144 = F_104 ( V_70 -> V_20 ) ;
if ( V_20 != V_144 && V_144 - V_20 > 1 ) {
F_19 ( L_42 , V_6 ) ;
F_19 ( L_43 , V_144 , V_20 ) ;
F_105 () ;
V_23 = 1 ;
} else
V_23 = 0 ;
V_75:
F_54 ( V_70 ) ;
return V_23 ;
}
static int F_35 ( const struct V_3 * V_4 ,
struct V_11 * V_10 , struct V_12 * V_13 )
{
if ( ! F_102 ( V_4 ) )
return 0 ;
if ( F_22 ( V_10 , V_13 ) )
return 0 ;
F_19 ( L_44 ,
V_10 -> V_6 , V_10 -> V_20 , V_13 ) ;
F_105 () ;
return - V_71 ;
}
static int F_47 ( const struct V_3 * V_4 ,
struct V_11 * V_10 )
{
struct V_11 * V_15 ;
int V_7 ;
if ( ! F_102 ( V_4 ) )
return 0 ;
for ( V_7 = 0 ; V_7 < V_34 ; ++ V_7 )
F_80 (p, &ubi->pq[i], u.list)
if ( V_15 == V_10 )
return 0 ;
F_19 ( L_45 ,
V_10 -> V_6 , V_10 -> V_20 ) ;
F_105 () ;
return - V_71 ;
}
