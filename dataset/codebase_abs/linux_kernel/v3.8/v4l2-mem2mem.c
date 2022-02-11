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
struct V_52 * V_53 )
{
struct V_7 * V_38 ;
V_38 = F_3 ( V_3 , V_53 -> type ) ;
return F_28 ( V_38 , V_53 ) ;
}
int F_29 ( struct V_35 * V_35 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_38 ;
int V_20 ;
V_38 = F_3 ( V_3 , type ) ;
V_20 = F_30 ( V_38 , type ) ;
if ( ! V_20 )
F_14 ( V_3 ) ;
return V_20 ;
}
int F_31 ( struct V_35 * V_35 , struct V_2 * V_3 ,
enum V_4 type )
{
struct V_7 * V_38 ;
V_38 = F_3 ( V_3 , type ) ;
return F_32 ( V_38 , type ) ;
}
unsigned int F_33 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 = F_34 ( V_35 ) ;
unsigned long V_58 = F_35 ( V_55 ) ;
struct V_7 * V_59 , * V_60 ;
struct V_61 * V_62 = NULL , * V_63 = NULL ;
unsigned int V_64 = 0 ;
unsigned long V_12 ;
if ( F_36 ( V_65 , & V_57 -> V_12 ) ) {
struct V_66 * V_67 = V_35 -> V_68 ;
if ( F_37 ( V_67 ) )
V_64 = V_69 ;
else if ( V_58 & V_69 )
F_38 ( V_35 , & V_67 -> V_55 , V_55 ) ;
if ( ! ( V_58 & ( V_70 | V_71 | V_72 | V_73 ) ) )
return V_64 ;
}
V_59 = F_39 ( V_3 ) ;
V_60 = F_40 ( V_3 ) ;
if ( ( ! V_59 -> V_31 || F_6 ( & V_59 -> V_74 ) )
&& ( ! V_60 -> V_31 || F_6 ( & V_60 -> V_74 ) ) ) {
V_64 |= V_75 ;
goto V_76;
}
if ( V_3 -> V_19 -> V_28 -> V_77 )
V_3 -> V_19 -> V_28 -> V_77 ( V_3 -> V_23 ) ;
F_38 ( V_35 , & V_59 -> V_78 , V_55 ) ;
F_38 ( V_35 , & V_60 -> V_78 , V_55 ) ;
if ( V_3 -> V_19 -> V_28 -> V_79 )
V_3 -> V_19 -> V_28 -> V_79 ( V_3 -> V_23 ) ;
F_5 ( & V_59 -> V_80 , V_12 ) ;
if ( ! F_6 ( & V_59 -> V_81 ) )
V_62 = F_8 ( & V_59 -> V_81 , struct V_61 ,
V_82 ) ;
if ( V_62 && ( V_62 -> V_83 == V_84
|| V_62 -> V_83 == V_85 ) )
V_64 |= V_70 | V_71 ;
F_7 ( & V_59 -> V_80 , V_12 ) ;
F_5 ( & V_60 -> V_80 , V_12 ) ;
if ( ! F_6 ( & V_60 -> V_81 ) )
V_63 = F_8 ( & V_60 -> V_81 , struct V_61 ,
V_82 ) ;
if ( V_63 && ( V_63 -> V_83 == V_84
|| V_63 -> V_83 == V_85 ) )
V_64 |= V_72 | V_73 ;
F_7 ( & V_60 -> V_80 , V_12 ) ;
V_76:
return V_64 ;
}
int F_41 ( struct V_35 * V_35 , struct V_2 * V_3 ,
struct V_86 * V_87 )
{
unsigned long V_49 = V_87 -> V_88 << V_89 ;
struct V_7 * V_38 ;
if ( V_49 < V_48 ) {
V_38 = F_39 ( V_3 ) ;
} else {
V_38 = F_40 ( V_3 ) ;
V_87 -> V_88 -= ( V_48 >> V_89 ) ;
}
return F_42 ( V_38 , V_87 ) ;
}
struct V_18 * F_43 ( struct V_90 * V_28 )
{
struct V_18 * V_19 ;
if ( ! V_28 || F_44 ( ! V_28 -> V_29 ) ||
F_44 ( ! V_28 -> V_91 ) )
return F_45 ( - V_92 ) ;
V_19 = F_46 ( sizeof *V_19 , V_93 ) ;
if ( ! V_19 )
return F_45 ( - V_94 ) ;
V_19 -> V_22 = NULL ;
V_19 -> V_28 = V_28 ;
F_47 ( & V_19 -> V_24 ) ;
F_48 ( & V_19 -> V_21 ) ;
return V_19 ;
}
void F_49 ( struct V_18 * V_19 )
{
F_50 ( V_19 ) ;
}
struct V_2 * F_51 ( struct V_18 * V_19 ,
void * V_95 ,
int (* F_52)( void * V_23 , struct V_7 * V_96 , struct V_7 * V_97 ) )
{
struct V_2 * V_3 ;
struct V_1 * V_5 , * V_6 ;
int V_20 ;
V_3 = F_46 ( sizeof *V_3 , V_93 ) ;
if ( ! V_3 )
return F_45 ( - V_94 ) ;
V_3 -> V_23 = V_95 ;
V_3 -> V_19 = V_19 ;
F_53 ( & V_3 -> V_34 ) ;
V_5 = & V_3 -> V_5 ;
V_6 = & V_3 -> V_6 ;
F_47 ( & V_5 -> V_14 ) ;
F_47 ( & V_6 -> V_14 ) ;
F_48 ( & V_5 -> V_13 ) ;
F_48 ( & V_6 -> V_13 ) ;
F_47 ( & V_3 -> V_25 ) ;
V_20 = F_52 ( V_95 , & V_5 -> V_9 , & V_6 -> V_9 ) ;
if ( V_20 )
goto V_98;
return V_3 ;
V_98:
F_50 ( V_3 ) ;
return F_45 ( V_20 ) ;
}
void F_54 ( struct V_2 * V_3 )
{
struct V_18 * V_19 ;
unsigned long V_12 ;
V_19 = V_3 -> V_19 ;
F_5 ( & V_19 -> V_21 , V_12 ) ;
if ( V_3 -> V_26 & V_27 ) {
F_7 ( & V_19 -> V_21 , V_12 ) ;
V_19 -> V_28 -> V_91 ( V_3 -> V_23 ) ;
F_13 ( L_10 , V_3 ) ;
F_55 ( V_3 -> V_34 , ! ( V_3 -> V_26 & V_27 ) ) ;
} else if ( V_3 -> V_26 & V_32 ) {
F_10 ( & V_3 -> V_25 ) ;
V_3 -> V_26 &= ~ ( V_32 | V_27 ) ;
F_7 ( & V_19 -> V_21 , V_12 ) ;
F_13 ( L_11 ,
V_3 ) ;
} else {
F_7 ( & V_19 -> V_21 , V_12 ) ;
}
F_56 ( & V_3 -> V_6 . V_9 ) ;
F_56 ( & V_3 -> V_5 . V_9 ) ;
F_50 ( V_3 ) ;
}
void F_57 ( struct V_2 * V_3 , struct V_61 * V_16 )
{
struct V_10 * V_11 = F_58 ( V_16 , struct V_10 , V_16 ) ;
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
