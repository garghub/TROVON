struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
F_2 ( & V_3 -> V_8 ) ;
V_6 = V_3 -> V_9 . V_5 ;
while ( V_6 ) {
V_7 = F_3 ( V_6 , struct V_1 , V_10 ) ;
if ( V_4 < V_7 -> V_4 )
V_6 = V_6 -> V_11 ;
else if ( V_4 > V_7 -> V_4 )
V_6 = V_6 -> V_12 ;
else {
F_4 ( & V_3 -> V_8 ) ;
return V_7 ;
}
}
F_4 ( & V_3 -> V_8 ) ;
return NULL ;
}
struct V_13 * F_5 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
int V_14 ;
if ( ! V_3 -> V_15 )
return NULL ;
F_2 ( & V_3 -> V_8 ) ;
V_6 = V_3 -> V_9 . V_5 ;
while ( V_6 ) {
V_7 = F_3 ( V_6 , struct V_1 , V_10 ) ;
if ( V_4 < V_7 -> V_4 )
V_6 = V_6 -> V_11 ;
else if ( V_4 > V_7 -> V_4 )
V_6 = V_6 -> V_12 ;
else {
V_14 = V_7 -> V_14 ;
F_4 ( & V_3 -> V_8 ) ;
return & V_3 -> V_15 [ V_14 ] . V_16 ;
}
}
F_4 ( & V_3 -> V_8 ) ;
return NULL ;
}
static inline long long F_6 ( const struct V_2 * V_3 )
{
long long V_17 , V_18 ;
V_17 = ( long long ) V_3 -> V_19 * V_3 -> V_20 + V_3 -> V_21 ;
V_18 = ( long long ) V_3 -> V_22 * V_3 -> V_20 ;
if ( V_17 >= V_18 )
return V_3 -> V_23 - V_17 + V_18 ;
else
return V_18 - V_17 ;
}
void F_7 ( struct V_2 * V_3 , struct V_1 * V_7 )
{
struct V_5 * * V_6 , * V_24 = NULL ;
struct V_1 * V_25 ;
struct V_26 * V_14 ;
F_2 ( & V_3 -> V_8 ) ;
V_6 = & V_3 -> V_9 . V_5 ;
while ( * V_6 ) {
V_24 = * V_6 ;
V_25 = F_3 ( V_24 , struct V_1 , V_10 ) ;
F_8 ( V_7 -> V_4 != V_25 -> V_4 ) ;
if ( V_7 -> V_4 < V_25 -> V_4 )
V_6 = & ( * V_6 ) -> V_11 ;
else
V_6 = & ( * V_6 ) -> V_12 ;
}
F_9 ( & V_7 -> V_10 , V_24 , V_6 ) ;
F_10 ( & V_7 -> V_10 , & V_3 -> V_9 ) ;
if ( V_3 -> V_15 ) {
V_14 = & V_3 -> V_15 [ V_7 -> V_14 ] ;
F_11 ( & V_7 -> V_27 , & V_14 -> V_28 ) ;
} else
F_8 ( V_3 -> V_29 && V_3 -> V_30 ) ;
V_3 -> V_31 += V_3 -> V_20 - V_7 -> V_32 ;
F_12 ( L_1 , V_7 -> V_4 ,
V_7 -> V_32 , F_13 ( V_7 -> V_14 ) , V_3 -> V_31 ) ;
F_4 ( & V_3 -> V_8 ) ;
}
int F_14 ( struct V_2 * V_3 , int V_14 , int V_4 , int V_33 )
{
int V_34 ;
struct V_1 * V_7 ;
struct V_35 * V_36 ;
V_7 = F_15 ( sizeof( struct V_1 ) , V_37 ) ;
if ( ! V_7 )
return - V_38 ;
V_36 = F_16 ( V_3 -> V_39 , V_37 ) ;
if ( ! V_36 ) {
F_17 ( V_7 ) ;
return - V_38 ;
}
F_18 ( & V_3 -> V_40 ) ;
F_8 ( ! V_3 -> V_41 && ! V_3 -> V_30 ) ;
if ( V_3 -> V_42 ) {
V_34 = - V_43 ;
goto V_44;
}
if ( F_6 ( V_3 ) - V_3 -> V_39 < V_3 -> V_45 ) {
F_12 ( L_2 ,
F_6 ( V_3 ) , V_3 -> V_45 ) ;
F_19 ( V_3 ) ;
V_34 = - V_46 ;
goto V_44;
}
if ( V_3 -> V_31 + V_3 -> V_20 - V_33 > V_3 -> V_47 ) {
F_12 ( L_3 ,
V_3 -> V_31 , V_3 -> V_47 ) ;
F_19 ( V_3 ) ;
V_34 = - V_46 ;
goto V_44;
}
if ( V_3 -> V_31 >= V_3 -> V_48 &&
V_3 -> V_49 == V_50 ) {
F_12 ( L_4 ,
V_3 -> V_31 , V_3 -> V_47 ) ;
F_20 ( V_3 ) ;
}
V_7 -> V_4 = V_4 ;
V_7 -> V_32 = V_33 ;
V_7 -> V_14 = V_14 ;
V_36 -> V_51 . V_52 = V_53 ;
V_36 -> V_4 = F_21 ( V_7 -> V_4 ) ;
V_36 -> V_33 = F_21 ( V_7 -> V_32 ) ;
V_36 -> V_14 = F_21 ( V_14 ) ;
if ( V_3 -> V_21 > V_3 -> V_20 - V_3 -> V_39 ) {
V_3 -> V_19 = F_22 ( V_3 , V_3 -> V_19 ) ;
V_3 -> V_21 = 0 ;
}
if ( V_3 -> V_21 == 0 ) {
V_34 = F_23 ( V_3 , V_3 -> V_19 ) ;
if ( V_34 )
goto V_44;
}
if ( V_7 -> V_32 == 0 ) {
V_34 = F_24 ( V_3 , V_7 -> V_4 ) ;
if ( V_34 )
goto V_44;
}
F_12 ( L_5 ,
V_3 -> V_19 , V_3 -> V_21 ) ;
V_34 = F_25 ( V_3 , V_36 , V_54 , V_3 -> V_19 ,
V_3 -> V_21 ) ;
if ( V_34 )
goto V_44;
V_3 -> V_21 += V_3 -> V_39 ;
F_7 ( V_3 , V_7 ) ;
F_26 ( & V_3 -> V_40 ) ;
F_17 ( V_36 ) ;
return 0 ;
V_44:
F_26 ( & V_3 -> V_40 ) ;
F_17 ( V_36 ) ;
F_17 ( V_7 ) ;
return V_34 ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_5 * V_6 ;
F_8 ( F_28 ( & V_3 -> V_55 ) ) ;
V_3 -> V_56 = 0 ;
F_2 ( & V_3 -> V_8 ) ;
V_6 = F_29 ( & V_3 -> V_9 ) ;
while ( V_6 ) {
struct V_5 * V_57 = V_6 ;
struct V_1 * V_7 ;
struct V_13 * V_16 ;
V_6 = F_30 ( V_6 ) ;
V_7 = F_3 ( V_57 , struct V_1 , V_10 ) ;
V_16 = & V_3 -> V_15 [ V_7 -> V_14 ] . V_16 ;
if ( V_16 -> V_4 == V_7 -> V_4 ) {
V_3 -> V_56 += V_16 -> V_33 - V_7 -> V_32 ;
F_12 ( L_6 ,
V_7 -> V_4 , V_7 -> V_32 , F_13 ( V_7 -> V_14 ) ,
V_16 -> V_33 - V_7 -> V_32 , V_3 -> V_56 ) ;
V_7 -> V_32 = V_16 -> V_33 ;
} else {
V_3 -> V_56 += V_3 -> V_20 - V_7 -> V_32 ;
F_12 ( L_7 ,
V_7 -> V_4 , V_7 -> V_32 , F_13 ( V_7 -> V_14 ) ,
V_3 -> V_20 - V_7 -> V_32 , V_3 -> V_56 ) ;
F_31 ( V_57 , & V_3 -> V_9 ) ;
F_32 ( & V_7 -> V_27 , & V_3 -> V_55 ) ;
}
}
F_4 ( & V_3 -> V_8 ) ;
}
int F_33 ( struct V_2 * V_3 , int * V_22 )
{
void * V_58 ;
struct V_59 * V_60 ;
struct V_35 * V_36 ;
int V_34 , V_61 , V_62 , V_63 ;
V_34 = F_34 ( V_3 ) ;
if ( V_34 )
return V_34 ;
V_62 = V_64 + V_3 -> V_65 * V_54 ;
V_62 = F_35 ( V_62 , V_3 -> V_66 ) ;
V_58 = V_60 = F_15 ( V_62 , V_37 ) ;
if ( ! V_58 )
return - V_38 ;
V_60 -> V_51 . V_52 = V_67 ;
V_60 -> V_68 = F_36 ( V_3 -> V_68 ) ;
F_37 ( V_3 , V_60 , V_64 , 0 ) ;
V_63 = V_64 ;
for ( V_61 = 0 ; V_61 < V_3 -> V_65 ; V_61 ++ ) {
int V_4 = V_3 -> V_15 [ V_61 ] . V_16 . V_4 ;
int V_33 = V_3 -> V_15 [ V_61 ] . V_16 . V_33 ;
if ( V_4 == - 1 || V_33 == V_3 -> V_20 )
continue;
F_12 ( L_8 ,
V_4 , V_33 , F_13 ( V_61 ) ) ;
V_36 = V_58 + V_63 ;
V_36 -> V_51 . V_52 = V_53 ;
V_36 -> V_4 = F_21 ( V_4 ) ;
V_36 -> V_33 = F_21 ( V_33 ) ;
V_36 -> V_14 = F_21 ( V_61 ) ;
F_37 ( V_3 , V_36 , V_54 , 0 ) ;
V_63 += V_54 ;
}
F_38 ( V_3 , V_58 + V_63 , F_35 ( V_63 , V_3 -> V_66 ) - V_63 ) ;
if ( V_3 -> V_21 ) {
V_3 -> V_19 = F_22 ( V_3 , V_3 -> V_19 ) ;
V_3 -> V_21 = 0 ;
}
if ( V_3 -> V_21 == 0 ) {
V_34 = F_23 ( V_3 , V_3 -> V_19 ) ;
if ( V_34 )
goto V_69;
}
V_63 = F_35 ( V_63 , V_3 -> V_66 ) ;
F_12 ( L_9 , V_3 -> V_19 , V_63 ) ;
V_34 = F_39 ( V_3 , V_3 -> V_19 , V_60 , 0 , V_63 ) ;
if ( V_34 )
goto V_69;
* V_22 = V_3 -> V_19 ;
V_3 -> V_21 += V_63 ;
if ( V_3 -> V_21 == V_3 -> V_20 ) {
V_3 -> V_19 = F_22 ( V_3 , V_3 -> V_19 ) ;
V_3 -> V_21 = 0 ;
}
F_27 ( V_3 ) ;
V_3 -> V_45 = 0 ;
V_69:
F_17 ( V_58 ) ;
return V_34 ;
}
int F_40 ( struct V_2 * V_3 , int V_22 )
{
int V_34 ;
F_18 ( & V_3 -> V_40 ) ;
F_12 ( L_10 ,
V_3 -> V_22 , V_22 ) ;
V_3 -> V_22 = V_22 ;
V_3 -> V_45 = V_3 -> V_20 ;
F_2 ( & V_3 -> V_8 ) ;
V_3 -> V_31 -= V_3 -> V_56 ;
F_4 ( & V_3 -> V_8 ) ;
V_34 = F_34 ( V_3 ) ;
F_26 ( & V_3 -> V_40 ) ;
return V_34 ;
}
int F_41 ( struct V_2 * V_3 , int V_70 )
{
int V_4 , V_34 = 0 ;
while ( ! F_28 ( & V_3 -> V_55 ) ) {
struct V_1 * V_7 ;
V_7 = F_42 ( V_3 -> V_55 . V_71 , struct V_1 , V_27 ) ;
V_34 = F_43 ( V_3 , V_7 -> V_4 ) ;
if ( V_34 )
return V_34 ;
F_44 ( & V_7 -> V_27 ) ;
F_17 ( V_7 ) ;
}
F_18 ( & V_3 -> V_40 ) ;
for ( V_4 = V_70 ; V_4 != V_3 -> V_22 ;
V_4 = F_22 ( V_3 , V_4 ) ) {
F_12 ( L_11 , V_4 ) ;
V_34 = F_23 ( V_3 , V_4 ) ;
if ( V_34 )
goto V_69;
}
V_69:
F_26 ( & V_3 -> V_40 ) ;
return V_34 ;
}
static int F_45 ( struct V_72 * V_73 , int V_4 )
{
struct V_5 * * V_6 = & V_73 -> V_5 , * V_24 = NULL ;
struct V_74 * V_75 ;
while ( * V_6 ) {
V_24 = * V_6 ;
V_75 = F_3 ( V_24 , struct V_74 , V_10 ) ;
if ( V_4 < V_75 -> V_4 )
V_6 = & ( * V_6 ) -> V_11 ;
else if ( V_4 > V_75 -> V_4 )
V_6 = & ( * V_6 ) -> V_12 ;
else
return 1 ;
}
V_75 = F_16 ( sizeof( struct V_74 ) , V_37 ) ;
if ( ! V_75 )
return - V_38 ;
V_75 -> V_4 = V_4 ;
F_9 ( & V_75 -> V_10 , V_24 , V_6 ) ;
F_10 ( & V_75 -> V_10 , V_73 ) ;
return 0 ;
}
static void F_46 ( struct V_72 * V_73 )
{
struct V_74 * V_75 , * V_76 ;
F_47 (dr, n, done_tree, rb)
F_17 ( V_75 ) ;
}
static int F_48 ( struct V_2 * V_3 , void * V_58 , int * V_4 , int * V_33 ,
void * V_77 )
{
struct V_78 * V_51 = V_77 ;
int V_63 = F_49 ( V_51 -> V_63 ) , V_79 = V_3 -> V_20 - * V_33 ;
if ( V_63 > V_79 ) {
int V_80 = F_35 ( * V_33 , V_3 -> V_66 ) , V_34 ;
F_38 ( V_3 , V_58 + * V_33 , V_80 - * V_33 ) ;
V_34 = F_50 ( V_3 , * V_4 , V_58 , V_80 ) ;
if ( V_34 )
return V_34 ;
* V_4 = F_22 ( V_3 , * V_4 ) ;
* V_33 = 0 ;
}
memcpy ( V_58 + * V_33 , V_77 , V_63 ) ;
* V_33 += F_35 ( V_63 , 8 ) ;
return 0 ;
}
int F_51 ( struct V_2 * V_3 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
struct V_72 V_73 = V_85 ;
int V_4 , V_34 , V_86 = 1 , V_87 , V_33 = 0 ;
void * V_58 ;
F_52 ( L_12 , V_3 -> V_22 ,
V_3 -> V_19 ) ;
V_58 = F_53 ( V_3 -> V_20 ) ;
if ( ! V_58 )
return - V_38 ;
V_4 = V_3 -> V_22 ;
V_87 = V_4 ;
while ( 1 ) {
V_82 = F_54 ( V_3 , V_4 , 0 , V_3 -> V_88 , 0 ) ;
if ( F_55 ( V_82 ) ) {
V_34 = F_56 ( V_82 ) ;
goto V_89;
}
F_57 (snod, &sleb->nodes, list) {
switch ( V_84 -> type ) {
case V_53 : {
struct V_35 * V_36 = V_84 -> V_77 ;
int V_90 = F_49 ( V_36 -> V_4 ) ;
V_34 = F_45 ( & V_73 , V_90 ) ;
if ( V_34 < 0 )
goto V_91;
if ( V_34 != 1 ) {
V_34 = F_48 ( V_3 , V_58 , & V_87 ,
& V_33 , V_84 -> V_77 ) ;
if ( V_34 )
goto V_91;
}
break;
}
case V_67 :
if ( ! V_86 )
break;
V_34 = F_48 ( V_3 , V_58 , & V_87 , & V_33 ,
V_84 -> V_77 ) ;
if ( V_34 )
goto V_91;
V_86 = 0 ;
break;
}
}
F_58 ( V_82 ) ;
if ( V_4 == V_3 -> V_19 )
break;
V_4 = F_22 ( V_3 , V_4 ) ;
}
if ( V_33 ) {
int V_80 = F_35 ( V_33 , V_3 -> V_66 ) ;
F_38 ( V_3 , V_58 + V_33 , V_80 - V_33 ) ;
V_34 = F_50 ( V_3 , V_87 , V_58 , V_80 ) ;
if ( V_34 )
goto V_89;
V_33 = F_35 ( V_33 , V_3 -> V_66 ) ;
}
F_46 ( & V_73 ) ;
F_59 ( V_58 ) ;
if ( V_87 == V_3 -> V_19 ) {
F_60 ( L_13 ) ;
return - V_92 ;
}
V_4 = V_87 ;
do {
V_4 = F_22 ( V_3 , V_4 ) ;
V_34 = F_23 ( V_3 , V_4 ) ;
if ( V_34 )
return V_34 ;
} while ( V_4 != V_3 -> V_19 );
V_3 -> V_19 = V_87 ;
V_3 -> V_21 = V_33 ;
F_52 ( L_14 , V_3 -> V_19 , V_3 -> V_21 ) ;
return 0 ;
V_91:
F_58 ( V_82 ) ;
V_89:
F_46 ( & V_73 ) ;
F_59 ( V_58 ) ;
return V_34 ;
}
static int F_34 ( struct V_2 * V_3 )
{
int V_61 , V_34 = 0 ;
struct V_1 * V_7 ;
long long V_31 = 0 ;
if ( ! F_61 ( V_3 ) )
return 0 ;
F_2 ( & V_3 -> V_8 ) ;
for ( V_61 = 0 ; V_61 < V_3 -> V_65 ; V_61 ++ )
F_57 (bud, &c->jheads[i].buds_list, list)
V_31 += V_3 -> V_20 - V_7 -> V_32 ;
if ( V_3 -> V_31 != V_31 ) {
F_60 ( L_15 ,
V_3 -> V_31 , V_31 ) ;
V_34 = - V_92 ;
}
F_4 ( & V_3 -> V_8 ) ;
return V_34 ;
}
