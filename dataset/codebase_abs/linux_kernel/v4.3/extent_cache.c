static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_8 * * V_10 )
{
struct V_1 * V_11 ;
V_11 = F_2 ( V_12 , V_13 ) ;
if ( ! V_11 )
return NULL ;
V_11 -> V_7 = * V_7 ;
F_3 ( & V_11 -> V_14 ) ;
F_4 ( & V_11 -> V_8 , V_9 , V_10 ) ;
F_5 ( & V_11 -> V_8 , & V_5 -> V_15 ) ;
V_5 -> V_16 ++ ;
F_6 ( & V_3 -> V_17 ) ;
return V_11 ;
}
static void F_7 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_1 * V_11 )
{
F_8 ( & V_11 -> V_8 , & V_5 -> V_15 ) ;
V_5 -> V_16 -- ;
F_9 ( & V_3 -> V_17 ) ;
if ( V_5 -> V_18 == V_11 )
V_5 -> V_18 = NULL ;
}
static struct V_4 * F_10 ( struct V_19 * V_19 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 ;
T_1 V_20 = V_19 -> V_21 ;
F_12 ( & V_3 -> V_22 ) ;
V_5 = F_13 ( & V_3 -> V_23 , V_20 ) ;
if ( ! V_5 ) {
V_5 = F_14 ( V_24 , V_25 ) ;
F_15 ( & V_3 -> V_23 , V_20 , V_5 ) ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_20 = V_20 ;
V_5 -> V_15 = V_26 ;
V_5 -> V_18 = NULL ;
F_16 ( & V_5 -> V_27 ) ;
F_17 ( & V_5 -> V_28 , 0 ) ;
V_5 -> V_16 = 0 ;
V_3 -> V_29 ++ ;
}
F_6 ( & V_5 -> V_28 ) ;
F_18 ( & V_3 -> V_22 ) ;
F_19 ( V_19 ) -> V_4 = V_5 ;
return V_5 ;
}
static struct V_1 * F_20 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int V_30 )
{
struct V_8 * V_31 = V_5 -> V_15 . V_8 ;
struct V_1 * V_11 = V_5 -> V_18 ;
if ( V_11 ) {
struct V_6 * V_32 = & V_11 -> V_7 ;
if ( V_32 -> V_30 <= V_30 && V_32 -> V_30 + V_32 -> V_33 > V_30 ) {
F_21 ( V_3 ) ;
return V_11 ;
}
}
while ( V_31 ) {
V_11 = F_22 ( V_31 , struct V_1 , V_8 ) ;
if ( V_30 < V_11 -> V_7 . V_30 ) {
V_31 = V_31 -> V_34 ;
} else if ( V_30 >= V_11 -> V_7 . V_30 + V_11 -> V_7 . V_33 ) {
V_31 = V_31 -> V_35 ;
} else {
F_23 ( V_3 ) ;
return V_11 ;
}
}
return NULL ;
}
static struct V_1 * F_24 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * * V_10 = & V_5 -> V_15 . V_8 ;
struct V_1 * V_11 ;
V_11 = F_1 ( V_3 , V_5 , V_7 , NULL , V_10 ) ;
if ( ! V_11 )
return NULL ;
V_5 -> V_36 = V_11 -> V_7 ;
V_5 -> V_18 = V_11 ;
return V_11 ;
}
static unsigned int F_25 ( struct V_2 * V_3 ,
struct V_4 * V_5 , bool V_37 )
{
struct V_8 * V_31 , * V_38 ;
struct V_1 * V_11 ;
unsigned int V_16 = V_5 -> V_16 ;
V_31 = F_26 ( & V_5 -> V_15 ) ;
while ( V_31 ) {
V_38 = F_27 ( V_31 ) ;
V_11 = F_22 ( V_31 , struct V_1 , V_8 ) ;
if ( V_37 ) {
F_28 ( & V_3 -> V_39 ) ;
if ( ! F_29 ( & V_11 -> V_14 ) )
F_30 ( & V_11 -> V_14 ) ;
F_31 ( & V_3 -> V_39 ) ;
}
if ( V_37 || F_29 ( & V_11 -> V_14 ) ) {
F_7 ( V_3 , V_5 , V_11 ) ;
F_32 ( V_12 , V_11 ) ;
}
V_31 = V_38 ;
}
return V_16 - V_5 -> V_16 ;
}
static void F_33 ( struct V_19 * V_19 , T_2 V_30 )
{
struct V_6 * V_36 = & F_19 ( V_19 ) -> V_4 -> V_36 ;
if ( V_36 -> V_30 <= V_30 && V_36 -> V_30 + V_36 -> V_33 > V_30 )
V_36 -> V_33 = 0 ;
}
void F_34 ( struct V_19 * V_19 , T_2 V_30 )
{
if ( ! F_35 ( V_19 ) )
return;
F_33 ( V_19 , V_30 ) ;
}
void F_36 ( struct V_19 * V_19 , struct V_40 * V_41 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 ;
struct V_1 * V_11 ;
struct V_6 V_7 ;
if ( ! F_35 ( V_19 ) )
return;
V_5 = F_10 ( V_19 ) ;
if ( ! V_41 || F_37 ( V_41 -> V_33 ) < V_42 )
return;
F_38 ( & V_7 , F_37 ( V_41 -> V_30 ) ,
F_37 ( V_41 -> V_43 ) , F_37 ( V_41 -> V_33 ) ) ;
F_39 ( & V_5 -> V_27 ) ;
if ( V_5 -> V_16 )
goto V_44;
V_11 = F_24 ( V_3 , V_5 , & V_7 ) ;
if ( V_11 ) {
F_28 ( & V_3 -> V_39 ) ;
F_40 ( & V_11 -> V_14 , & V_3 -> V_45 ) ;
F_31 ( & V_3 -> V_39 ) ;
}
V_44:
F_41 ( & V_5 -> V_27 ) ;
}
static bool F_42 ( struct V_19 * V_19 , T_2 V_46 ,
struct V_6 * V_7 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = F_19 ( V_19 ) -> V_4 ;
struct V_1 * V_11 ;
bool V_47 = false ;
F_43 ( V_3 , ! V_5 ) ;
F_44 ( V_19 , V_46 ) ;
F_45 ( & V_5 -> V_27 ) ;
if ( V_5 -> V_36 . V_30 <= V_46 &&
V_5 -> V_36 . V_30 + V_5 -> V_36 . V_33 > V_46 ) {
* V_7 = V_5 -> V_36 ;
V_47 = true ;
F_46 ( V_3 ) ;
goto V_44;
}
V_11 = F_20 ( V_3 , V_5 , V_46 ) ;
if ( V_11 ) {
* V_7 = V_11 -> V_7 ;
F_28 ( & V_3 -> V_39 ) ;
if ( ! F_29 ( & V_11 -> V_14 ) )
F_47 ( & V_11 -> V_14 , & V_3 -> V_45 ) ;
V_5 -> V_18 = V_11 ;
F_31 ( & V_3 -> V_39 ) ;
V_47 = true ;
}
V_44:
F_48 ( V_3 ) ;
F_49 ( & V_5 -> V_27 ) ;
F_50 ( V_19 , V_46 , V_7 ) ;
return V_47 ;
}
static struct V_1 * F_51 ( struct V_4 * V_5 ,
unsigned int V_30 ,
struct V_1 * * V_48 ,
struct V_1 * * V_49 ,
struct V_8 * * * V_50 ,
struct V_8 * * V_51 )
{
struct V_8 * * V_52 = & V_5 -> V_15 . V_8 ;
struct V_8 * V_9 = NULL , * V_53 ;
struct V_1 * V_11 = V_5 -> V_18 ;
* V_50 = NULL ;
* V_51 = NULL ;
* V_48 = NULL ;
* V_49 = NULL ;
if ( F_52 ( & V_5 -> V_15 ) )
return NULL ;
if ( V_11 ) {
struct V_6 * V_32 = & V_11 -> V_7 ;
if ( V_32 -> V_30 <= V_30 && V_32 -> V_30 + V_32 -> V_33 > V_30 )
goto V_54;
}
while ( * V_52 ) {
V_9 = * V_52 ;
V_11 = F_22 ( * V_52 , struct V_1 , V_8 ) ;
if ( V_30 < V_11 -> V_7 . V_30 )
V_52 = & ( * V_52 ) -> V_34 ;
else if ( V_30 >= V_11 -> V_7 . V_30 + V_11 -> V_7 . V_33 )
V_52 = & ( * V_52 ) -> V_35 ;
else
goto V_54;
}
* V_50 = V_52 ;
* V_51 = V_9 ;
V_11 = F_22 ( V_9 , struct V_1 , V_8 ) ;
V_53 = V_9 ;
if ( V_9 && V_30 > V_11 -> V_7 . V_30 )
V_53 = F_27 ( V_9 ) ;
* V_49 = V_53 ?
F_22 ( V_53 , struct V_1 , V_8 ) : NULL ;
V_53 = V_9 ;
if ( V_9 && V_30 < V_11 -> V_7 . V_30 )
V_53 = F_53 ( V_9 ) ;
* V_48 = V_53 ?
F_22 ( V_53 , struct V_1 , V_8 ) : NULL ;
return NULL ;
V_54:
if ( V_30 == V_11 -> V_7 . V_30 ) {
V_53 = F_53 ( & V_11 -> V_8 ) ;
* V_48 = V_53 ?
F_22 ( V_53 , struct V_1 , V_8 ) : NULL ;
}
if ( V_30 == V_11 -> V_7 . V_30 + V_11 -> V_7 . V_33 - 1 ) {
V_53 = F_27 ( & V_11 -> V_8 ) ;
* V_49 = V_53 ?
F_22 ( V_53 , struct V_1 , V_8 ) : NULL ;
}
return V_11 ;
}
static struct V_1 * F_54 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_1 * * V_55 ,
struct V_1 * V_48 ,
struct V_1 * V_49 )
{
struct V_1 * V_11 = NULL ;
if ( V_48 && F_55 ( V_7 , & V_48 -> V_7 ) ) {
V_48 -> V_7 . V_33 += V_7 -> V_33 ;
V_7 = & V_48 -> V_7 ;
V_11 = V_48 ;
}
if ( V_49 && F_56 ( V_7 , & V_49 -> V_7 ) ) {
if ( V_11 ) {
F_7 ( V_3 , V_5 , V_48 ) ;
* V_55 = V_48 ;
}
V_49 -> V_7 . V_30 = V_7 -> V_30 ;
V_49 -> V_7 . V_43 = V_7 -> V_43 ;
V_49 -> V_7 . V_33 += V_7 -> V_33 ;
V_11 = V_49 ;
}
if ( V_11 ) {
if ( V_11 -> V_7 . V_33 > V_5 -> V_36 . V_33 )
V_5 -> V_36 = V_11 -> V_7 ;
V_5 -> V_18 = V_11 ;
}
return V_11 ;
}
static struct V_1 * F_57 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_8 * * V_50 ,
struct V_8 * V_51 )
{
struct V_8 * * V_10 = & V_5 -> V_15 . V_8 ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_11 = NULL ;
if ( V_50 && V_51 ) {
V_9 = V_51 ;
V_10 = V_50 ;
goto V_56;
}
while ( * V_10 ) {
V_9 = * V_10 ;
V_11 = F_22 ( V_9 , struct V_1 , V_8 ) ;
if ( V_7 -> V_30 < V_11 -> V_7 . V_30 )
V_10 = & ( * V_10 ) -> V_34 ;
else if ( V_7 -> V_30 >= V_11 -> V_7 . V_30 + V_11 -> V_7 . V_33 )
V_10 = & ( * V_10 ) -> V_35 ;
else
F_43 ( V_3 , 1 ) ;
}
V_56:
V_11 = F_1 ( V_3 , V_5 , V_7 , V_9 , V_10 ) ;
if ( ! V_11 )
return NULL ;
if ( V_11 -> V_7 . V_33 > V_5 -> V_36 . V_33 )
V_5 -> V_36 = V_11 -> V_7 ;
V_5 -> V_18 = V_11 ;
return V_11 ;
}
unsigned int F_58 ( struct V_19 * V_19 ,
T_2 V_30 , T_3 V_57 , unsigned int V_33 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = F_19 ( V_19 ) -> V_4 ;
struct V_1 * V_11 = NULL , * V_58 = NULL , * V_59 = NULL , * V_60 = NULL ;
struct V_1 * V_61 = NULL , * V_62 = NULL ;
struct V_6 V_7 , V_63 , V_64 ;
struct V_8 * * V_50 = NULL , * V_51 = NULL ;
unsigned int V_65 = V_30 + V_33 ;
unsigned int V_66 = ( unsigned int ) V_30 ;
if ( ! V_5 )
return false ;
F_39 ( & V_5 -> V_27 ) ;
if ( F_59 ( F_19 ( V_19 ) , V_67 ) ) {
F_41 ( & V_5 -> V_27 ) ;
return false ;
}
V_64 = V_5 -> V_36 ;
V_63 . V_33 = 0 ;
F_33 ( V_19 , V_30 ) ;
V_11 = F_51 ( V_5 , V_30 , & V_61 , & V_62 ,
& V_50 , & V_51 ) ;
if ( ! V_11 ) {
if ( V_62 ) {
V_11 = V_62 ;
F_43 ( V_3 , V_11 -> V_7 . V_30 <= V_66 ) ;
V_66 = V_11 -> V_7 . V_30 ;
} else {
goto V_68;
}
}
while ( V_11 ) {
struct V_8 * V_31 ;
if ( V_66 >= V_65 )
break;
V_63 = V_11 -> V_7 ;
V_58 = V_59 = NULL ;
V_31 = F_27 ( & V_11 -> V_8 ) ;
if ( V_66 > V_63 . V_30 && V_65 >= V_63 . V_30 + V_63 . V_33 ) {
V_11 -> V_7 . V_33 = V_66 - V_63 . V_30 ;
if ( V_11 -> V_7 . V_33 < V_42 ) {
F_7 ( V_3 , V_5 , V_11 ) ;
V_50 = NULL ;
V_51 = NULL ;
goto V_69;
}
if ( F_60 ( & V_63 , & V_5 -> V_36 ) )
V_5 -> V_36 = V_11 -> V_7 ;
goto V_38;
}
if ( V_66 <= V_63 . V_30 && V_65 < V_63 . V_30 + V_63 . V_33 ) {
V_11 -> V_7 . V_30 = V_65 ;
V_11 -> V_7 . V_43 += V_65 - V_63 . V_30 ;
V_11 -> V_7 . V_33 -= V_65 - V_63 . V_30 ;
if ( V_11 -> V_7 . V_33 < V_42 ) {
F_7 ( V_3 , V_5 , V_11 ) ;
V_50 = NULL ;
V_51 = NULL ;
goto V_69;
}
if ( F_60 ( & V_63 , & V_5 -> V_36 ) )
V_5 -> V_36 = V_11 -> V_7 ;
goto V_38;
}
F_7 ( V_3 , V_5 , V_11 ) ;
V_50 = NULL ;
V_51 = NULL ;
if ( V_66 <= V_63 . V_30 && V_65 >= V_63 . V_30 + V_63 . V_33 ) {
if ( F_60 ( & V_63 , & V_5 -> V_36 ) )
V_5 -> V_36 . V_33 = 0 ;
goto V_69;
}
if ( V_63 . V_33 > V_42 ) {
unsigned int V_70 ;
if ( V_66 - V_63 . V_30 >= V_42 ) {
F_38 ( & V_7 , V_63 . V_30 , V_63 . V_43 ,
V_66 - V_63 . V_30 ) ;
V_58 = F_57 ( V_3 , V_5 , & V_7 ,
NULL , NULL ) ;
}
V_70 = V_63 . V_30 + V_63 . V_33 ;
if ( V_70 - V_65 >= V_42 ) {
F_38 ( & V_7 , V_65 ,
V_65 - V_63 . V_30 + V_63 . V_43 ,
V_70 - V_65 ) ;
V_59 = F_57 ( V_3 , V_5 , & V_7 ,
NULL , NULL ) ;
}
}
V_69:
F_28 ( & V_3 -> V_39 ) ;
if ( V_11 && ! F_29 ( & V_11 -> V_14 ) )
F_61 ( & V_11 -> V_14 ) ;
if ( V_58 )
F_40 ( & V_58 -> V_14 , & V_3 -> V_45 ) ;
if ( V_59 )
F_40 ( & V_59 -> V_14 , & V_3 -> V_45 ) ;
F_31 ( & V_3 -> V_39 ) ;
if ( V_11 )
F_32 ( V_12 , V_11 ) ;
V_38:
V_11 = V_31 ? F_22 ( V_31 , struct V_1 , V_8 ) : NULL ;
V_62 = V_11 ;
if ( V_11 )
V_66 = V_11 -> V_7 . V_30 ;
}
V_68:
if ( V_57 ) {
struct V_1 * V_55 = NULL ;
F_38 ( & V_7 , V_30 , V_57 , V_33 ) ;
V_60 = F_54 ( V_3 , V_5 , & V_7 , & V_55 ,
V_61 , V_62 ) ;
if ( ! V_60 )
V_60 = F_57 ( V_3 , V_5 , & V_7 ,
V_50 , V_51 ) ;
if ( V_63 . V_33 >= 1 &&
V_64 . V_33 < V_42 &&
V_5 -> V_36 . V_33 < V_42 ) {
V_5 -> V_36 . V_33 = 0 ;
F_62 ( F_19 ( V_19 ) , V_67 ) ;
}
F_28 ( & V_3 -> V_39 ) ;
if ( V_60 ) {
if ( F_29 ( & V_60 -> V_14 ) )
F_40 ( & V_60 -> V_14 , & V_3 -> V_45 ) ;
else
F_47 ( & V_60 -> V_14 , & V_3 -> V_45 ) ;
}
if ( V_55 && ! F_29 ( & V_55 -> V_14 ) )
F_61 ( & V_55 -> V_14 ) ;
F_31 ( & V_3 -> V_39 ) ;
if ( V_55 )
F_32 ( V_12 , V_55 ) ;
}
if ( F_59 ( F_19 ( V_19 ) , V_67 ) )
F_25 ( V_3 , V_5 , true ) ;
F_41 ( & V_5 -> V_27 ) ;
return ! F_60 ( & V_64 , & V_5 -> V_36 ) ;
}
unsigned int F_63 ( struct V_2 * V_3 , int V_71 )
{
struct V_4 * V_72 [ V_73 ] ;
struct V_1 * V_11 , * V_74 ;
unsigned long V_20 = F_64 ( V_3 ) ;
struct V_75 * V_15 = & V_3 -> V_23 ;
unsigned int V_76 ;
unsigned int V_77 = 0 , V_78 = 0 ;
int V_79 ;
if ( ! F_65 ( V_3 , V_80 ) )
return 0 ;
if ( ! F_66 ( & V_3 -> V_22 ) )
goto V_44;
while ( ( V_76 = F_67 ( V_15 ,
( void * * ) V_72 , V_20 , V_73 ) ) ) {
unsigned V_81 ;
V_20 = V_72 [ V_76 - 1 ] -> V_20 + 1 ;
for ( V_81 = 0 ; V_81 < V_76 ; V_81 ++ ) {
struct V_4 * V_5 = V_72 [ V_81 ] ;
if ( ! F_68 ( & V_5 -> V_28 ) ) {
F_39 ( & V_5 -> V_27 ) ;
V_77 += F_25 ( V_3 , V_5 , true ) ;
F_41 ( & V_5 -> V_27 ) ;
F_69 ( V_15 , V_5 -> V_20 ) ;
F_32 ( V_24 , V_5 ) ;
V_3 -> V_29 -- ;
V_78 ++ ;
if ( V_77 + V_78 >= V_71 )
goto V_82;
}
}
}
F_18 ( & V_3 -> V_22 ) ;
if ( ! F_66 ( & V_3 -> V_22 ) )
goto V_44;
V_79 = V_71 - ( V_77 + V_78 ) ;
F_28 ( & V_3 -> V_39 ) ;
F_70 (en, tmp, &sbi->extent_list, list) {
if ( ! V_79 -- )
break;
F_30 ( & V_11 -> V_14 ) ;
}
F_31 ( & V_3 -> V_39 ) ;
while ( ( V_76 = F_67 ( V_15 ,
( void * * ) V_72 , V_20 , V_73 ) ) ) {
unsigned V_81 ;
V_20 = V_72 [ V_76 - 1 ] -> V_20 + 1 ;
for ( V_81 = 0 ; V_81 < V_76 ; V_81 ++ ) {
struct V_4 * V_5 = V_72 [ V_81 ] ;
F_39 ( & V_5 -> V_27 ) ;
V_77 += F_25 ( V_3 , V_5 , false ) ;
F_41 ( & V_5 -> V_27 ) ;
if ( V_77 + V_78 >= V_71 )
break;
}
}
V_82:
F_18 ( & V_3 -> V_22 ) ;
V_44:
F_71 ( V_3 , V_77 , V_78 ) ;
return V_77 + V_78 ;
}
unsigned int F_72 ( struct V_19 * V_19 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = F_19 ( V_19 ) -> V_4 ;
unsigned int V_77 = 0 ;
if ( ! V_5 )
return 0 ;
F_39 ( & V_5 -> V_27 ) ;
V_77 = F_25 ( V_3 , V_5 , true ) ;
F_41 ( & V_5 -> V_27 ) ;
return V_77 ;
}
void F_73 ( struct V_19 * V_19 )
{
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = F_19 ( V_19 ) -> V_4 ;
unsigned int V_77 = 0 ;
if ( ! V_5 )
return;
if ( V_19 -> V_83 && ! F_74 ( V_19 ) && V_5 -> V_16 ) {
F_9 ( & V_5 -> V_28 ) ;
return;
}
V_77 = F_72 ( V_19 ) ;
F_12 ( & V_3 -> V_22 ) ;
F_9 ( & V_5 -> V_28 ) ;
F_43 ( V_3 , F_68 ( & V_5 -> V_28 ) || V_5 -> V_16 ) ;
F_69 ( & V_3 -> V_23 , V_19 -> V_21 ) ;
F_32 ( V_24 , V_5 ) ;
V_3 -> V_29 -- ;
F_18 ( & V_3 -> V_22 ) ;
F_19 ( V_19 ) -> V_4 = NULL ;
F_75 ( V_19 , V_77 ) ;
}
bool F_76 ( struct V_19 * V_19 , T_2 V_46 ,
struct V_6 * V_7 )
{
if ( ! F_35 ( V_19 ) )
return false ;
return F_42 ( V_19 , V_46 , V_7 ) ;
}
void F_77 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = F_19 ( V_85 -> V_19 ) ;
T_2 V_30 ;
if ( ! F_35 ( V_85 -> V_19 ) )
return;
F_43 ( F_11 ( V_85 -> V_19 ) , V_85 -> V_88 == V_89 ) ;
V_30 = F_78 ( F_79 ( V_85 -> V_90 ) , V_87 ) +
V_85 -> V_91 ;
if ( F_58 ( V_85 -> V_19 , V_30 , V_85 -> V_88 , 1 ) )
F_80 ( V_85 ) ;
}
void F_81 ( struct V_84 * V_85 ,
T_2 V_30 , T_3 V_57 , unsigned int V_33 )
{
if ( ! F_35 ( V_85 -> V_19 ) )
return;
if ( F_58 ( V_85 -> V_19 , V_30 , V_57 , V_33 ) )
F_80 ( V_85 ) ;
}
void F_82 ( struct V_2 * V_3 )
{
F_83 ( & V_3 -> V_23 , V_92 ) ;
F_84 ( & V_3 -> V_22 ) ;
F_3 ( & V_3 -> V_45 ) ;
F_85 ( & V_3 -> V_39 ) ;
V_3 -> V_29 = 0 ;
F_17 ( & V_3 -> V_17 , 0 ) ;
}
int T_4 F_86 ( void )
{
V_24 = F_87 ( L_1 ,
sizeof( struct V_4 ) ) ;
if ( ! V_24 )
return - V_93 ;
V_12 = F_87 ( L_2 ,
sizeof( struct V_1 ) ) ;
if ( ! V_12 ) {
F_88 ( V_24 ) ;
return - V_93 ;
}
return 0 ;
}
void F_89 ( void )
{
F_88 ( V_12 ) ;
F_88 ( V_24 ) ;
}
