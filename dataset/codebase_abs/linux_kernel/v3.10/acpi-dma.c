static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
T_1 V_13 = 0 , V_14 = 0 ;
T_2 V_15 ;
int V_16 ;
if ( V_2 -> V_17 != sizeof( struct V_7 ) )
return - V_18 ;
F_2 ( & V_10 ) ;
V_16 = F_3 ( V_4 , & V_10 , NULL , NULL ) ;
if ( V_16 <= 0 )
return 0 ;
F_4 (rentry, &resource_list, node) {
if ( F_5 ( & V_12 -> V_19 ) == V_20 )
V_13 = V_12 -> V_19 . V_21 ;
else if ( F_5 ( & V_12 -> V_19 ) == V_22 )
V_14 = V_12 -> V_19 . V_21 ;
}
F_6 ( & V_10 ) ;
if ( V_13 == 0 && V_14 == 0 )
return 0 ;
V_8 = ( const struct V_7 * ) & V_2 [ 1 ] ;
if ( V_8 -> V_23 != V_13 || V_8 -> V_24 != V_14 )
return 0 ;
V_15 = F_7 ( V_2 -> V_15 ) ;
F_8 ( & V_4 -> V_25 , L_1 ,
( char * ) & V_15 , V_2 -> V_26 , V_2 -> V_27 ) ;
if ( V_8 -> V_28 == 0 && V_8 -> V_29 == 0 )
return 0 ;
V_6 -> V_28 = V_8 -> V_28 ;
V_6 -> V_30 = V_8 -> V_28 +
V_8 -> V_29 - 1 ;
F_8 ( & V_4 -> V_25 , L_2 ,
V_6 -> V_28 , V_6 -> V_30 ) ;
return 1 ;
}
static void F_9 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_31 ;
struct V_32 * V_33 ;
T_3 V_34 ;
int V_16 ;
V_34 = F_10 ( V_35 , 0 ,
(struct V_36 * * ) & V_33 ) ;
if ( F_11 ( V_34 ) ) {
if ( V_34 != V_37 )
F_12 ( & V_4 -> V_25 , L_3 ) ;
return;
}
V_2 = (struct V_1 * ) ( V_33 + 1 ) ;
V_31 = (struct V_1 * ) ( ( void * ) V_33 + V_33 -> V_38 . V_39 ) ;
while ( V_2 < V_31 ) {
V_16 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_16 < 0 ) {
F_12 ( & V_4 -> V_25 ,
L_4 ) ;
return;
}
V_2 = (struct V_1 * ) ( ( void * ) V_2 + V_2 -> V_39 ) ;
}
}
int F_13 ( struct V_40 * V_25 )
{
struct V_5 * V_6 ;
if ( ! V_25 )
return - V_41 ;
F_14 ( & V_42 ) ;
F_4 (adma, &acpi_dma_list, dma_controllers)
if ( V_6 -> V_25 == V_25 ) {
F_15 ( & V_6 -> V_43 ) ;
F_16 ( & V_42 ) ;
F_17 ( V_6 ) ;
return 0 ;
}
F_16 ( & V_42 ) ;
return - V_18 ;
}
static void F_18 ( struct V_40 * V_25 , void * V_19 )
{
F_13 ( V_25 ) ;
}
void F_19 ( struct V_40 * V_25 )
{
F_20 ( F_21 ( V_25 , F_18 , NULL , NULL ) ) ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
V_45 -> V_25 = V_6 -> V_25 ;
if ( V_6 -> V_28 == 0 && V_6 -> V_30 == 0 )
return 0 ;
if ( V_45 -> V_46 < V_6 -> V_28 ||
V_45 -> V_46 > V_6 -> V_30 )
return - 1 ;
V_45 -> V_46 -= V_6 -> V_28 ;
return 1 ;
}
static int F_23 ( struct V_47 * V_19 , void * V_48 )
{
struct V_49 * V_50 = V_48 ;
if ( V_19 -> type == V_51 ) {
struct V_52 * V_53 = & V_19 -> V_48 . V_54 ;
if ( V_50 -> V_55 ++ == V_50 -> V_56 ) {
V_50 -> V_45 . V_57 = V_53 -> V_58 ;
V_50 -> V_45 . V_46 = V_53 -> V_59 ;
}
}
return 1 ;
}
struct V_60 * F_24 ( struct V_40 * V_25 ,
T_4 V_56 )
{
struct V_49 V_50 ;
struct V_44 * V_45 = & V_50 . V_45 ;
struct V_9 V_10 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_60 * V_61 = NULL ;
int V_62 ;
if ( ! V_25 || ! F_25 ( V_25 ) )
return NULL ;
if ( F_26 ( F_25 ( V_25 ) , & V_4 ) )
return NULL ;
memset ( & V_50 , 0 , sizeof( V_50 ) ) ;
V_50 . V_56 = V_56 ;
V_45 -> V_57 = - 1 ;
V_45 -> V_46 = - 1 ;
F_2 ( & V_10 ) ;
F_3 ( V_4 , & V_10 ,
F_23 , & V_50 ) ;
F_6 ( & V_10 ) ;
if ( V_45 -> V_46 < 0 || V_45 -> V_57 < 0 )
return NULL ;
F_14 ( & V_42 ) ;
F_4 (adma, &acpi_dma_list, dma_controllers) {
V_62 = F_22 ( V_6 , V_45 ) ;
if ( V_62 < 0 )
continue;
V_61 = V_6 -> V_63 ( V_45 , V_6 ) ;
if ( V_62 > 0 || V_61 )
break;
}
F_16 ( & V_42 ) ;
return V_61 ;
}
struct V_60 * F_27 ( struct V_40 * V_25 ,
const char * V_64 )
{
T_4 V_56 ;
if ( ! strcmp ( V_64 , L_5 ) )
V_56 = 0 ;
else if ( ! strcmp ( V_64 , L_6 ) )
V_56 = 1 ;
else
return NULL ;
return F_24 ( V_25 , V_56 ) ;
}
struct V_60 * F_28 ( struct V_44 * V_45 ,
struct V_5 * V_6 )
{
struct V_65 * V_66 = V_6 -> V_48 ;
if ( ! V_66 || ! V_66 -> V_67 )
return NULL ;
return F_29 ( V_66 -> V_68 , V_66 -> V_67 , V_45 ) ;
}
