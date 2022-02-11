static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 type )
{
if ( F_2 ( type ) )
return & V_3 -> V_5 ;
else
return & V_3 -> V_6 ;
}
struct V_7 * F_3 ( struct V_2 * V_3 ,
enum V_4 type )
{
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , type ) ;
if ( ! V_8 )
return NULL ;
return & V_8 -> V_9 ;
}
void * F_4 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
if ( F_6 ( & V_8 -> V_14 ) ) {
F_7 ( & V_8 -> V_13 , V_12 ) ;
return NULL ;
}
V_11 = F_8 ( V_8 -> V_14 . V_15 , struct V_10 , V_16 ) ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_17 ;
}
void * F_9 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
if ( F_6 ( & V_8 -> V_14 ) ) {
F_7 ( & V_8 -> V_13 , V_12 ) ;
return NULL ;
}
V_11 = F_8 ( V_8 -> V_14 . V_15 , struct V_10 , V_16 ) ;
F_10 ( & V_11 -> V_16 ) ;
V_8 -> V_18 -- ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_17 ;
}
void * F_11 ( struct V_19 * V_20 )
{
unsigned long V_12 ;
void * V_21 = NULL ;
F_5 ( & V_20 -> V_22 , V_12 ) ;
if ( V_20 -> V_23 )
V_21 = V_20 -> V_23 -> V_24 ;
F_7 ( & V_20 -> V_22 , V_12 ) ;
return V_21 ;
}
static void F_12 ( struct V_19 * V_20 )
{
unsigned long V_12 ;
F_5 ( & V_20 -> V_22 , V_12 ) ;
if ( NULL != V_20 -> V_23 ) {
F_7 ( & V_20 -> V_22 , V_12 ) ;
F_13 ( L_1 ) ;
return;
}
if ( F_6 ( & V_20 -> V_25 ) ) {
F_7 ( & V_20 -> V_22 , V_12 ) ;
F_13 ( L_2 ) ;
return;
}
V_20 -> V_23 = F_8 ( V_20 -> V_25 . V_15 ,
struct V_2 , V_26 ) ;
V_20 -> V_23 -> V_27 |= V_28 ;
F_7 ( & V_20 -> V_22 , V_12 ) ;
V_20 -> V_29 -> V_30 ( V_20 -> V_23 -> V_24 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
unsigned long V_31 , V_12 ;
V_20 = V_3 -> V_20 ;
F_13 ( L_3 , V_3 ) ;
if ( ! V_3 -> V_5 . V_9 . V_32
|| ! V_3 -> V_6 . V_9 . V_32 ) {
F_13 ( L_4 ) ;
return;
}
F_5 ( & V_20 -> V_22 , V_31 ) ;
if ( V_3 -> V_27 & V_33 ) {
F_7 ( & V_20 -> V_22 , V_31 ) ;
F_13 ( L_5 ) ;
return;
}
F_5 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 ) ) {
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_7 ( & V_20 -> V_22 , V_31 ) ;
F_13 ( L_6 ) ;
return;
}
if ( F_6 ( & V_3 -> V_6 . V_14 ) ) {
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_7 ( & V_20 -> V_22 , V_31 ) ;
F_13 ( L_7 ) ;
return;
}
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( V_20 -> V_29 -> V_34
&& ( ! V_20 -> V_29 -> V_34 ( V_3 -> V_24 ) ) ) {
F_7 ( & V_20 -> V_22 , V_31 ) ;
F_13 ( L_8 ) ;
return;
}
F_15 ( & V_3 -> V_26 , & V_20 -> V_25 ) ;
V_3 -> V_27 |= V_33 ;
F_7 ( & V_20 -> V_22 , V_31 ) ;
F_12 ( V_20 ) ;
}
void F_16 ( struct V_19 * V_20 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_20 -> V_22 , V_12 ) ;
if ( ! V_20 -> V_23 || V_20 -> V_23 != V_3 ) {
F_7 ( & V_20 -> V_22 , V_12 ) ;
F_13 ( L_9 ) ;
return;
}
F_10 ( & V_20 -> V_23 -> V_26 ) ;
V_20 -> V_23 -> V_27 &= ~ ( V_33 | V_28 ) ;
F_17 ( & V_20 -> V_23 -> V_35 ) ;
V_20 -> V_23 = NULL ;
F_7 ( & V_20 -> V_22 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_20 ) ;
}
int F_18 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_7 * V_39 ;
V_39 = F_3 ( V_3 , V_38 -> type ) ;
return F_19 ( V_39 , V_38 ) ;
}
int F_20 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_7 * V_39 ;
int V_21 = 0 ;
unsigned int V_42 ;
V_39 = F_3 ( V_3 , V_41 -> type ) ;
V_21 = F_21 ( V_39 , V_41 ) ;
if ( V_41 -> V_43 == V_44 && ! F_2 ( V_39 -> type ) ) {
if ( F_22 ( V_39 -> type ) ) {
for ( V_42 = 0 ; V_42 < V_41 -> V_45 ; ++ V_42 )
V_41 -> V_46 . V_47 [ V_42 ] . V_46 . V_48
+= V_49 ;
} else {
V_41 -> V_46 . V_50 += V_49 ;
}
}
return V_21 ;
}
int F_23 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_7 * V_39 ;
int V_21 ;
V_39 = F_3 ( V_3 , V_41 -> type ) ;
V_21 = F_24 ( V_39 , V_41 ) ;
if ( ! V_21 )
F_14 ( V_3 ) ;
return V_21 ;
}
int F_25 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_40 * V_41 )
{
struct V_7 * V_39 ;
V_39 = F_3 ( V_3 , V_41 -> type ) ;
return F_26 ( V_39 , V_41 , V_36 -> V_51 & V_52 ) ;
}
int F_27 ( struct V_36 * V_36 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_39 ;
int V_21 ;
V_39 = F_3 ( V_3 , type ) ;
V_21 = F_28 ( V_39 , type ) ;
if ( ! V_21 )
F_14 ( V_3 ) ;
return V_21 ;
}
int F_29 ( struct V_36 * V_36 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_39 ;
V_39 = F_3 ( V_3 , type ) ;
return F_30 ( V_39 , type ) ;
}
unsigned int F_31 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_53 * V_54 )
{
struct V_7 * V_55 , * V_56 ;
struct V_57 * V_58 = NULL , * V_59 = NULL ;
unsigned int V_60 = 0 ;
unsigned long V_12 ;
V_55 = F_32 ( V_3 ) ;
V_56 = F_33 ( V_3 ) ;
if ( ( ! V_55 -> V_32 || F_6 ( & V_55 -> V_61 ) )
&& ( ! V_56 -> V_32 || F_6 ( & V_56 -> V_61 ) ) ) {
V_60 = V_62 ;
goto V_63;
}
if ( V_3 -> V_20 -> V_29 -> V_64 )
V_3 -> V_20 -> V_29 -> V_64 ( V_3 -> V_24 ) ;
F_34 ( V_36 , & V_55 -> V_65 , V_54 ) ;
F_34 ( V_36 , & V_56 -> V_65 , V_54 ) ;
if ( V_3 -> V_20 -> V_29 -> V_66 )
V_3 -> V_20 -> V_29 -> V_66 ( V_3 -> V_24 ) ;
F_5 ( & V_55 -> V_67 , V_12 ) ;
if ( ! F_6 ( & V_55 -> V_68 ) )
V_58 = F_35 ( & V_55 -> V_68 , struct V_57 ,
V_69 ) ;
if ( V_58 && ( V_58 -> V_70 == V_71
|| V_58 -> V_70 == V_72 ) )
V_60 |= V_73 | V_74 ;
F_7 ( & V_55 -> V_67 , V_12 ) ;
F_5 ( & V_56 -> V_67 , V_12 ) ;
if ( ! F_6 ( & V_56 -> V_68 ) )
V_59 = F_35 ( & V_56 -> V_68 , struct V_57 ,
V_69 ) ;
if ( V_59 && ( V_59 -> V_70 == V_71
|| V_59 -> V_70 == V_72 ) )
V_60 |= V_75 | V_76 ;
F_7 ( & V_56 -> V_67 , V_12 ) ;
V_63:
return V_60 ;
}
int F_36 ( struct V_36 * V_36 , struct V_2 * V_3 ,
struct V_77 * V_78 )
{
unsigned long V_50 = V_78 -> V_79 << V_80 ;
struct V_7 * V_39 ;
if ( V_50 < V_49 ) {
V_39 = F_32 ( V_3 ) ;
} else {
V_39 = F_33 ( V_3 ) ;
V_78 -> V_79 -= ( V_49 >> V_80 ) ;
}
return F_37 ( V_39 , V_78 ) ;
}
struct V_19 * F_38 ( struct V_81 * V_29 )
{
struct V_19 * V_20 ;
if ( ! V_29 )
return F_39 ( - V_82 ) ;
F_40 ( ! V_29 -> V_30 ) ;
F_40 ( ! V_29 -> V_83 ) ;
V_20 = F_41 ( sizeof *V_20 , V_84 ) ;
if ( ! V_20 )
return F_39 ( - V_85 ) ;
V_20 -> V_23 = NULL ;
V_20 -> V_29 = V_29 ;
F_42 ( & V_20 -> V_25 ) ;
F_43 ( & V_20 -> V_22 ) ;
return V_20 ;
}
void F_44 ( struct V_19 * V_20 )
{
F_45 ( V_20 ) ;
}
struct V_2 * F_46 ( struct V_19 * V_20 ,
void * V_86 ,
int (* F_47)( void * V_24 , struct V_7 * V_87 , struct V_7 * V_88 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_21 ;
V_3 = F_41 ( sizeof *V_3 , V_84 ) ;
if ( ! V_3 )
return F_39 ( - V_85 ) ;
V_3 -> V_24 = V_86 ;
V_3 -> V_20 = V_20 ;
F_48 ( & V_3 -> V_35 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_42 ( & V_5 -> V_14 ) ;
F_42 ( & V_6 -> V_14 ) ;
F_43 ( & V_5 -> V_13 ) ;
F_43 ( & V_6 -> V_13 ) ;
F_42 ( & V_3 -> V_26 ) ;
V_21 = F_47 ( V_86 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_21 )
goto V_89;
return V_3 ;
V_89:
F_45 ( V_3 ) ;
return F_39 ( V_21 ) ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_19 * V_20 ;
unsigned long V_12 ;
V_20 = V_3 -> V_20 ;
F_5 ( & V_20 -> V_22 , V_12 ) ;
if ( V_3 -> V_27 & V_28 ) {
F_7 ( & V_20 -> V_22 , V_12 ) ;
V_20 -> V_29 -> V_83 ( V_3 -> V_24 ) ;
F_13 ( L_10 , V_3 ) ;
F_50 ( V_3 -> V_35 , ! ( V_3 -> V_27 & V_28 ) ) ;
} else if ( V_3 -> V_27 & V_33 ) {
F_10 ( & V_3 -> V_26 ) ;
V_3 -> V_27 &= ~ ( V_33 | V_28 ) ;
F_7 ( & V_20 -> V_22 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_20 -> V_22 , V_12 ) ;
}
F_51 ( & V_3 -> V_6 . V_9 ) ;
F_51 ( & V_3 -> V_5 . V_9 ) ;
F_45 ( V_3 ) ;
}
void F_52 ( struct V_2 * V_3 , struct V_57 * V_17 )
{
struct V_10 * V_11 = F_53 ( V_17 , struct V_10 , V_17 ) ;
struct V_1 * V_8 ;
unsigned long V_12 ;
V_8 = F_1 ( V_3 , V_17 -> V_7 -> type ) ;
if ( ! V_8 )
return;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_15 ( & V_11 -> V_16 , & V_8 -> V_14 ) ;
V_8 -> V_18 ++ ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
}
