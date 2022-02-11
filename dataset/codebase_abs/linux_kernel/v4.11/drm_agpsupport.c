int F_1 ( struct V_1 * V_2 , struct F_1 * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
V_5 = & V_2 -> V_6 -> V_9 ;
V_3 -> V_10 = V_5 -> V_11 . V_12 ;
V_3 -> V_13 = V_5 -> V_11 . V_14 ;
V_3 -> V_15 = V_5 -> V_15 ;
V_3 -> V_16 = V_5 -> V_17 ;
V_3 -> V_18 = V_5 -> V_19 * 1024 * 1024 ;
V_3 -> V_20 = V_5 -> V_21 << V_22 ;
V_3 -> V_23 = V_5 -> V_24 << V_22 ;
V_3 -> V_25 = V_5 -> V_26 -> V_27 ;
V_3 -> V_28 = V_5 -> V_26 -> V_26 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct F_1 * V_3 = V_29 ;
int V_32 ;
V_32 = F_1 ( V_2 , V_3 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return - V_33 ;
if ( V_2 -> V_6 -> V_7 )
return - V_34 ;
if ( ! ( V_2 -> V_6 -> V_35 = F_4 ( V_2 -> V_36 ) ) )
return - V_33 ;
V_2 -> V_6 -> V_7 = 1 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
return F_3 ( (struct V_1 * ) V_31 -> V_14 -> V_2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
F_7 ( V_2 -> V_6 -> V_35 ) ;
V_2 -> V_6 -> V_7 = 0 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
return F_6 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_37 V_15 )
{
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
V_2 -> V_6 -> V_15 = V_15 . V_15 ;
F_10 ( V_2 -> V_6 -> V_35 , V_15 . V_15 ) ;
V_2 -> V_6 -> V_38 = 1 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_37 * V_15 = V_29 ;
return F_9 ( V_2 , * V_15 ) ;
}
int F_12 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
unsigned long V_45 ;
T_1 type ;
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
if ( ! ( V_42 = F_13 ( sizeof( * V_42 ) , V_46 ) ) )
return - V_47 ;
V_45 = ( V_40 -> V_48 + V_49 - 1 ) / V_49 ;
type = ( T_1 ) V_40 -> type ;
if ( ! ( V_44 = F_14 ( V_2 -> V_6 -> V_35 , V_45 , type ) ) ) {
F_15 ( V_42 ) ;
return - V_47 ;
}
V_42 -> V_50 = ( unsigned long ) V_44 -> V_51 + 1 ;
V_42 -> V_44 = V_44 ;
V_42 -> V_52 = 0 ;
V_42 -> V_45 = V_45 ;
F_16 ( & V_42 -> V_53 , & V_2 -> V_6 -> V_44 ) ;
V_40 -> V_50 = V_42 -> V_50 ;
V_40 -> V_54 = V_44 -> V_54 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_39 * V_40 = V_29 ;
return F_12 ( V_2 , V_40 ) ;
}
static struct V_41 * F_18 ( struct V_1 * V_2 ,
unsigned long V_50 )
{
struct V_41 * V_42 ;
F_19 (entry, &dev->agp->memory, head) {
if ( V_42 -> V_50 == V_50 )
return V_42 ;
}
return NULL ;
}
int F_20 ( struct V_1 * V_2 , struct V_55 * V_40 )
{
struct V_41 * V_42 ;
int V_56 ;
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
if ( ! ( V_42 = F_18 ( V_2 , V_40 -> V_50 ) ) )
return - V_8 ;
if ( ! V_42 -> V_52 )
return - V_8 ;
V_56 = F_21 ( V_42 -> V_44 ) ;
if ( V_56 == 0 )
V_42 -> V_52 = 0 ;
return V_56 ;
}
int F_22 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_55 * V_40 = V_29 ;
return F_20 ( V_2 , V_40 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_55 * V_40 )
{
struct V_41 * V_42 ;
int V_57 ;
int V_58 ;
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
if ( ! ( V_42 = F_18 ( V_2 , V_40 -> V_50 ) ) )
return - V_8 ;
if ( V_42 -> V_52 )
return - V_8 ;
V_58 = ( V_40 -> V_59 + V_49 - 1 ) / V_49 ;
if ( ( V_57 = F_24 ( V_42 -> V_44 , V_58 ) ) )
return V_57 ;
V_42 -> V_52 = V_2 -> V_6 -> V_60 + ( V_58 << V_22 ) ;
F_25 ( L_1 ,
V_2 -> V_6 -> V_60 , V_42 -> V_52 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_55 * V_40 = V_29 ;
return F_23 ( V_2 , V_40 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_41 * V_42 ;
if ( ! V_2 -> V_6 || ! V_2 -> V_6 -> V_7 )
return - V_8 ;
if ( ! ( V_42 = F_18 ( V_2 , V_40 -> V_50 ) ) )
return - V_8 ;
if ( V_42 -> V_52 )
F_21 ( V_42 -> V_44 ) ;
F_28 ( & V_42 -> V_53 ) ;
F_29 ( V_42 -> V_44 , V_42 -> V_45 ) ;
F_15 ( V_42 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * V_29 ,
struct V_30 * V_31 )
{
struct V_39 * V_40 = V_29 ;
return F_27 ( V_2 , V_40 ) ;
}
struct V_61 * F_31 ( struct V_1 * V_2 )
{
struct V_61 * V_53 = NULL ;
if ( ! ( V_53 = F_13 ( sizeof( * V_53 ) , V_46 ) ) )
return NULL ;
V_53 -> V_35 = F_32 ( V_2 -> V_36 ) ;
if ( ! V_53 -> V_35 ) {
if ( ! ( V_53 -> V_35 = F_4 ( V_2 -> V_36 ) ) ) {
F_15 ( V_53 ) ;
return NULL ;
}
F_33 ( V_53 -> V_35 , & V_53 -> V_9 ) ;
F_7 ( V_53 -> V_35 ) ;
} else {
F_33 ( V_53 -> V_35 , & V_53 -> V_9 ) ;
}
if ( V_53 -> V_9 . V_62 == V_63 ) {
F_15 ( V_53 ) ;
return NULL ;
}
F_34 ( & V_53 -> V_44 ) ;
V_53 -> V_64 = V_53 -> V_9 . V_64 ;
V_53 -> V_65 = V_53 -> V_9 . V_65 ;
V_53 -> V_60 = V_53 -> V_9 . V_17 ;
return V_53 ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_41 * V_42 , * V_66 ;
if ( ! V_2 -> V_6 )
return;
if ( ! F_36 ( V_2 , V_67 ) )
return;
F_37 (entry, tempe, &dev->agp->memory, head) {
if ( V_42 -> V_52 )
F_21 ( V_42 -> V_44 ) ;
F_29 ( V_42 -> V_44 , V_42 -> V_45 ) ;
F_15 ( V_42 ) ;
}
F_34 ( & V_2 -> V_6 -> V_44 ) ;
if ( V_2 -> V_6 -> V_7 )
F_6 ( V_2 ) ;
V_2 -> V_6 -> V_7 = 0 ;
V_2 -> V_6 -> V_38 = 0 ;
}
struct V_43 *
F_38 ( struct V_1 * V_2 ,
struct V_58 * * V_45 ,
unsigned long V_68 ,
T_2 V_69 ,
T_1 type )
{
struct V_43 * V_70 ;
int V_56 , V_71 ;
F_25 ( L_2 ) ;
V_70 = F_14 ( V_2 -> V_6 -> V_35 , V_68 ,
type ) ;
if ( V_70 == NULL ) {
F_39 ( L_3 ,
V_68 ) ;
return NULL ;
}
for ( V_71 = 0 ; V_71 < V_68 ; V_71 ++ )
V_70 -> V_45 [ V_71 ] = V_45 [ V_71 ] ;
V_70 -> V_72 = V_68 ;
V_70 -> V_73 = true ;
V_56 = F_40 ( V_70 , V_69 / V_49 ) ;
if ( V_56 != 0 ) {
F_39 ( L_4 , V_56 ) ;
F_41 ( V_70 ) ;
return NULL ;
}
return V_70 ;
}
