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
V_11 = F_8 ( & V_8 -> V_14 , struct V_10 , V_15 ) ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_16 ;
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
V_11 = F_8 ( & V_8 -> V_14 , struct V_10 , V_15 ) ;
F_10 ( & V_11 -> V_15 ) ;
V_8 -> V_17 -- ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
return & V_11 -> V_16 ;
}
void * F_11 ( struct V_18 * V_19 )
{
unsigned long V_12 ;
void * V_20 = NULL ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_19 -> V_22 )
V_20 = V_19 -> V_22 -> V_23 ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
return V_20 ;
}
static void F_12 ( struct V_18 * V_19 )
{
unsigned long V_12 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( NULL != V_19 -> V_22 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_1 ) ;
return;
}
if ( F_6 ( & V_19 -> V_24 ) ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_2 ) ;
return;
}
V_19 -> V_22 = F_8 ( & V_19 -> V_24 ,
struct V_2 , V_25 ) ;
V_19 -> V_22 -> V_26 |= V_27 ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_29 ( V_19 -> V_22 -> V_23 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_30 , V_12 ;
V_19 = V_3 -> V_19 ;
F_13 ( L_3 , V_3 ) ;
if ( ! V_3 -> V_5 . V_9 . V_31
|| ! V_3 -> V_6 . V_9 . V_31 ) {
F_13 ( L_4 ) ;
return;
}
F_5 ( & V_19 -> V_21 , V_30 ) ;
if ( V_3 -> V_26 & V_32 ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_5 ) ;
return;
}
F_5 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( F_6 ( & V_3 -> V_5 . V_14 ) ) {
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_6 ) ;
return;
}
if ( F_6 ( & V_3 -> V_6 . V_14 ) ) {
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_7 ) ;
return;
}
F_7 ( & V_3 -> V_5 . V_13 , V_12 ) ;
if ( V_19 -> V_28 -> V_33
&& ( ! V_19 -> V_28 -> V_33 ( V_3 -> V_23 ) ) ) {
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_13 ( L_8 ) ;
return;
}
F_15 ( & V_3 -> V_25 , & V_19 -> V_24 ) ;
V_3 -> V_26 |= V_32 ;
F_7 ( & V_19 -> V_21 , V_30 ) ;
F_12 ( V_19 ) ;
}
void F_16 ( struct V_18 * V_19 ,
struct V_2 * V_3 )
{
unsigned long V_12 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( ! V_19 -> V_22 || V_19 -> V_22 != V_3 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_9 ) ;
return;
}
F_10 ( & V_19 -> V_22 -> V_25 ) ;
V_19 -> V_22 -> V_26 &= ~ ( V_32 | V_27 ) ;
F_17 ( & V_19 -> V_22 -> V_34 ) ;
V_19 -> V_22 = NULL ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_14 ( V_3 ) ;
F_12 ( V_19 ) ;
}
int F_18 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_36 * V_37 )
{
struct V_7 * V_38 ;
V_38 = F_3 ( V_3 , V_37 -> type ) ;
return F_19 ( V_38 , V_37 ) ;
}
int F_20 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_7 * V_38 ;
int V_20 = 0 ;
unsigned int V_41 ;
V_38 = F_3 ( V_3 , V_40 -> type ) ;
V_20 = F_21 ( V_38 , V_40 ) ;
if ( V_40 -> V_42 == V_43 && ! F_2 ( V_38 -> type ) ) {
if ( F_22 ( V_38 -> type ) ) {
for ( V_41 = 0 ; V_41 < V_40 -> V_44 ; ++ V_41 )
V_40 -> V_45 . V_46 [ V_41 ] . V_45 . V_47
+= V_48 ;
} else {
V_40 -> V_45 . V_49 += V_48 ;
}
}
return V_20 ;
}
int F_23 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_7 * V_38 ;
int V_20 ;
V_38 = F_3 ( V_3 , V_40 -> type ) ;
V_20 = F_24 ( V_38 , V_40 ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_25 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_39 * V_40 )
{
struct V_7 * V_38 ;
V_38 = F_3 ( V_3 , V_40 -> type ) ;
return F_26 ( V_38 , V_40 , V_35 -> V_50 & V_51 ) ;
}
int F_27 ( struct V_35 * V_35 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_38 ;
int V_20 ;
V_38 = F_3 ( V_3 , type ) ;
V_20 = F_28 ( V_38 , type ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_29 ( struct V_35 * V_35 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_38 ;
V_38 = F_3 ( V_3 , type ) ;
return F_30 ( V_38 , type ) ;
}
unsigned int F_31 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_52 * V_53 )
{
struct V_54 * V_55 = F_32 ( V_35 ) ;
unsigned long V_56 = F_33 ( V_53 ) ;
struct V_7 * V_57 , * V_58 ;
struct V_59 * V_60 = NULL , * V_61 = NULL ;
unsigned int V_62 = 0 ;
unsigned long V_12 ;
if ( F_34 ( V_63 , & V_55 -> V_12 ) ) {
struct V_64 * V_65 = V_35 -> V_66 ;
if ( F_35 ( V_65 ) )
V_62 = V_67 ;
else if ( V_56 & V_67 )
F_36 ( V_35 , & V_65 -> V_53 , V_53 ) ;
if ( ! ( V_56 & ( V_68 | V_69 | V_70 | V_71 ) ) )
return V_62 ;
}
V_57 = F_37 ( V_3 ) ;
V_58 = F_38 ( V_3 ) ;
if ( ( ! V_57 -> V_31 || F_6 ( & V_57 -> V_72 ) )
&& ( ! V_58 -> V_31 || F_6 ( & V_58 -> V_72 ) ) ) {
V_62 |= V_73 ;
goto V_74;
}
if ( V_3 -> V_19 -> V_28 -> V_75 )
V_3 -> V_19 -> V_28 -> V_75 ( V_3 -> V_23 ) ;
F_36 ( V_35 , & V_57 -> V_76 , V_53 ) ;
F_36 ( V_35 , & V_58 -> V_76 , V_53 ) ;
if ( V_3 -> V_19 -> V_28 -> V_77 )
V_3 -> V_19 -> V_28 -> V_77 ( V_3 -> V_23 ) ;
F_5 ( & V_57 -> V_78 , V_12 ) ;
if ( ! F_6 ( & V_57 -> V_79 ) )
V_60 = F_8 ( & V_57 -> V_79 , struct V_59 ,
V_80 ) ;
if ( V_60 && ( V_60 -> V_81 == V_82
|| V_60 -> V_81 == V_83 ) )
V_62 |= V_68 | V_69 ;
F_7 ( & V_57 -> V_78 , V_12 ) ;
F_5 ( & V_58 -> V_78 , V_12 ) ;
if ( ! F_6 ( & V_58 -> V_79 ) )
V_61 = F_8 ( & V_58 -> V_79 , struct V_59 ,
V_80 ) ;
if ( V_61 && ( V_61 -> V_81 == V_82
|| V_61 -> V_81 == V_83 ) )
V_62 |= V_70 | V_71 ;
F_7 ( & V_58 -> V_78 , V_12 ) ;
V_74:
return V_62 ;
}
int F_39 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_84 * V_85 )
{
unsigned long V_49 = V_85 -> V_86 << V_87 ;
struct V_7 * V_38 ;
if ( V_49 < V_48 ) {
V_38 = F_37 ( V_3 ) ;
} else {
V_38 = F_38 ( V_3 ) ;
V_85 -> V_86 -= ( V_48 >> V_87 ) ;
}
return F_40 ( V_38 , V_85 ) ;
}
struct V_18 * F_41 ( struct V_88 * V_28 )
{
struct V_18 * V_19 ;
if ( ! V_28 )
return F_42 ( - V_89 ) ;
F_43 ( ! V_28 -> V_29 ) ;
F_43 ( ! V_28 -> V_90 ) ;
V_19 = F_44 ( sizeof *V_19 , V_91 ) ;
if ( ! V_19 )
return F_42 ( - V_92 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_28 = V_28 ;
F_45 ( & V_19 -> V_24 ) ;
F_46 ( & V_19 -> V_21 ) ;
return V_19 ;
}
void F_47 ( struct V_18 * V_19 )
{
F_48 ( V_19 ) ;
}
struct V_2 * F_49 ( struct V_18 * V_19 ,
void * V_93 ,
int (* F_50)( void * V_23 , struct V_7 * V_94 , struct V_7 * V_95 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_20 ;
V_3 = F_44 ( sizeof *V_3 , V_91 ) ;
if ( ! V_3 )
return F_42 ( - V_92 ) ;
V_3 -> V_23 = V_93 ;
V_3 -> V_19 = V_19 ;
F_51 ( & V_3 -> V_34 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_45 ( & V_5 -> V_14 ) ;
F_45 ( & V_6 -> V_14 ) ;
F_46 ( & V_5 -> V_13 ) ;
F_46 ( & V_6 -> V_13 ) ;
F_45 ( & V_3 -> V_25 ) ;
V_20 = F_50 ( V_93 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_20 )
goto V_96;
return V_3 ;
V_96:
F_48 ( V_3 ) ;
return F_42 ( V_20 ) ;
}
void F_52 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_90 ( V_3 -> V_23 ) ;
F_13 ( L_10 , V_3 ) ;
F_53 ( V_3 -> V_34 , ! ( V_3 -> V_26 & V_27 ) ) ;
} else if ( V_3 -> V_26 & V_32 ) {
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 &= ~ ( V_32 | V_27 ) ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_19 -> V_21 , V_12 ) ;
}
F_54 ( & V_3 -> V_6 . V_9 ) ;
F_54 ( & V_3 -> V_5 . V_9 ) ;
F_48 ( V_3 ) ;
}
void F_55 ( struct V_2 * V_3 , struct V_59 * V_16 )
{
struct V_10 * V_11 = F_56 ( V_16 , struct V_10 , V_16 ) ;
struct V_1 * V_8 ;
unsigned long V_12 ;
V_8 = F_1 ( V_3 , V_16 -> V_7 -> type ) ;
if ( ! V_8 )
return;
F_5 ( & V_8 -> V_13 , V_12 ) ;
F_15 ( & V_11 -> V_15 , & V_8 -> V_14 ) ;
V_8 -> V_17 ++ ;
F_7 ( & V_8 -> V_13 , V_12 ) ;
}
