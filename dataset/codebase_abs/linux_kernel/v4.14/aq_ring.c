static struct V_1 * F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
V_2 -> V_6 =
F_2 ( V_2 -> V_7 , sizeof( struct V_8 ) , V_9 ) ;
if ( ! V_2 -> V_6 ) {
V_5 = - V_10 ;
goto V_11;
}
V_2 -> V_12 = F_3 ( F_4 ( V_4 ) ,
V_2 -> V_7 * V_2 -> V_13 ,
& V_2 -> V_14 , V_9 ) ;
if ( ! V_2 -> V_12 ) {
V_5 = - V_10 ;
goto V_11;
}
V_11:
if ( V_5 < 0 ) {
F_5 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
struct V_1 * F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_15 ,
struct V_16 * V_17 )
{
int V_5 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_7 = V_17 -> V_18 ;
V_2 -> V_13 = V_17 -> V_19 -> V_20 ;
V_2 = F_1 ( V_2 , V_4 ) ;
if ( ! V_2 ) {
V_5 = - V_10 ;
goto V_11;
}
V_11:
if ( V_5 < 0 ) {
F_5 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
struct V_1 * F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_15 ,
struct V_16 * V_17 )
{
int V_5 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_7 = V_17 -> V_21 ;
V_2 -> V_13 = V_17 -> V_19 -> V_22 ;
V_2 = F_1 ( V_2 , V_4 ) ;
if ( ! V_2 ) {
V_5 = - V_10 ;
goto V_11;
}
V_11:
if ( V_5 < 0 ) {
F_5 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
int F_8 ( struct V_1 * V_2 )
{
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
return 0 ;
}
static inline bool F_9 ( unsigned int V_26 , unsigned int V_27 ,
unsigned int V_28 )
{
return ( V_26 < V_28 ) ? ( ( V_26 < V_27 ) && ( V_27 < V_28 ) ) : ( ( V_26 < V_27 ) || ( V_27 < V_28 ) ) ;
}
void F_10 ( struct V_1 * V_29 )
{
if ( F_11 ( V_29 ) <= V_30 )
F_12 ( V_29 ) ;
else if ( F_11 ( V_29 ) > V_31 )
F_13 ( V_29 ) ;
}
void F_13 ( struct V_1 * V_29 )
{
struct V_32 * V_33 = F_14 ( V_29 -> V_4 ) ;
if ( F_15 ( V_33 , V_29 -> V_15 ) ) {
F_16 ( V_33 , V_29 -> V_15 ) ;
V_29 -> V_34 . V_35 . V_36 ++ ;
}
}
void F_12 ( struct V_1 * V_29 )
{
struct V_32 * V_33 = F_14 ( V_29 -> V_4 ) ;
if ( ! F_15 ( V_33 , V_29 -> V_15 ) )
F_17 ( V_33 , V_29 -> V_15 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = F_4 ( V_2 -> V_4 ) ;
for (; V_2 -> V_24 != V_2 -> V_23 ;
V_2 -> V_24 = F_19 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_39 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
if ( F_20 ( V_39 -> V_40 ) ) {
if ( F_21 ( V_39 -> V_41 ) ) {
if ( ! V_39 -> V_42 &&
V_39 -> V_43 != 0xffffU &&
( ! F_9 ( V_2 -> V_24 ,
V_39 -> V_43 ,
V_2 -> V_23 ) ) )
break;
F_22 ( V_38 , V_39 -> V_44 , V_39 -> V_45 ,
V_46 ) ;
} else {
F_23 ( V_38 , V_39 -> V_44 , V_39 -> V_45 ,
V_46 ) ;
}
}
if ( F_21 ( V_39 -> V_42 ) )
F_24 ( V_39 -> V_47 ) ;
V_39 -> V_44 = 0U ;
V_39 -> V_43 = 0xffffU ;
}
}
int F_25 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
int * V_50 ,
int V_51 )
{
struct V_32 * V_33 = F_14 ( V_2 -> V_4 ) ;
int V_5 = 0 ;
bool V_52 = true ;
for (; ( V_2 -> V_24 != V_2 -> V_23 ) && V_51 ;
V_2 -> V_24 = F_19 ( V_2 , V_2 -> V_24 ) ,
-- V_51 , ++ ( * V_50 ) ) {
struct V_8 * V_39 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
struct V_53 * V_47 = NULL ;
unsigned int V_54 = 0U ;
unsigned int V_27 = 0U ;
struct V_8 * V_55 = NULL ;
if ( V_39 -> V_56 ) {
F_26 ( V_39 -> V_57 , 0 ) ;
continue;
}
if ( V_39 -> V_58 )
continue;
if ( ! V_39 -> V_42 ) {
for ( V_54 = V_39 -> V_59 ,
V_55 = & V_2 -> V_6 [ V_54 ] ; true ;
V_54 = V_55 -> V_59 ,
V_55 = & V_2 -> V_6 [ V_54 ] ) {
V_52 =
F_9 ( V_2 -> V_24 ,
V_54 ,
V_2 -> V_23 ) ;
if ( F_21 ( ! V_52 ) ) {
V_52 = false ;
break;
}
if ( V_55 -> V_42 )
break;
}
if ( ! V_52 ) {
V_5 = 0 ;
goto V_11;
}
}
if ( V_39 -> V_42 ) {
V_47 = F_27 ( F_28 ( V_39 -> V_57 ) ,
V_39 -> V_45 + V_60 ) ;
if ( F_21 ( ! V_47 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_29 ( V_47 , V_39 -> V_45 ) ;
} else {
V_47 = F_30 ( V_33 , V_61 ) ;
if ( F_21 ( ! V_47 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_29 ( V_47 , V_61 ) ;
memcpy ( V_47 -> V_62 , F_28 ( V_39 -> V_57 ) , V_61 ) ;
F_31 ( V_47 , 0 , V_39 -> V_57 , V_61 ,
V_39 -> V_45 - V_61 ,
F_32 ( V_39 -> V_45 - V_61 ) ) ;
for ( V_27 = 1U , V_54 = V_39 -> V_59 ,
V_55 = & V_2 -> V_6 [ V_54 ] ; true ;
V_54 = V_55 -> V_59 ,
V_55 = & V_2 -> V_6 [ V_54 ] , ++ V_27 ) {
F_31 ( V_47 , V_27 , V_55 -> V_57 , 0 ,
V_55 -> V_45 ,
F_32 ( V_39 -> V_45 -
V_61 ) ) ;
V_55 -> V_58 = 1 ;
if ( V_55 -> V_42 )
break;
}
}
V_47 -> V_63 = F_33 ( V_47 , V_33 ) ;
if ( F_21 ( V_39 -> V_64 ) ) {
++ V_2 -> V_34 . V_65 . V_66 ;
V_47 -> V_67 = V_68 ;
} else {
if ( V_39 -> V_69 ) {
F_34 ( V_47 ) ;
if ( V_39 -> V_70 || V_39 -> V_71 )
F_34 ( V_47 ) ;
} else {
V_47 -> V_67 = V_68 ;
}
}
F_35 ( V_47 , V_39 -> V_72 ,
V_39 -> V_73 ? V_74 :
V_75 ) ;
F_36 ( V_47 , V_2 -> V_15 ) ;
F_37 ( V_49 , V_47 ) ;
++ V_2 -> V_34 . V_65 . V_76 ;
V_2 -> V_34 . V_65 . V_77 += V_47 -> V_45 ;
}
V_11:
return V_5 ;
}
int F_38 ( struct V_1 * V_2 )
{
unsigned int V_78 = F_39 ( V_79 / V_80 +
( V_79 % V_80 ? 1 : 0 ) ) - 1 ;
struct V_8 * V_39 = NULL ;
int V_5 = 0 ;
int V_27 = 0 ;
for ( V_27 = F_11 ( V_2 ) ; V_27 -- ;
V_2 -> V_25 = F_19 ( V_2 , V_2 -> V_25 ) ) {
V_39 = & V_2 -> V_6 [ V_2 -> V_25 ] ;
V_39 -> V_81 = 0U ;
V_39 -> V_45 = V_79 ;
V_39 -> V_57 = F_40 ( V_82 | V_83 |
V_84 , V_78 ) ;
if ( ! V_39 -> V_57 ) {
V_5 = - V_10 ;
goto V_11;
}
V_39 -> V_44 = F_41 ( F_4 ( V_2 -> V_4 ) ,
V_39 -> V_57 , 0 ,
V_79 , V_85 ) ;
if ( F_42 ( F_4 ( V_2 -> V_4 ) , V_39 -> V_44 ) ) {
V_5 = - V_10 ;
goto V_11;
}
V_39 = NULL ;
}
V_11:
if ( V_5 < 0 ) {
if ( V_39 && V_39 -> V_57 )
F_26 ( V_39 -> V_57 , 0 ) ;
}
return V_5 ;
}
void F_43 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
for (; V_2 -> V_24 != V_2 -> V_25 ;
V_2 -> V_24 = F_19 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_39 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
F_23 ( F_4 ( V_2 -> V_4 ) , V_39 -> V_44 ,
V_79 , V_85 ) ;
F_26 ( V_39 -> V_57 , 0 ) ;
}
V_11: ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
F_44 ( V_2 -> V_6 ) ;
if ( V_2 -> V_12 )
F_45 ( F_4 ( V_2 -> V_4 ) ,
V_2 -> V_7 * V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_14 ) ;
V_11: ;
}
