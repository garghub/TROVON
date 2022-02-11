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
F_9 ( & V_2 -> V_26 . V_27 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 = F_4 ( V_2 -> V_4 ) ;
for (; V_2 -> V_24 != V_2 -> V_23 ;
V_2 -> V_24 = F_11 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_30 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
if ( F_12 ( V_30 -> V_31 ) ) {
if ( F_13 ( V_30 -> V_32 ) )
F_14 ( V_29 , V_30 -> V_33 , V_30 -> V_34 ,
V_35 ) ;
else
F_15 ( V_29 , V_30 -> V_33 , V_30 -> V_34 ,
V_35 ) ;
}
if ( F_13 ( V_30 -> V_36 ) )
F_16 ( V_30 -> V_37 ) ;
}
}
static inline unsigned int F_17 ( unsigned int V_38 , unsigned int V_39 ,
unsigned int V_40 )
{
return ( V_38 < V_40 ) ? ( ( V_38 < V_39 ) && ( V_39 < V_40 ) ) : ( ( V_38 < V_39 ) || ( V_39 < V_40 ) ) ;
}
int F_18 ( struct V_1 * V_2 , int * V_41 , int V_42 )
{
struct V_43 * V_44 = F_19 ( V_2 -> V_4 ) ;
int V_5 = 0 ;
bool V_45 = true ;
for (; ( V_2 -> V_24 != V_2 -> V_23 ) && V_42 ;
V_2 -> V_24 = F_11 ( V_2 , V_2 -> V_24 ) ,
-- V_42 , ++ ( * V_41 ) ) {
struct V_8 * V_30 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
struct V_46 * V_37 = NULL ;
unsigned int V_47 = 0U ;
unsigned int V_39 = 0U ;
struct V_8 * V_48 = NULL ;
if ( V_30 -> V_49 ) {
F_20 ( V_30 -> V_50 , 0 ) ;
continue;
}
if ( V_30 -> V_51 )
continue;
if ( ! V_30 -> V_36 ) {
for ( V_47 = V_30 -> V_52 ,
V_48 = & V_2 -> V_6 [ V_47 ] ; true ;
V_47 = V_48 -> V_52 ,
V_48 = & V_2 -> V_6 [ V_47 ] ) {
V_45 =
F_17 ( V_2 -> V_24 ,
V_47 ,
V_2 -> V_23 ) ;
if ( F_13 ( ! V_45 ) ) {
V_45 = false ;
break;
}
if ( V_48 -> V_36 )
break;
}
if ( ! V_45 ) {
V_5 = 0 ;
goto V_11;
}
}
if ( V_30 -> V_36 ) {
V_37 = F_21 ( F_22 ( V_30 -> V_50 ) ,
V_30 -> V_34 + V_53 ) ;
if ( F_13 ( ! V_37 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_23 ( V_37 , V_30 -> V_34 ) ;
} else {
V_37 = F_24 ( V_44 , V_54 ) ;
if ( F_13 ( ! V_37 ) ) {
V_5 = - V_10 ;
goto V_11;
}
F_23 ( V_37 , V_54 ) ;
memcpy ( V_37 -> V_55 , F_22 ( V_30 -> V_50 ) , V_54 ) ;
F_25 ( V_37 , 0 , V_30 -> V_50 , V_54 ,
V_30 -> V_34 - V_54 ,
F_26 ( V_30 -> V_34 - V_54 ) ) ;
for ( V_39 = 1U , V_47 = V_30 -> V_52 ,
V_48 = & V_2 -> V_6 [ V_47 ] ; true ;
V_47 = V_48 -> V_52 ,
V_48 = & V_2 -> V_6 [ V_47 ] , ++ V_39 ) {
F_25 ( V_37 , V_39 , V_48 -> V_50 , 0 ,
V_48 -> V_34 ,
F_26 ( V_30 -> V_34 -
V_54 ) ) ;
V_48 -> V_51 = 1 ;
if ( V_48 -> V_36 )
break;
}
}
V_37 -> V_56 = F_27 ( V_37 , V_44 ) ;
if ( F_13 ( V_30 -> V_57 ) ) {
++ V_2 -> V_58 . V_59 . V_60 ;
F_28 ( V_37 ) ;
} else {
if ( V_30 -> V_61 ) {
F_29 ( V_37 ) ;
if ( V_30 -> V_62 || V_30 -> V_63 )
F_29 ( V_37 ) ;
} else {
V_37 -> V_64 = V_65 ;
}
}
F_30 ( V_37 , V_30 -> V_66 ,
V_30 -> V_67 ? V_68 :
V_69 ) ;
F_31 ( V_37 , V_2 -> V_15 ) ;
F_32 ( V_37 ) ;
++ V_2 -> V_58 . V_59 . V_70 ;
V_2 -> V_58 . V_59 . V_71 += V_37 -> V_34 ;
}
V_11:
return V_5 ;
}
int F_33 ( struct V_1 * V_2 )
{
unsigned int V_72 = F_34 ( V_73 / V_74 +
( V_73 % V_74 ? 1 : 0 ) ) - 1 ;
struct V_8 * V_30 = NULL ;
int V_5 = 0 ;
int V_39 = 0 ;
for ( V_39 = F_35 ( V_2 ) ; V_39 -- ;
V_2 -> V_25 = F_11 ( V_2 , V_2 -> V_25 ) ) {
V_30 = & V_2 -> V_6 [ V_2 -> V_25 ] ;
V_30 -> V_75 = 0U ;
V_30 -> V_34 = V_73 ;
V_30 -> V_50 = F_36 ( V_76 | V_77 |
V_78 , V_72 ) ;
if ( ! V_30 -> V_50 ) {
V_5 = - V_10 ;
goto V_11;
}
V_30 -> V_33 = F_37 ( F_4 ( V_2 -> V_4 ) ,
V_30 -> V_50 , 0 ,
V_73 , V_79 ) ;
if ( F_38 ( F_4 ( V_2 -> V_4 ) , V_30 -> V_33 ) ) {
V_5 = - V_10 ;
goto V_11;
}
V_30 = NULL ;
}
V_11:
if ( V_5 < 0 ) {
if ( V_30 && V_30 -> V_50 )
F_20 ( V_30 -> V_50 , 0 ) ;
}
return V_5 ;
}
void F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
for (; V_2 -> V_24 != V_2 -> V_25 ;
V_2 -> V_24 = F_11 ( V_2 , V_2 -> V_24 ) ) {
struct V_8 * V_30 = & V_2 -> V_6 [ V_2 -> V_24 ] ;
F_15 ( F_4 ( V_2 -> V_4 ) , V_30 -> V_33 ,
V_73 , V_79 ) ;
F_20 ( V_30 -> V_50 , 0 ) ;
}
V_11: ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( ! V_2 )
goto V_11;
F_40 ( V_2 -> V_6 ) ;
if ( V_2 -> V_12 )
F_41 ( F_4 ( V_2 -> V_4 ) ,
V_2 -> V_7 * V_2 -> V_13 , V_2 -> V_12 ,
V_2 -> V_14 ) ;
V_11: ;
}
