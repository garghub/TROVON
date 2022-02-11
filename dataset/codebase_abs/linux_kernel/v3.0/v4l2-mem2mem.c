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
if ( F_6 ( & V_8 -> V_14 ) )
goto V_15;
V_11 = F_7 ( V_8 -> V_14 . V_16 , struct V_10 , V_17 ) ;
V_15:
F_8 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_18 ;
}
void * F_9 ( struct V_1 * V_8 )
{
struct V_10 * V_11 = NULL ;
unsigned long V_12 ;
F_5 ( & V_8 -> V_13 , V_12 ) ;
if ( ! F_6 ( & V_8 -> V_14 ) ) {
V_11 = F_7 ( V_8 -> V_14 . V_16 , struct V_10 ,
V_17 ) ;
F_10 ( & V_11 -> V_17 ) ;
V_8 -> V_19 -- ;
}
F_8 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_18 ;
}
void * F_11 ( struct V_20 * V_21 )
{
unsigned long V_12 ;
void * V_22 = NULL ;
F_5 ( & V_21 -> V_23 , V_12 ) ;
if ( V_21 -> V_24 )
V_22 = V_21 -> V_24 -> V_25 ;
F_8 ( & V_21 -> V_23 , V_12 ) ;
return V_22 ;
}
static void F_12 ( struct V_20 * V_21 )
{
unsigned long V_12 ;
F_5 ( & V_21 -> V_23 , V_12 ) ;
if ( NULL != V_21 -> V_24 ) {
F_8 ( & V_21 -> V_23 , V_12 ) ;
F_13 ( L_1 ) ;
return;
}
if ( F_6 ( & V_21 -> V_26 ) ) {
F_8 ( & V_21 -> V_23 , V_12 ) ;
F_13 ( L_2 ) ;
return;
}
V_21 -> V_24 = F_7 ( V_21 -> V_26 . V_16 ,
struct V_2 , V_27 ) ;
V_21 -> V_24 -> V_28 |= V_29 ;
F_8 ( & V_21 -> V_23 , V_12 ) ;
V_21 -> V_30 -> V_31 ( V_21 -> V_24 -> V_25 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
unsigned long V_32 , V_12 ;
V_21 = V_3 -> V_21 ;
F_13 ( L_3 , V_3 ) ;
if ( ! V_3 -> V_5 . V_9 . V_33
|| ! V_3 -> V_6 . V_9 . V_33 ) {
F_13 ( L_4 ) ;
return;
}
F_5 ( & V_21 -> V_23 , V_32 ) ;
if ( V_3 -> V_28 & V_34 ) {
F_8 ( & V_21 -> V_23 , V_32 ) ;
F_13 ( L_5 ) ;
return;
}
F_5 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 ) ) {
F_8 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_8 ( & V_21 -> V_23 , V_32 ) ;
F_13 ( L_6 ) ;
return;
}
if ( F_6 ( & V_3 -> V_6 . V_14 ) ) {
F_8 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_8 ( & V_21 -> V_23 , V_32 ) ;
F_13 ( L_7 ) ;
return;
}
F_8 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( V_21 -> V_30 -> V_35
&& ( ! V_21 -> V_30 -> V_35 ( V_3 -> V_25 ) ) ) {
F_8 ( & V_21 -> V_23 , V_32 ) ;
F_13 ( L_8 ) ;
return;
}
F_15 ( & V_3 -> V_27 , & V_21 -> V_26 ) ;
V_3 -> V_28 |= V_34 ;
F_8 ( & V_21 -> V_23 , V_32 ) ;
F_12 ( V_21 ) ;
}
void F_16 ( struct V_20 * V_21 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_21 -> V_23 , V_12 ) ;
if ( ! V_21 -> V_24 || V_21 -> V_24 != V_3 ) {
F_8 ( & V_21 -> V_23 , V_12 ) ;
F_13 ( L_9 ) ;
return;
}
F_10 ( & V_21 -> V_24 -> V_27 ) ;
V_21 -> V_24 -> V_28 &= ~ ( V_34 | V_29 ) ;
F_17 ( & V_21 -> V_24 -> V_36 ) ;
V_21 -> V_24 = NULL ;
F_8 ( & V_21 -> V_23 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_21 ) ;
}
int F_18 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_38 * V_39 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_39 -> type ) ;
return F_19 ( V_40 , V_39 ) ;
}
int F_20 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
int V_22 = 0 ;
unsigned int V_43 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
V_22 = F_21 ( V_40 , V_42 ) ;
if ( V_42 -> V_44 == V_45 && ! F_2 ( V_40 -> type ) ) {
if ( F_22 ( V_40 -> type ) ) {
for ( V_43 = 0 ; V_43 < V_42 -> V_46 ; ++ V_43 )
V_42 -> V_47 . V_48 [ V_43 ] . V_47 . V_49
+= V_50 ;
} else {
V_42 -> V_47 . V_51 += V_50 ;
}
}
return V_22 ;
}
int F_23 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
int V_22 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
V_22 = F_24 ( V_40 , V_42 ) ;
if ( ! V_22 )
F_14 ( V_3 ) ;
return V_22 ;
}
int F_25 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , V_42 -> type ) ;
return F_26 ( V_40 , V_42 , V_37 -> V_52 & V_53 ) ;
}
int F_27 ( struct V_37 * V_37 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_40 ;
int V_22 ;
V_40 = F_3 ( V_3 , type ) ;
V_22 = F_28 ( V_40 , type ) ;
if ( ! V_22 )
F_14 ( V_3 ) ;
return V_22 ;
}
int F_29 ( struct V_37 * V_37 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_40 ;
V_40 = F_3 ( V_3 , type ) ;
return F_30 ( V_40 , type ) ;
}
unsigned int F_31 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_7 * V_56 , * V_57 ;
struct V_58 * V_59 = NULL , * V_60 = NULL ;
unsigned int V_61 = 0 ;
unsigned long V_12 ;
V_56 = F_32 ( V_3 ) ;
V_57 = F_33 ( V_3 ) ;
if ( ( ! V_56 -> V_33 || F_6 ( & V_56 -> V_62 ) )
&& ( ! V_57 -> V_33 || F_6 ( & V_57 -> V_62 ) ) ) {
V_61 = V_63 ;
goto V_15;
}
if ( V_3 -> V_21 -> V_30 -> V_64 )
V_3 -> V_21 -> V_30 -> V_64 ( V_3 -> V_25 ) ;
F_34 ( V_37 , & V_56 -> V_65 , V_55 ) ;
F_34 ( V_37 , & V_57 -> V_65 , V_55 ) ;
if ( V_3 -> V_21 -> V_30 -> V_66 )
V_3 -> V_21 -> V_30 -> V_66 ( V_3 -> V_25 ) ;
F_5 ( & V_56 -> V_67 , V_12 ) ;
if ( ! F_6 ( & V_56 -> V_68 ) )
V_59 = F_35 ( & V_56 -> V_68 , struct V_58 ,
V_69 ) ;
if ( V_59 && ( V_59 -> V_70 == V_71
|| V_59 -> V_70 == V_72 ) )
V_61 |= V_73 | V_74 ;
F_8 ( & V_56 -> V_67 , V_12 ) ;
F_5 ( & V_57 -> V_67 , V_12 ) ;
if ( ! F_6 ( & V_57 -> V_68 ) )
V_60 = F_35 ( & V_57 -> V_68 , struct V_58 ,
V_69 ) ;
if ( V_60 && ( V_60 -> V_70 == V_71
|| V_60 -> V_70 == V_72 ) )
V_61 |= V_75 | V_76 ;
F_8 ( & V_57 -> V_67 , V_12 ) ;
V_15:
return V_61 ;
}
int F_36 ( struct V_37 * V_37 , struct V_2 * V_3 ,
struct V_77 * V_78 )
{
unsigned long V_51 = V_78 -> V_79 << V_80 ;
struct V_7 * V_40 ;
if ( V_51 < V_50 ) {
V_40 = F_32 ( V_3 ) ;
} else {
V_40 = F_33 ( V_3 ) ;
V_78 -> V_79 -= ( V_50 >> V_80 ) ;
}
return F_37 ( V_40 , V_78 ) ;
}
struct V_20 * F_38 ( struct V_81 * V_30 )
{
struct V_20 * V_21 ;
if ( ! V_30 )
return F_39 ( - V_82 ) ;
F_40 ( ! V_30 -> V_31 ) ;
F_40 ( ! V_30 -> V_83 ) ;
V_21 = F_41 ( sizeof *V_21 , V_84 ) ;
if ( ! V_21 )
return F_39 ( - V_85 ) ;
V_21 -> V_24 = NULL ;
V_21 -> V_30 = V_30 ;
F_42 ( & V_21 -> V_26 ) ;
F_43 ( & V_21 -> V_23 ) ;
return V_21 ;
}
void F_44 ( struct V_20 * V_21 )
{
F_45 ( V_21 ) ;
}
struct V_2 * F_46 ( struct V_20 * V_21 ,
void * V_86 ,
int (* F_47)( void * V_25 , struct V_7 * V_87 , struct V_7 * V_88 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_22 ;
V_3 = F_41 ( sizeof *V_3 , V_84 ) ;
if ( ! V_3 )
return F_39 ( - V_85 ) ;
V_3 -> V_25 = V_86 ;
V_3 -> V_21 = V_21 ;
F_48 ( & V_3 -> V_36 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_42 ( & V_5 -> V_14 ) ;
F_42 ( & V_6 -> V_14 ) ;
F_43 ( & V_5 -> V_13 ) ;
F_43 ( & V_6 -> V_13 ) ;
F_42 ( & V_3 -> V_27 ) ;
V_22 = F_47 ( V_86 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_22 )
goto V_89;
return V_3 ;
V_89:
F_45 ( V_3 ) ;
return F_39 ( V_22 ) ;
}
void F_49 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
unsigned long V_12 ;
V_21 = V_3 -> V_21 ;
F_5 ( & V_21 -> V_23 , V_12 ) ;
if ( V_3 -> V_28 & V_29 ) {
F_8 ( & V_21 -> V_23 , V_12 ) ;
V_21 -> V_30 -> V_83 ( V_3 -> V_25 ) ;
F_13 ( L_10 , V_3 ) ;
F_50 ( V_3 -> V_36 , ! ( V_3 -> V_28 & V_29 ) ) ;
} else if ( V_3 -> V_28 & V_34 ) {
F_10 ( & V_3 -> V_27 ) ;
V_3 -> V_28 &= ~ ( V_34 | V_29 ) ;
F_8 ( & V_21 -> V_23 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_8 ( & V_21 -> V_23 , V_12 ) ;
}
F_51 ( & V_3 -> V_6 . V_9 ) ;
F_51 ( & V_3 -> V_5 . V_9 ) ;
F_45 ( V_3 ) ;
}
void F_52 ( struct V_2 * V_3 , struct V_58 * V_18 )
{
struct V_10 * V_11 = F_53 ( V_18 , struct V_10 , V_18 ) ;
struct V_1 * V_8 ;
unsigned long V_12 ;
V_8 = F_1 ( V_3 , V_18 -> V_7 -> type ) ;
if ( ! V_8 )
return;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_15 ( & V_11 -> V_17 , & V_8 -> V_14 ) ;
V_8 -> V_19 ++ ;
F_8 ( & V_8 -> V_13 , V_12 ) ;
}
