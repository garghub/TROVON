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
void F_9 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_4 ( V_2 -> V_4 ) ;
for (; V_2 -> V_24 != V_2 -> V_23 ;
V_2 -> V_24 = F_10 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_28 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
if ( F_11 ( V_28 -> V_29 ) ) {
if ( F_12 ( V_28 -> V_30 ) )
F_13 ( V_27 , V_28 -> V_31 , V_28 -> V_32 ,
V_33 ) ;
else
F_14 ( V_27 , V_28 -> V_31 , V_28 -> V_32 ,
V_33 ) ;
}
if ( F_12 ( V_28 -> V_34 ) )
F_15 ( V_28 -> V_35 ) ;
}
}
static inline unsigned int F_16 ( unsigned int V_36 , unsigned int V_37 ,
unsigned int V_38 )
{
return ( V_36 < V_38 ) ? ( ( V_36 < V_37 ) && ( V_37 < V_38 ) ) : ( ( V_36 < V_37 ) || ( V_37 < V_38 ) ) ;
}
int F_17 ( struct V_1 * V_2 , int * V_39 , int V_40 )
{
struct V_41 * V_42 = F_18 ( V_2 -> V_4 ) ;
int V_5 = 0 ;
bool V_43 = true ;
for (; ( V_2 -> V_24 != V_2 -> V_23 ) && V_40 ;
V_2 -> V_24 = F_10 ( V_2 , V_2 -> V_24 ) ,
-- V_40 , ++ ( * V_39 ) ) {
struct V_8 * V_28 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
struct V_44 * V_35 = NULL ;
unsigned int V_45 = 0U ;
unsigned int V_37 = 0U ;
struct V_8 * V_46 = NULL ;
if ( V_28 -> V_47 ) {
F_19 ( V_28 -> V_48 , 0 ) ;
continue;
}
if ( V_28 -> V_49 )
continue;
if ( ! V_28 -> V_34 ) {
for ( V_45 = V_28 -> V_50 ,
V_46 = & V_2 -> V_6 [ V_45 ] ; true ;
V_45 = V_46 -> V_50 ,
V_46 = & V_2 -> V_6 [ V_45 ] ) {
V_43 =
F_16 ( V_2 -> V_24 ,
V_45 ,
V_2 -> V_23 ) ;
if ( F_12 ( ! V_43 ) ) {
V_43 = false ;
break;
}
if ( V_46 -> V_34 )
break;
}
if ( ! V_43 ) {
V_5 = 0 ;
goto V_11;
}
}
if ( V_28 -> V_34 ) {
V_35 = F_20 ( F_21 ( V_28 -> V_48 ) ,
V_28 -> V_32 + V_51 ) ;
if ( F_12 ( ! V_35 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_22 ( V_35 , V_28 -> V_32 ) ;
} else {
V_35 = F_23 ( V_42 , V_52 ) ;
if ( F_12 ( ! V_35 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_22 ( V_35 , V_52 ) ;
memcpy ( V_35 -> V_53 , F_21 ( V_28 -> V_48 ) , V_52 ) ;
F_24 ( V_35 , 0 , V_28 -> V_48 , V_52 ,
V_28 -> V_32 - V_52 ,
F_25 ( V_28 -> V_32 - V_52 ) ) ;
for ( V_37 = 1U , V_45 = V_28 -> V_50 ,
V_46 = & V_2 -> V_6 [ V_45 ] ; true ;
V_45 = V_46 -> V_50 ,
V_46 = & V_2 -> V_6 [ V_45 ] , ++ V_37 ) {
F_24 ( V_35 , V_37 , V_46 -> V_48 , 0 ,
V_46 -> V_32 ,
F_25 ( V_28 -> V_32 -
V_52 ) ) ;
V_46 -> V_49 = 1 ;
if ( V_46 -> V_34 )
break;
}
}
V_35 -> V_54 = F_26 ( V_35 , V_42 ) ;
if ( F_12 ( V_28 -> V_55 ) ) {
++ V_2 -> V_56 . V_57 . V_58 ;
V_35 -> V_59 = V_60 ;
} else {
if ( V_28 -> V_61 ) {
F_27 ( V_35 ) ;
if ( V_28 -> V_62 || V_28 -> V_63 )
F_27 ( V_35 ) ;
} else {
V_35 -> V_59 = V_60 ;
}
}
F_28 ( V_35 , V_28 -> V_64 ,
V_28 -> V_65 ? V_66 :
V_67 ) ;
F_29 ( V_35 , V_2 -> V_15 ) ;
F_30 ( V_35 ) ;
++ V_2 -> V_56 . V_57 . V_68 ;
V_2 -> V_56 . V_57 . V_69 += V_35 -> V_32 ;
}
V_11:
return V_5 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned int V_70 = F_32 ( V_71 / V_72 +
( V_71 % V_72 ? 1 : 0 ) ) - 1 ;
struct V_8 * V_28 = NULL ;
int V_5 = 0 ;
int V_37 = 0 ;
for ( V_37 = F_33 ( V_2 ) ; V_37 -- ;
V_2 -> V_25 = F_10 ( V_2 , V_2 -> V_25 ) ) {
V_28 = & V_2 -> V_6 [ V_2 -> V_25 ] ;
V_28 -> V_73 = 0U ;
V_28 -> V_32 = V_71 ;
V_28 -> V_48 = F_34 ( V_74 | V_75 |
V_76 , V_70 ) ;
if ( ! V_28 -> V_48 ) {
V_5 = - V_10 ;
goto V_11;
}
V_28 -> V_31 = F_35 ( F_4 ( V_2 -> V_4 ) ,
V_28 -> V_48 , 0 ,
V_71 , V_77 ) ;
if ( F_36 ( F_4 ( V_2 -> V_4 ) , V_28 -> V_31 ) ) {
V_5 = - V_10 ;
goto V_11;
}
V_28 = NULL ;
}
V_11:
if ( V_5 < 0 ) {
if ( V_28 && V_28 -> V_48 )
F_19 ( V_28 -> V_48 , 0 ) ;
}
return V_5 ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
for (; V_2 -> V_24 != V_2 -> V_25 ;
V_2 -> V_24 = F_10 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_28 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
F_14 ( F_4 ( V_2 -> V_4 ) , V_28 -> V_31 ,
V_71 , V_77 ) ;
F_19 ( V_28 -> V_48 , 0 ) ;
}
V_11: ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
F_38 ( V_2 -> V_6 ) ;
if ( V_2 -> V_12 )
F_39 ( F_4 ( V_2 -> V_4 ) ,
V_2 -> V_7 * V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_14 ) ;
V_11: ;
}
