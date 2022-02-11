int F_1 ( struct V_1 * V_2 , struct F_1 * V_3 )
{
T_1 * V_4 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
V_4 = & V_2 -> V_5 -> V_8 ;
V_3 -> V_9 = V_4 -> V_10 . V_11 ;
V_3 -> V_12 = V_4 -> V_10 . V_13 ;
V_3 -> V_14 = V_4 -> V_14 ;
V_3 -> V_15 = V_4 -> V_16 ;
V_3 -> V_17 = V_4 -> V_18 * 1024 * 1024 ;
V_3 -> V_19 = V_4 -> V_20 << V_21 ;
V_3 -> V_22 = V_4 -> V_23 << V_21 ;
V_3 -> V_24 = V_4 -> V_25 -> V_26 ;
V_3 -> V_27 = V_4 -> V_25 -> V_25 ;
return 0 ;
}
int F_2 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct F_1 * V_3 = V_28 ;
int V_31 ;
V_31 = F_1 ( V_2 , V_3 ) ;
if ( V_31 )
return V_31 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return - V_32 ;
if ( V_2 -> V_5 -> V_6 )
return - V_33 ;
if ( ! ( V_2 -> V_5 -> V_34 = F_4 ( V_2 -> V_35 ) ) )
return - V_32 ;
V_2 -> V_5 -> V_6 = 1 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
return F_3 ( (struct V_1 * ) V_30 -> V_13 -> V_2 ) ;
}
int F_6 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
F_7 ( V_2 -> V_5 -> V_34 ) ;
V_2 -> V_5 -> V_6 = 0 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
return F_6 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_36 V_14 )
{
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
V_2 -> V_5 -> V_14 = V_14 . V_14 ;
F_10 ( V_2 -> V_5 -> V_34 , V_14 . V_14 ) ;
V_2 -> V_5 -> V_37 = 1 ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_36 * V_14 = V_28 ;
return F_9 ( V_2 , * V_14 ) ;
}
int F_12 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
T_2 * V_42 ;
unsigned long V_43 ;
T_3 type ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
if ( ! ( V_41 = F_13 ( sizeof( * V_41 ) , V_44 ) ) )
return - V_45 ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
V_43 = ( V_39 -> V_46 + V_47 - 1 ) / V_47 ;
type = ( T_3 ) V_39 -> type ;
if ( ! ( V_42 = F_14 ( V_2 -> V_5 -> V_34 , V_43 , type ) ) ) {
F_15 ( V_41 ) ;
return - V_45 ;
}
V_41 -> V_48 = ( unsigned long ) V_42 -> V_49 + 1 ;
V_41 -> V_42 = V_42 ;
V_41 -> V_50 = 0 ;
V_41 -> V_43 = V_43 ;
F_16 ( & V_41 -> V_51 , & V_2 -> V_5 -> V_42 ) ;
V_39 -> V_48 = V_41 -> V_48 ;
V_39 -> V_52 = V_42 -> V_52 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_38 * V_39 = V_28 ;
return F_12 ( V_2 , V_39 ) ;
}
static struct V_40 * F_18 ( struct V_1 * V_2 ,
unsigned long V_48 )
{
struct V_40 * V_41 ;
F_19 (entry, &dev->agp->memory, head) {
if ( V_41 -> V_48 == V_48 )
return V_41 ;
}
return NULL ;
}
int F_20 ( struct V_1 * V_2 , struct V_53 * V_39 )
{
struct V_40 * V_41 ;
int V_54 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
if ( ! ( V_41 = F_18 ( V_2 , V_39 -> V_48 ) ) )
return - V_7 ;
if ( ! V_41 -> V_50 )
return - V_7 ;
V_54 = F_21 ( V_41 -> V_42 ) ;
if ( V_54 == 0 )
V_41 -> V_50 = 0 ;
return V_54 ;
}
int F_22 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_53 * V_39 = V_28 ;
return F_20 ( V_2 , V_39 ) ;
}
int F_23 ( struct V_1 * V_2 , struct V_53 * V_39 )
{
struct V_40 * V_41 ;
int V_55 ;
int V_56 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
if ( ! ( V_41 = F_18 ( V_2 , V_39 -> V_48 ) ) )
return - V_7 ;
if ( V_41 -> V_50 )
return - V_7 ;
V_56 = ( V_39 -> V_57 + V_47 - 1 ) / V_47 ;
if ( ( V_55 = F_24 ( V_41 -> V_42 , V_56 ) ) )
return V_55 ;
V_41 -> V_50 = V_2 -> V_5 -> V_58 + ( V_56 << V_21 ) ;
F_25 ( L_1 ,
V_2 -> V_5 -> V_58 , V_41 -> V_50 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_53 * V_39 = V_28 ;
return F_23 ( V_2 , V_39 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_40 * V_41 ;
if ( ! V_2 -> V_5 || ! V_2 -> V_5 -> V_6 )
return - V_7 ;
if ( ! ( V_41 = F_18 ( V_2 , V_39 -> V_48 ) ) )
return - V_7 ;
if ( V_41 -> V_50 )
F_21 ( V_41 -> V_42 ) ;
F_28 ( & V_41 -> V_51 ) ;
F_29 ( V_41 -> V_42 , V_41 -> V_43 ) ;
F_15 ( V_41 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 , void * V_28 ,
struct V_29 * V_30 )
{
struct V_38 * V_39 = V_28 ;
return F_27 ( V_2 , V_39 ) ;
}
struct V_59 * F_31 ( struct V_1 * V_2 )
{
struct V_59 * V_51 = NULL ;
if ( ! ( V_51 = F_13 ( sizeof( * V_51 ) , V_44 ) ) )
return NULL ;
memset ( ( void * ) V_51 , 0 , sizeof( * V_51 ) ) ;
V_51 -> V_34 = F_32 ( V_2 -> V_35 ) ;
if ( ! V_51 -> V_34 ) {
if ( ! ( V_51 -> V_34 = F_4 ( V_2 -> V_35 ) ) ) {
F_15 ( V_51 ) ;
return NULL ;
}
F_33 ( V_51 -> V_34 , & V_51 -> V_8 ) ;
F_7 ( V_51 -> V_34 ) ;
} else {
F_33 ( V_51 -> V_34 , & V_51 -> V_8 ) ;
}
if ( V_51 -> V_8 . V_60 == V_61 ) {
F_15 ( V_51 ) ;
return NULL ;
}
F_34 ( & V_51 -> V_42 ) ;
V_51 -> V_62 = V_51 -> V_8 . V_62 ;
V_51 -> V_63 = V_51 -> V_8 . V_63 ;
V_51 -> V_58 = V_51 -> V_8 . V_16 ;
return V_51 ;
}
T_2 *
F_35 ( struct V_1 * V_2 ,
struct V_56 * * V_43 ,
unsigned long V_64 ,
T_4 V_65 ,
T_3 type )
{
T_2 * V_66 ;
int V_54 , V_67 ;
F_25 ( L_2 ) ;
V_66 = F_14 ( V_2 -> V_5 -> V_34 , V_64 ,
type ) ;
if ( V_66 == NULL ) {
F_36 ( L_3 ,
V_64 ) ;
return NULL ;
}
for ( V_67 = 0 ; V_67 < V_64 ; V_67 ++ )
V_66 -> V_43 [ V_67 ] = V_43 [ V_67 ] ;
V_66 -> V_68 = V_64 ;
V_66 -> V_69 = true ;
V_54 = F_37 ( V_66 , V_65 / V_47 ) ;
if ( V_54 != 0 ) {
F_36 ( L_4 , V_54 ) ;
F_38 ( V_66 ) ;
return NULL ;
}
return V_66 ;
}
