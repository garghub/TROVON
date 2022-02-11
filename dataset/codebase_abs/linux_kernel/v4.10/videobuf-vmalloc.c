static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( 2 , L_1 , V_4 ,
V_4 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
V_4 -> V_6 ++ ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_10 = V_4 -> V_10 ;
int V_11 ;
F_2 ( 2 , L_2 , V_4 ,
V_4 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
V_4 -> V_6 -- ;
if ( 0 == V_4 -> V_6 ) {
struct V_12 * V_13 ;
F_2 ( 1 , L_3 , V_4 , V_10 ) ;
F_4 ( V_10 ) ;
if ( V_10 -> V_14 )
F_5 ( V_10 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ ) {
if ( NULL == V_10 -> V_16 [ V_11 ] )
continue;
if ( V_10 -> V_16 [ V_11 ] -> V_4 != V_4 )
continue;
V_13 = V_10 -> V_16 [ V_11 ] -> V_17 ;
if ( V_13 ) {
F_6 ( V_13 -> V_18 , V_19 ) ;
F_2 ( 1 , L_4 ,
V_20 , V_11 , V_13 -> V_21 ) ;
F_7 ( V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
}
V_10 -> V_16 [ V_11 ] -> V_4 = NULL ;
V_10 -> V_16 [ V_11 ] -> V_22 = 0 ;
}
F_8 ( V_4 ) ;
F_9 ( V_10 ) ;
}
return;
}
static struct V_23 * F_10 ( T_1 V_24 )
{
struct V_12 * V_13 ;
struct V_23 * V_25 ;
V_25 = F_11 ( V_24 + sizeof( * V_13 ) , V_26 ) ;
if ( ! V_25 )
return V_25 ;
V_13 = V_25 -> V_17 = ( ( char * ) V_25 ) + V_24 ;
V_13 -> V_18 = V_19 ;
F_2 ( 1 , L_5 ,
V_20 , V_25 , ( long ) sizeof( * V_25 ) , ( long ) V_24 - sizeof( * V_25 ) ,
V_13 , ( long ) sizeof( * V_13 ) ) ;
return V_25 ;
}
static int F_12 ( struct V_9 * V_10 ,
struct V_23 * V_25 ,
struct V_27 * V_28 )
{
struct V_12 * V_13 = V_25 -> V_17 ;
int V_29 ;
F_13 ( ! V_13 ) ;
F_6 ( V_13 -> V_18 , V_19 ) ;
switch ( V_25 -> V_30 ) {
case V_31 :
F_2 ( 1 , L_6 , V_20 ) ;
if ( ! V_13 -> V_21 ) {
F_14 ( V_32 L_7 ) ;
return - V_33 ;
}
break;
case V_34 :
V_29 = F_15 ( V_25 -> V_24 ) ;
F_2 ( 1 , L_8 , V_20 ) ;
if ( V_25 -> V_22 ) {
F_14 ( V_32 L_9 ) ;
return - V_33 ;
}
V_13 -> V_21 = F_16 ( V_29 ) ;
if ( ! V_13 -> V_21 ) {
F_14 ( V_32 L_10 , V_29 ) ;
return - V_35 ;
}
F_2 ( 1 , L_11 ,
V_13 -> V_21 , V_29 ) ;
#if 0
int rc;
if (!vb->baddr)
return 0;
rc = remap_vmalloc_range(mem->vma, (void *)vb->baddr, 0);
if (rc < 0) {
printk(KERN_ERR "mmap: remap failed with error %d", rc);
return -ENOMEM;
}
#endif
break;
case V_36 :
default:
F_2 ( 1 , L_12 , V_20 ) ;
F_14 ( V_32 L_13 ) ;
return - V_33 ;
}
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_23 * V_37 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 ;
int V_38 , V_29 ;
F_2 ( 1 , L_14 , V_20 ) ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_26 ) ;
if ( NULL == V_4 )
return - V_35 ;
V_37 -> V_4 = V_4 ;
V_4 -> V_10 = V_10 ;
V_37 -> V_22 = V_2 -> V_7 ;
V_13 = V_37 -> V_17 ;
F_13 ( ! V_13 ) ;
F_6 ( V_13 -> V_18 , V_19 ) ;
V_29 = F_15 ( V_2 -> V_8 - V_2 -> V_7 ) ;
V_13 -> V_21 = F_16 ( V_29 ) ;
if ( ! V_13 -> V_21 ) {
F_14 ( V_32 L_10 , V_29 ) ;
goto error;
}
F_2 ( 1 , L_11 , V_13 -> V_21 , V_29 ) ;
V_38 = F_18 ( V_2 , V_13 -> V_21 , 0 ) ;
if ( V_38 < 0 ) {
F_14 ( V_32 L_15 , V_38 ) ;
F_7 ( V_13 -> V_21 ) ;
goto error;
}
V_2 -> V_39 = & V_40 ;
V_2 -> V_41 |= V_42 | V_43 ;
V_2 -> V_5 = V_4 ;
F_2 ( 1 , L_16 ,
V_4 , V_10 , V_2 -> V_7 , V_2 -> V_8 ,
( long int ) V_37 -> V_44 ,
V_2 -> V_45 , V_37 -> V_11 ) ;
F_1 ( V_2 ) ;
return 0 ;
error:
V_13 = NULL ;
F_8 ( V_4 ) ;
return - V_35 ;
}
void F_19 ( struct V_9 * V_10 ,
const struct V_46 * V_47 ,
struct V_48 * V_49 ,
T_2 * V_50 ,
enum V_51 type ,
enum V_52 V_53 ,
unsigned int V_54 ,
void * V_17 ,
struct V_55 * V_56 )
{
F_20 ( V_10 , V_47 , V_49 , V_50 , type , V_53 , V_54 ,
V_17 , & V_57 , V_56 ) ;
}
void * F_21 ( struct V_23 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_17 ;
F_13 ( ! V_13 ) ;
F_6 ( V_13 -> V_18 , V_19 ) ;
return V_13 -> V_21 ;
}
void F_22 ( struct V_23 * V_37 )
{
struct V_12 * V_13 = V_37 -> V_17 ;
if ( ( V_37 -> V_30 != V_34 ) || V_37 -> V_22 )
return;
if ( ! V_13 )
return;
F_6 ( V_13 -> V_18 , V_19 ) ;
F_7 ( V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
return;
}
