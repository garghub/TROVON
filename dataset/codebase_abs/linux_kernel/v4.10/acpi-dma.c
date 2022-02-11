static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
const struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
T_1 V_13 = 0 , V_14 = 0 ;
int V_15 ;
if ( V_2 -> V_16 != sizeof( struct V_7 ) )
return - V_17 ;
F_2 ( & V_10 ) ;
V_15 = F_3 ( V_4 , & V_10 , NULL , NULL ) ;
if ( V_15 <= 0 )
return 0 ;
F_4 (rentry, &resource_list, node) {
if ( F_5 ( V_12 -> V_18 ) == V_19 )
V_13 = V_12 -> V_18 -> V_20 ;
else if ( F_5 ( V_12 -> V_18 ) == V_21 )
V_14 = V_12 -> V_18 -> V_20 ;
}
F_6 ( & V_10 ) ;
if ( V_13 == 0 && V_14 == 0 )
return 0 ;
V_8 = ( const struct V_7 * ) & V_2 [ 1 ] ;
if ( V_8 -> V_22 != F_7 ( V_13 ) ||
V_8 -> V_23 != F_8 ( V_13 ) ||
V_8 -> V_24 != V_14 )
return 0 ;
F_9 ( & V_4 -> V_25 , L_1 ,
( char * ) & V_2 -> V_26 , V_2 -> V_27 , V_2 -> V_28 ) ;
if ( V_8 -> V_29 == 0 && V_8 -> V_30 == 0 )
return 0 ;
V_6 -> V_29 = V_8 -> V_29 ;
V_6 -> V_31 = V_8 -> V_29 +
V_8 -> V_30 - 1 ;
F_9 ( & V_4 -> V_25 , L_2 ,
V_6 -> V_29 , V_6 -> V_31 ) ;
return 1 ;
}
static void F_10 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_2 , * V_32 ;
struct V_33 * V_34 ;
T_2 V_35 ;
int V_15 ;
V_35 = F_11 ( V_36 , 0 ,
(struct V_37 * * ) & V_34 ) ;
if ( F_12 ( V_35 ) ) {
if ( V_35 != V_38 )
F_13 ( & V_4 -> V_25 , L_3 ) ;
return;
}
V_2 = (struct V_1 * ) ( V_34 + 1 ) ;
V_32 = (struct V_1 * ) ( ( void * ) V_34 + V_34 -> V_39 . V_40 ) ;
while ( V_2 < V_32 ) {
V_15 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( V_15 < 0 ) {
F_13 ( & V_4 -> V_25 ,
L_4 ) ;
return;
}
V_2 = (struct V_1 * ) ( ( void * ) V_2 + V_2 -> V_40 ) ;
}
}
int F_14 ( struct V_41 * V_25 )
{
struct V_5 * V_6 ;
if ( ! V_25 )
return - V_42 ;
F_15 ( & V_43 ) ;
F_4 (adma, &acpi_dma_list, dma_controllers)
if ( V_6 -> V_25 == V_25 ) {
F_16 ( & V_6 -> V_44 ) ;
F_17 ( & V_43 ) ;
F_18 ( V_6 ) ;
return 0 ;
}
F_17 ( & V_43 ) ;
return - V_17 ;
}
static void F_19 ( struct V_41 * V_25 , void * V_18 )
{
F_14 ( V_25 ) ;
}
void F_20 ( struct V_41 * V_25 )
{
F_21 ( F_22 ( V_25 , F_19 , NULL , NULL ) ) ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
V_46 -> V_25 = V_6 -> V_25 ;
if ( V_6 -> V_29 == 0 && V_6 -> V_31 == 0 )
return 0 ;
if ( V_46 -> V_47 < V_6 -> V_29 ||
V_46 -> V_47 > V_6 -> V_31 )
return - 1 ;
V_46 -> V_47 -= V_6 -> V_29 ;
return 1 ;
}
static int F_24 ( struct V_48 * V_18 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
if ( V_18 -> type == V_52 ) {
struct V_53 * V_54 = & V_18 -> V_49 . V_55 ;
if ( V_51 -> V_56 ++ == V_51 -> V_57 ) {
V_51 -> V_46 . V_58 = V_54 -> V_59 ;
V_51 -> V_46 . V_47 = V_54 -> V_60 ;
}
}
return 1 ;
}
struct V_61 * F_25 ( struct V_41 * V_25 ,
T_3 V_57 )
{
struct V_50 V_51 ;
struct V_45 * V_46 = & V_51 . V_46 ;
struct V_9 V_10 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_61 * V_62 = NULL ;
int V_63 ;
if ( ! V_25 )
return F_26 ( - V_17 ) ;
V_4 = F_27 ( V_25 ) ;
if ( ! V_4 )
return F_26 ( - V_17 ) ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
V_51 . V_57 = V_57 ;
V_46 -> V_58 = - 1 ;
V_46 -> V_47 = - 1 ;
F_2 ( & V_10 ) ;
F_3 ( V_4 , & V_10 ,
F_24 , & V_51 ) ;
F_6 ( & V_10 ) ;
if ( V_46 -> V_47 < 0 || V_46 -> V_58 < 0 )
return F_26 ( - V_17 ) ;
F_15 ( & V_43 ) ;
F_4 (adma, &acpi_dma_list, dma_controllers) {
V_63 = F_23 ( V_6 , V_46 ) ;
if ( V_63 < 0 )
continue;
V_62 = V_6 -> V_64 ( V_46 , V_6 ) ;
if ( V_63 > 0 || V_62 )
break;
}
F_17 ( & V_43 ) ;
return V_62 ? V_62 : F_26 ( - V_65 ) ;
}
struct V_61 * F_28 ( struct V_41 * V_25 ,
const char * V_66 )
{
int V_57 ;
V_57 = F_29 ( V_25 , L_5 , V_66 ) ;
if ( V_57 < 0 ) {
if ( ! strcmp ( V_66 , L_6 ) )
V_57 = 0 ;
else if ( ! strcmp ( V_66 , L_7 ) )
V_57 = 1 ;
else
return F_26 ( - V_17 ) ;
}
F_9 ( V_25 , L_8 , V_66 , V_57 ) ;
return F_25 ( V_25 , V_57 ) ;
}
struct V_61 * F_30 ( struct V_45 * V_46 ,
struct V_5 * V_6 )
{
struct V_67 * V_68 = V_6 -> V_49 ;
if ( ! V_68 || ! V_68 -> V_69 )
return NULL ;
return F_31 ( V_68 -> V_70 , V_68 -> V_69 , V_46 ) ;
}
