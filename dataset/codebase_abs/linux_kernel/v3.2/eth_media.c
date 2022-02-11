static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_10 ;
V_7 = F_2 ( V_2 , V_11 ) ;
if ( ! V_7 )
return 0 ;
V_9 = ( (struct V_12 * ) ( V_4 -> V_13 ) ) -> V_9 ;
V_10 = V_9 -> V_14 - F_3 ( V_2 ) ;
if ( ( V_10 > 0 ) &&
F_4 ( V_7 , F_5 ( V_10 ) , 0 , V_11 ) ) {
F_6 ( V_7 ) ;
return 0 ;
}
F_7 ( V_7 ) ;
V_7 -> V_9 = V_9 ;
F_8 ( V_7 , V_9 , V_15 , & V_6 -> V_16 . V_17 ,
V_9 -> V_16 , V_7 -> V_18 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_19 * V_20 , struct V_8 * V_21 )
{
struct V_12 * V_22 = (struct V_12 * ) V_20 -> V_23 ;
if ( ! F_11 ( F_12 ( V_9 ) , & V_24 ) ) {
F_6 ( V_2 ) ;
return 0 ;
}
if ( F_13 ( V_22 -> V_25 ) ) {
if ( F_13 ( V_2 -> V_26 <= V_27 ) ) {
V_2 -> V_28 = NULL ;
F_14 ( V_2 , V_22 -> V_25 ) ;
return 0 ;
}
}
F_6 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = NULL ;
struct V_8 * V_29 = NULL ;
struct V_12 * V_22 = & V_30 [ 0 ] ;
struct V_12 * V_31 = & V_30 [ V_32 ] ;
char * V_33 = strchr ( ( const char * ) V_4 -> V_34 , ':' ) + 1 ;
int V_35 = 0 ;
while ( V_22 -> V_9 ) {
if ( ! V_22 -> V_25 )
V_35 ++ ;
if ( ++ V_22 == V_31 )
return V_35 ? - V_36 : - V_37 ;
}
F_16 ( & V_38 ) ;
F_17 (&init_net, pdev) {
if ( ! strncmp ( V_29 -> V_34 , V_33 , V_39 ) ) {
V_9 = V_29 ;
F_18 ( V_9 ) ;
break;
}
}
F_19 ( & V_38 ) ;
if ( ! V_9 )
return - V_40 ;
V_22 -> V_9 = V_9 ;
V_22 -> V_41 . type = F_20 ( V_15 ) ;
V_22 -> V_41 . V_9 = V_9 ;
V_22 -> V_41 . V_42 = F_10 ;
V_22 -> V_41 . V_23 = V_22 ;
F_21 ( & ( V_22 -> V_41 . V_43 ) ) ;
F_22 ( & V_22 -> V_41 ) ;
V_22 -> V_25 = V_4 ;
V_4 -> V_13 = ( void * ) V_22 ;
V_4 -> V_44 = V_9 -> V_44 ;
V_4 -> V_45 = 0 ;
V_4 -> V_46 . type = F_23 ( V_47 ) ;
memcpy ( & V_4 -> V_46 . V_16 , V_9 -> V_16 , V_48 ) ;
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
( (struct V_12 * ) V_4 -> V_13 ) -> V_25 = NULL ;
}
static int F_25 ( struct V_49 * V_50 , unsigned long V_51 ,
void * V_52 )
{
struct V_8 * V_9 = (struct V_8 * ) V_52 ;
struct V_12 * V_22 = & V_30 [ 0 ] ;
struct V_12 * V_31 = & V_30 [ V_32 ] ;
if ( ! F_11 ( F_12 ( V_9 ) , & V_24 ) )
return V_53 ;
while ( ( V_22 -> V_9 != V_9 ) ) {
if ( ++ V_22 == V_31 )
return V_53 ;
}
if ( ! V_22 -> V_25 )
return V_53 ;
V_22 -> V_25 -> V_44 = V_9 -> V_44 ;
switch ( V_51 ) {
case V_54 :
if ( F_26 ( V_9 ) )
F_27 ( V_22 -> V_25 ) ;
else
F_28 ( V_22 -> V_25 -> V_34 ) ;
break;
case V_55 :
F_27 ( V_22 -> V_25 ) ;
break;
case V_56 :
F_28 ( V_22 -> V_25 -> V_34 ) ;
break;
case V_57 :
case V_58 :
F_28 ( V_22 -> V_25 -> V_34 ) ;
F_27 ( V_22 -> V_25 ) ;
break;
case V_59 :
case V_60 :
F_29 ( V_22 -> V_25 -> V_34 ) ;
break;
}
return V_61 ;
}
static char * F_30 ( struct V_5 * V_62 , char * V_63 , int V_64 )
{
T_1 * V_46 = ( T_1 * ) & V_62 -> V_16 ;
if ( V_64 < 18 )
* V_63 = '\0' ;
else
sprintf ( V_63 , L_1 , V_46 ) ;
return V_63 ;
}
int F_31 ( void )
{
struct V_5 V_65 ;
int V_66 ;
if ( V_67 )
return - V_68 ;
V_65 . type = F_23 ( V_47 ) ;
memset ( & V_65 . V_16 , 0xff , V_48 ) ;
memset ( V_30 , 0 , sizeof( V_30 ) ) ;
V_66 = F_32 ( V_47 , L_2 ,
F_15 , F_24 , F_1 ,
F_30 , & V_65 , V_69 ,
V_70 , V_71 ) ;
if ( V_66 )
return V_66 ;
V_72 . V_73 = & F_25 ;
V_72 . V_74 = 0 ;
V_66 = F_33 ( & V_72 ) ;
if ( ! V_66 )
V_67 = 1 ;
return V_66 ;
}
void F_34 ( void )
{
int V_75 ;
if ( ! V_67 )
return;
F_35 ( & V_72 ) ;
for ( V_75 = 0 ; V_75 < V_32 ; V_75 ++ ) {
if ( V_30 [ V_75 ] . V_25 ) {
V_30 [ V_75 ] . V_25 -> V_45 = 1 ;
V_30 [ V_75 ] . V_25 = NULL ;
}
if ( V_30 [ V_75 ] . V_9 ) {
F_36 ( & V_30 [ V_75 ] . V_41 ) ;
F_37 ( V_30 [ V_75 ] . V_9 ) ;
}
}
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_67 = 0 ;
}
