static struct V_1 * V_1 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_3 ;
}
int F_2 ( struct V_2 * V_2 )
{
return F_3 ( F_4 ( V_2 ) ) - V_4 ;
}
void F_5 ( struct V_2 * V_2 )
{
V_1 ( V_2 ) -> V_5 = false ;
}
static void F_6 ( struct V_2 * V_2 )
{
struct V_1 * V_6 = V_1 ( V_2 ) ;
int V_7 = F_7 ( F_4 ( V_2 ) ) ;
V_6 -> V_8 = 1 + ( V_7 * V_6 -> V_9 / 100 ) ;
}
static void F_8 ( struct V_2 * V_2 )
{
struct V_1 * V_6 = V_1 ( V_2 ) ;
int V_10 = F_7 ( V_6 -> V_11 ) ;
int V_12 , V_13 , V_14 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = true ;
if ( ! V_10 )
return;
for ( V_12 = 0 ; V_12 < V_18 ; V_12 ++ ) {
if ( ! V_6 -> V_19 [ V_12 ] )
continue;
V_13 = F_9 ( V_2 , V_12 ) ;
if ( V_13 < F_3 ( V_6 -> V_11 ) )
F_10 ( V_6 -> V_11 , V_13 ) ;
V_6 -> V_17 &= F_11 ( V_2 , V_12 ) ;
if ( V_6 -> V_19 [ V_12 ] < V_10 )
continue;
V_6 -> V_15 = V_12 ;
if ( ( V_12 ^ F_12 ( V_2 ) ) & 1 )
break;
}
V_14 = V_6 -> V_15 ;
if ( V_14 != V_16 )
V_6 -> V_17 = F_11 ( V_2 , V_14 ) ;
}
void F_13 ( struct V_2 * V_2 , int V_20 )
{
struct V_1 * V_6 = V_1 ( V_2 ) ;
F_14 ( V_2 ) ;
V_6 -> V_19 [ V_20 ] ++ ;
F_8 ( V_2 ) ;
F_15 ( V_2 ) ;
}
void F_16 ( struct V_2 * V_2 , int V_20 )
{
struct V_1 * V_6 = V_1 ( V_2 ) ;
F_14 ( V_2 ) ;
V_6 -> V_19 [ V_20 ] -- ;
F_8 ( V_2 ) ;
F_15 ( V_2 ) ;
}
static void F_17 ( struct V_2 * V_2 , struct V_21 * V_22 )
{
int V_20 ;
struct V_1 * V_6 = V_1 ( V_2 ) ;
struct V_23 * V_24 , * V_25 ;
struct V_21 V_26 ;
if ( F_18 ( V_22 ) )
return;
V_20 = V_6 -> V_15 ;
if ( V_20 >= 0 ) {
F_19 ( V_2 , V_20 , V_22 ) ;
return;
}
F_20 ( & V_26 ) ;
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ ) {
if ( ! V_6 -> V_19 [ V_20 ] )
continue;
F_21 (xmitq, skb) {
V_25 = F_22 ( V_24 , V_27 ) ;
if ( ! V_25 )
break;
F_23 ( & V_26 , V_25 ) ;
}
F_19 ( V_2 , V_20 , & V_26 ) ;
}
F_24 ( V_22 ) ;
F_24 ( & V_26 ) ;
}
static void F_25 ( struct V_2 * V_2 , int V_19 ,
struct V_28 * V_29 )
{
struct V_1 * V_6 = V_1 ( V_2 ) ;
unsigned long exp = V_29 -> V_30 ;
if ( ! V_6 -> V_17 ) {
V_29 -> V_31 = true ;
return;
}
if ( ! V_6 -> V_5 ) {
V_29 -> V_31 = false ;
return;
}
V_29 -> V_30 = V_32 + V_33 ;
if ( V_29 -> V_34 || F_26 ( V_32 , exp ) )
return;
V_29 -> V_31 = V_19 <= V_6 -> V_8 ;
}
static int F_27 ( struct V_2 * V_2 , struct V_21 * V_35 ,
T_1 * V_36 )
{
struct V_37 * V_38 = F_4 ( V_2 ) ;
struct V_21 V_22 ;
int V_39 = 0 ;
F_28 ( & V_22 ) ;
F_14 ( V_2 ) ;
if ( F_7 ( V_38 ) )
V_39 = F_29 ( V_38 , V_35 , & V_22 ) ;
F_15 ( V_2 ) ;
F_17 ( V_2 , & V_22 ) ;
F_24 ( V_35 ) ;
if ( V_39 == - V_40 ) {
* V_36 = 1 ;
V_39 = 0 ;
}
return V_39 ;
}
static int F_30 ( struct V_2 * V_2 , struct V_21 * V_35 ,
struct V_41 * V_19 , T_1 * V_36 )
{
struct V_21 V_42 ;
struct V_43 * V_44 , * V_45 ;
T_2 V_46 , V_47 ;
V_47 = F_31 ( F_32 ( F_33 ( V_35 ) ) ) ;
F_28 ( & V_42 ) ;
F_34 (n, tmp, &dests->list, list) {
V_46 = V_44 -> V_48 ;
if ( ! F_35 ( V_46 , V_35 , & V_42 ) )
return - V_49 ;
if ( F_36 ( V_2 , & V_42 , V_46 , V_47 ) == - V_40 )
( * V_36 ) ++ ;
}
return 0 ;
}
int F_37 ( struct V_2 * V_2 , struct V_21 * V_35 ,
struct V_28 * V_29 , struct V_41 * V_19 ,
T_1 * V_36 )
{
struct V_21 V_50 , V_51 ;
int V_39 = 0 ;
F_20 ( & V_50 ) ;
F_20 ( & V_51 ) ;
if ( V_19 -> V_52 && ! F_38 ( V_35 , & V_51 ) ) {
V_39 = - V_49 ;
goto exit;
}
if ( V_19 -> V_53 ) {
F_25 ( V_2 , V_19 -> V_53 , V_29 ) ;
if ( V_29 -> V_31 )
V_39 = F_30 ( V_2 , V_35 , V_19 , V_36 ) ;
else
V_39 = F_27 ( V_2 , V_35 , V_36 ) ;
}
if ( V_19 -> V_52 )
F_39 ( V_2 , & V_51 , & V_50 ) ;
exit:
F_24 ( V_35 ) ;
return V_39 ;
}
int F_40 ( struct V_2 * V_2 , struct V_37 * V_38 , struct V_23 * V_24 )
{
struct V_54 * V_55 = F_32 ( V_24 ) ;
struct V_21 * V_50 = & V_1 ( V_2 ) -> V_50 ;
struct V_21 V_22 ;
int V_39 ;
F_28 ( & V_22 ) ;
if ( F_41 ( V_55 ) != F_42 ( V_2 ) || ! F_43 ( V_38 ) ) {
F_44 ( V_24 ) ;
return 0 ;
}
F_14 ( V_2 ) ;
if ( F_45 ( V_55 ) == V_56 )
V_39 = F_46 ( V_38 , V_24 , & V_22 ) ;
else
V_39 = F_47 ( V_38 , V_24 , NULL ) ;
F_15 ( V_2 ) ;
F_17 ( V_2 , & V_22 ) ;
if ( ! F_18 ( V_50 ) )
F_48 ( V_2 , V_50 ) ;
return V_39 ;
}
void F_49 ( struct V_2 * V_2 , struct V_37 * V_38 ,
struct V_54 * V_55 )
{
struct V_21 * V_50 = & V_1 ( V_2 ) -> V_50 ;
T_1 V_57 = F_50 ( V_55 ) ;
struct V_21 V_22 ;
if ( F_51 ( V_55 ) )
return;
F_28 ( & V_22 ) ;
F_14 ( V_2 ) ;
F_52 ( V_38 , V_57 , & V_22 ) ;
F_15 ( V_2 ) ;
F_17 ( V_2 , & V_22 ) ;
if ( ! F_18 ( V_50 ) )
F_48 ( V_2 , V_50 ) ;
}
int F_53 ( struct V_2 * V_2 , struct V_37 * V_38 ,
struct V_54 * V_55 )
{
struct V_21 * V_50 = & V_1 ( V_2 ) -> V_50 ;
struct V_21 V_22 ;
int V_39 = 0 ;
F_28 ( & V_22 ) ;
F_14 ( V_2 ) ;
if ( F_54 ( V_55 ) != V_58 ) {
F_55 ( V_38 , V_55 ) ;
} else if ( ! F_51 ( V_55 ) ) {
F_52 ( V_38 , F_50 ( V_55 ) , & V_22 ) ;
V_39 = F_56 ( V_38 , V_55 , & V_22 ) ;
}
F_15 ( V_2 ) ;
F_17 ( V_2 , & V_22 ) ;
if ( ! F_18 ( V_50 ) )
F_48 ( V_2 , V_50 ) ;
return V_39 ;
}
void F_57 ( struct V_2 * V_2 , struct V_37 * V_59 ,
struct V_21 * V_22 )
{
struct V_37 * V_60 = F_4 ( V_2 ) ;
F_14 ( V_2 ) ;
F_58 ( V_60 , V_59 , V_22 ) ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_15 ( V_2 ) ;
}
void F_59 ( struct V_2 * V_2 , struct V_37 * V_61 )
{
struct V_37 * V_60 = F_4 ( V_2 ) ;
struct V_21 * V_50 = & V_1 ( V_2 ) -> V_50 ;
struct V_21 V_22 ;
F_28 ( & V_22 ) ;
F_14 ( V_2 ) ;
F_60 ( V_60 , V_61 , & V_22 ) ;
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_15 ( V_2 ) ;
F_17 ( V_2 , & V_22 ) ;
if ( ! F_18 ( V_50 ) )
F_48 ( V_2 , V_50 ) ;
}
int F_61 ( struct V_2 * V_2 )
{
struct V_37 * V_38 = F_4 ( V_2 ) ;
if ( ! V_38 )
return - V_62 ;
F_14 ( V_2 ) ;
F_62 ( V_38 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_2 * V_2 , T_2 V_63 )
{
struct V_37 * V_38 = F_4 ( V_2 ) ;
if ( ! V_38 )
return - V_62 ;
if ( V_63 < V_64 )
V_63 = V_64 ;
if ( V_63 > V_65 )
return - V_66 ;
F_14 ( V_2 ) ;
F_64 ( V_38 , V_63 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_65 ( struct V_2 * V_2 , struct V_67 * V_68 [] )
{
int V_69 ;
T_2 V_70 ;
struct V_67 * V_71 [ V_72 + 1 ] ;
if ( ! V_68 [ V_73 ] )
return - V_66 ;
V_69 = F_66 ( V_68 [ V_73 ] , V_71 ) ;
if ( V_69 )
return V_69 ;
if ( ! V_71 [ V_74 ] )
return - V_75 ;
V_70 = F_67 ( V_71 [ V_74 ] ) ;
return F_63 ( V_2 , V_70 ) ;
}
int F_68 ( struct V_2 * V_2 )
{
struct F_1 * V_76 = F_1 ( V_2 ) ;
struct V_1 * V_6 = NULL ;
struct V_37 * V_38 = NULL ;
V_6 = F_69 ( sizeof( * V_6 ) , V_27 ) ;
if ( ! V_6 )
goto V_77;
V_76 -> V_3 = V_6 ;
F_70 ( & F_1 ( V_2 ) -> V_78 ) ;
if ( ! F_71 ( V_2 , 0 , 0 ,
V_79 ,
V_80 ,
0 ,
& V_6 -> V_50 ,
NULL ,
NULL ,
& V_38 ) )
goto V_77;
V_6 -> V_11 = V_38 ;
V_76 -> V_81 = V_38 ;
V_6 -> V_9 = 25 ;
V_6 -> V_5 = true ;
return 0 ;
V_77:
F_72 ( V_6 ) ;
F_72 ( V_38 ) ;
return - V_49 ;
}
void F_73 ( struct V_2 * V_2 )
{
struct F_1 * V_76 = F_74 ( V_2 , V_82 ) ;
F_75 () ;
F_72 ( V_76 -> V_3 ) ;
F_72 ( V_76 -> V_81 ) ;
}
void F_76 ( struct V_41 * V_83 , T_2 V_84 )
{
memset ( V_83 , 0 , sizeof( * V_83 ) ) ;
F_77 ( & V_83 -> V_85 ) ;
V_83 -> V_84 = V_84 ;
}
void F_78 ( struct V_41 * V_83 , T_2 V_86 )
{
if ( V_86 == V_83 -> V_84 )
V_83 -> V_52 = true ;
else if ( F_79 ( & V_83 -> V_85 , V_86 ) )
V_83 -> V_53 ++ ;
}
void F_80 ( struct V_41 * V_83 , T_2 V_86 )
{
if ( V_86 == V_83 -> V_84 )
V_83 -> V_52 = false ;
else if ( F_81 ( & V_83 -> V_85 , V_86 ) )
V_83 -> V_53 -- ;
}
void F_82 ( struct V_41 * V_83 )
{
F_83 ( & V_83 -> V_85 ) ;
V_83 -> V_53 = 0 ;
V_83 -> V_52 = 0 ;
}
