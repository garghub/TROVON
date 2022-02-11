static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_6 = 0 ;
return 0 ;
}
static T_1 F_2 ( T_2 * V_7 , enum V_8 * type ,
struct V_9 * time ,
char * * V_10 ,
struct V_1 * V_2 )
{
T_1 V_11 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 ;
if ( V_4 -> V_6 >= V_4 -> V_14 )
return - V_15 ;
* V_7 = V_4 -> V_6 ++ ;
V_13 = V_4 -> V_16 [ * V_7 ] ;
* type = V_17 ;
time -> V_18 = 0 ;
time -> V_19 = 0 ;
F_3 ( V_13 ) ;
V_11 = F_4 ( V_13 ) ;
* V_10 = F_5 ( V_11 , V_20 ) ;
if ( * V_10 == NULL )
return - V_21 ;
memcpy ( * V_10 , F_6 ( V_13 ) , V_11 ) ;
return V_11 ;
}
static T_3 F_7 ( struct V_12 * V_13 )
{
char * V_22 ;
struct V_23 V_24 ;
T_3 V_25 ;
F_8 ( & V_24 ) ;
V_22 = F_9 ( V_26 , V_27 L_1 ,
( long ) V_24 . V_18 , ( long ) V_24 . V_28 ) ;
F_10 ( ! V_22 ) ;
V_25 = V_22 ? strlen ( V_22 ) : 0 ;
F_11 ( V_13 , V_22 , V_25 ) ;
F_12 ( V_22 ) ;
return V_25 ;
}
static int F_13 ( enum V_8 type ,
enum V_29 V_30 ,
T_2 * V_7 ,
unsigned int V_31 ,
T_3 V_11 , struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 = V_4 -> V_16 [ V_4 -> V_32 ] ;
T_3 V_33 ;
if ( type != V_17 )
return - V_15 ;
if ( V_30 != V_34 &&
V_30 != V_35 )
return - V_15 ;
if ( V_30 == V_34 && ! V_4 -> V_36 )
return - V_15 ;
if ( V_31 != 1 )
return - V_37 ;
V_33 = F_7 ( V_13 ) ;
if ( V_11 + V_33 > V_13 -> V_38 )
V_11 = V_13 -> V_38 - V_33 ;
F_11 ( V_13 , V_4 -> V_39 . V_10 , V_11 ) ;
V_4 -> V_32 = ( V_4 -> V_32 + 1 ) % V_4 -> V_14 ;
return 0 ;
}
static int F_14 ( enum V_8 type , T_2 V_7 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_7 >= V_4 -> V_14 )
return - V_15 ;
F_15 ( V_4 -> V_16 [ V_7 ] ) ;
F_16 ( V_4 -> V_16 [ V_7 ] ) ;
return 0 ;
}
static int T_4 F_17 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = & V_41 -> V_43 ;
struct V_44 * V_45 = V_41 -> V_43 . V_46 ;
struct V_3 * V_4 = & V_47 ;
int V_48 = - V_15 ;
int V_49 ;
if ( V_4 -> V_14 )
goto V_50;
if ( ! V_45 -> V_51 || ! V_45 -> V_52 ) {
F_18 ( L_2
L_3 ) ;
goto V_50;
}
V_45 -> V_51 = F_19 ( V_45 -> V_51 ) ;
V_45 -> V_52 = F_19 ( V_45 -> V_52 ) ;
if ( V_45 -> V_51 < V_53 &&
V_45 -> V_52 < V_53 ) {
F_18 ( L_4 ,
V_53 ) ;
goto V_50;
}
if ( V_45 -> V_51 < V_45 -> V_52 ) {
F_18 ( L_5
L_6 ) ;
goto V_50;
}
V_4 -> V_14 = V_45 -> V_51 / V_45 -> V_52 ;
V_4 -> V_32 = 0 ;
V_4 -> V_11 = V_45 -> V_51 ;
V_4 -> V_54 = V_45 -> V_55 ;
V_4 -> V_52 = V_45 -> V_52 ;
V_4 -> V_36 = V_45 -> V_36 ;
V_4 -> V_56 = V_45 -> V_56 ;
V_4 -> V_16 = F_20 ( sizeof( * V_4 -> V_16 ) * V_4 -> V_14 , V_20 ) ;
if ( ! V_4 -> V_16 ) {
V_48 = - V_21 ;
F_21 ( V_43 , L_7 ) ;
goto V_50;
}
for ( V_49 = 0 ; V_49 < V_4 -> V_14 ; V_49 ++ ) {
T_3 V_57 = V_4 -> V_52 ;
T_5 V_58 = V_4 -> V_54 + V_57 * V_49 ;
V_4 -> V_16 [ V_49 ] = F_22 ( V_58 , V_57 , V_4 -> V_56 ) ;
if ( F_23 ( V_4 -> V_16 [ V_49 ] ) ) {
V_48 = F_24 ( V_4 -> V_16 [ V_49 ] ) ;
F_21 ( V_43 , L_8 ,
V_57 , ( unsigned long long ) V_58 , V_48 ) ;
goto V_59;
}
}
V_4 -> V_39 . V_5 = V_4 ;
V_4 -> V_39 . V_60 = V_4 -> V_16 [ 0 ] -> V_38 ;
V_4 -> V_39 . V_10 = F_5 ( V_4 -> V_39 . V_60 , V_20 ) ;
F_25 ( & V_4 -> V_39 . V_61 ) ;
if ( ! V_4 -> V_39 . V_10 ) {
F_18 ( L_9 ) ;
goto V_62;
}
V_48 = F_26 ( & V_4 -> V_39 ) ;
if ( V_48 ) {
F_18 ( L_10 ) ;
goto V_63;
}
V_51 = V_45 -> V_51 ;
V_55 = V_45 -> V_55 ;
V_52 = V_45 -> V_52 ;
V_36 = V_45 -> V_36 ;
F_27 ( L_11 ,
V_4 -> V_11 , ( unsigned long long ) V_4 -> V_54 ,
V_4 -> V_14 , V_4 -> V_52 ,
V_64 ? L_12 : L_13 ) ;
return 0 ;
V_63:
F_12 ( V_4 -> V_39 . V_10 ) ;
V_62:
V_4 -> V_39 . V_60 = 0 ;
V_4 -> V_14 = 0 ;
V_59:
for ( V_49 = 0 ; V_4 -> V_16 [ V_49 ] ; V_49 ++ )
F_28 ( V_4 -> V_16 [ V_49 ] ) ;
F_12 ( V_4 -> V_16 ) ;
V_50:
return V_48 ;
}
static int T_6 F_29 ( struct V_40 * V_41 )
{
#if 0
struct ramoops_context *cxt = &oops_cxt;
iounmap(cxt->virt_addr);
release_mem_region(cxt->phys_addr, cxt->size);
cxt->max_count = 0;
kfree(cxt->pstore.buf);
cxt->pstore.bufsize = 0;
return 0;
#endif
return - V_65 ;
}
static int T_4 F_30 ( void )
{
int V_66 ;
V_66 = F_31 ( & V_67 , F_17 ) ;
if ( V_66 == - V_68 ) {
F_27 ( L_14 ) ;
V_69 = F_20 ( sizeof( struct V_44 ) ,
V_20 ) ;
if ( ! V_69 )
return - V_21 ;
V_69 -> V_51 = V_51 ;
V_69 -> V_55 = V_55 ;
V_69 -> V_52 = V_52 ;
V_69 -> V_36 = V_36 ;
V_69 -> V_56 = V_64 ;
V_70 = F_32 ( & V_67 , F_17 ,
NULL , 0 , V_69 ,
sizeof( struct V_44 ) ) ;
if ( F_23 ( V_70 ) )
V_66 = F_24 ( V_70 ) ;
else
V_66 = 0 ;
}
return V_66 ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_67 ) ;
F_12 ( V_69 ) ;
}
