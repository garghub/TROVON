int F_1 ( void )
{
V_1 = F_2 ( V_2 * sizeof( struct V_3 ) ,
V_4 ) ;
if ( ! V_1 )
return - V_5 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static struct V_3 * F_5 ( struct V_6 * V_6 , const char * V_7 )
{
unsigned int V_8 = F_6 ( V_7 , strlen ( V_7 ) , ( unsigned long ) V_6 ) ;
return & V_1 [ V_8 & ( V_2 - 1 ) ] ;
}
struct V_9 * F_7 ( struct V_6 * V_6 , const char * V_7 )
{
struct V_3 * V_10 = F_5 ( V_6 , V_7 ) ;
struct V_9 * V_9 ;
F_8 (vport, bucket, hash_node)
if ( ! strcmp ( V_7 , V_9 -> V_11 -> V_12 ( V_9 ) ) &&
F_9 ( F_10 ( V_9 -> V_13 ) , V_6 ) )
return V_9 ;
return NULL ;
}
struct V_9 * F_11 ( int V_14 , const struct V_15 * V_11 ,
const struct V_16 * V_17 )
{
struct V_9 * V_9 ;
T_1 V_18 ;
V_18 = sizeof( struct V_9 ) ;
if ( V_14 ) {
V_18 = F_12 ( V_18 , V_19 ) ;
V_18 += V_14 ;
}
V_9 = F_2 ( V_18 , V_4 ) ;
if ( ! V_9 )
return F_13 ( - V_5 ) ;
V_9 -> V_13 = V_17 -> V_13 ;
V_9 -> V_20 = V_17 -> V_20 ;
V_9 -> V_11 = V_11 ;
F_14 ( & V_9 -> V_21 ) ;
if ( F_15 ( V_9 , V_17 -> V_22 ) ) {
F_4 ( V_9 ) ;
return F_13 ( - V_23 ) ;
}
V_9 -> V_24 = F_16 ( struct V_25 ) ;
if ( ! V_9 -> V_24 ) {
F_4 ( V_9 ) ;
return F_13 ( - V_5 ) ;
}
return V_9 ;
}
void F_17 ( struct V_9 * V_9 )
{
F_4 ( F_18 ( V_9 -> V_22 ) ) ;
F_19 ( V_9 -> V_24 ) ;
F_4 ( V_9 ) ;
}
struct V_9 * F_20 ( const struct V_16 * V_17 )
{
struct V_9 * V_9 ;
int V_26 = 0 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_21 ( V_28 ) ; V_27 ++ ) {
if ( V_28 [ V_27 ] -> type == V_17 -> type ) {
struct V_3 * V_10 ;
V_9 = V_28 [ V_27 ] -> F_22 ( V_17 ) ;
if ( F_23 ( V_9 ) ) {
V_26 = F_24 ( V_9 ) ;
goto V_29;
}
V_10 = F_5 ( F_10 ( V_9 -> V_13 ) ,
V_9 -> V_11 -> V_12 ( V_9 ) ) ;
F_25 ( & V_9 -> V_30 , V_10 ) ;
return V_9 ;
}
}
V_26 = - V_31 ;
V_29:
return F_13 ( V_26 ) ;
}
int F_26 ( struct V_9 * V_9 , struct V_32 * V_33 )
{
if ( ! V_9 -> V_11 -> V_34 )
return - V_35 ;
return V_9 -> V_11 -> V_34 ( V_9 , V_33 ) ;
}
void F_27 ( struct V_9 * V_9 )
{
F_28 () ;
F_29 ( & V_9 -> V_30 ) ;
V_9 -> V_11 -> V_36 ( V_9 ) ;
}
void F_30 ( struct V_9 * V_9 , struct V_37 * V_38 )
{
int V_27 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_39 = F_31 ( & V_9 -> V_40 . V_39 ) ;
V_38 -> V_41 = F_31 ( & V_9 -> V_40 . V_41 ) ;
V_38 -> V_42 = F_31 ( & V_9 -> V_40 . V_42 ) ;
V_38 -> V_43 = F_31 ( & V_9 -> V_40 . V_43 ) ;
F_32 (i) {
const struct V_25 * V_24 ;
struct V_25 V_44 ;
unsigned int V_45 ;
V_24 = F_33 ( V_9 -> V_24 , V_27 ) ;
do {
V_45 = F_34 ( & V_24 -> V_46 ) ;
V_44 = * V_24 ;
} while ( F_35 ( & V_24 -> V_46 , V_45 ) );
V_38 -> V_47 += V_44 . V_47 ;
V_38 -> V_48 += V_44 . V_48 ;
V_38 -> V_49 += V_44 . V_49 ;
V_38 -> V_50 += V_44 . V_50 ;
}
}
int F_36 ( const struct V_9 * V_9 , struct V_51 * V_52 )
{
struct V_32 * V_53 ;
int V_26 ;
if ( ! V_9 -> V_11 -> V_54 )
return 0 ;
V_53 = F_37 ( V_52 , V_55 ) ;
if ( ! V_53 )
return - V_56 ;
V_26 = V_9 -> V_11 -> V_54 ( V_9 , V_52 ) ;
if ( V_26 ) {
F_38 ( V_52 , V_53 ) ;
return V_26 ;
}
F_39 ( V_52 , V_53 ) ;
return 0 ;
}
int F_15 ( struct V_9 * V_9 , struct V_32 * V_57 )
{
struct V_58 * V_59 , * V_58 ;
if ( ! F_40 ( V_57 ) || F_40 ( V_57 ) % sizeof( V_60 ) )
return - V_23 ;
V_59 = F_41 ( V_9 -> V_22 ) ;
V_58 = F_42 ( sizeof( * V_58 ) + F_40 ( V_57 ) ,
V_4 ) ;
if ( ! V_58 )
return - V_5 ;
V_58 -> V_61 = F_40 ( V_57 ) / sizeof( V_60 ) ;
V_58 -> V_62 = F_43 ( V_58 -> V_61 ) ;
F_44 ( V_58 -> V_57 , V_57 , F_40 ( V_57 ) ) ;
F_45 ( V_9 -> V_22 , V_58 ) ;
if ( V_59 )
F_46 ( V_59 , V_63 ) ;
return 0 ;
}
int F_47 ( const struct V_9 * V_9 ,
struct V_51 * V_52 )
{
struct V_58 * V_57 ;
V_57 = F_48 ( V_9 -> V_22 ) ;
if ( V_9 -> V_13 -> V_64 & V_65 )
return F_49 ( V_52 , V_66 ,
V_57 -> V_61 * sizeof( V_60 ) , ( void * ) V_57 -> V_57 ) ;
else
return F_50 ( V_52 , V_66 , V_57 -> V_57 [ 0 ] ) ;
}
V_60 F_51 ( const struct V_9 * V_9 , struct V_51 * V_52 )
{
struct V_58 * V_57 ;
V_60 V_67 ;
V_60 V_8 ;
V_57 = F_52 ( V_9 -> V_22 ) ;
if ( V_57 -> V_61 == 1 && V_57 -> V_57 [ 0 ] == 0 )
return 0 ;
V_8 = F_53 ( V_52 ) ;
V_67 = V_8 - V_57 -> V_61 * F_54 ( V_8 , V_57 -> V_62 ) ;
return V_57 -> V_57 [ V_67 ] ;
}
void F_55 ( struct V_9 * V_9 , struct V_51 * V_52 ,
struct V_68 * V_69 )
{
struct V_25 * V_38 ;
struct V_70 V_71 ;
int error ;
V_38 = F_56 ( V_9 -> V_24 ) ;
F_57 ( & V_38 -> V_46 ) ;
V_38 -> V_48 ++ ;
V_38 -> V_47 += V_52 -> V_72 ;
F_58 ( & V_38 -> V_46 ) ;
F_59 ( V_52 ) -> V_73 = V_9 ;
F_59 ( V_52 ) -> V_74 = NULL ;
error = F_60 ( V_69 , V_52 , & V_71 ) ;
if ( F_61 ( error ) ) {
F_62 ( V_52 ) ;
return;
}
F_63 ( V_52 , & V_71 ) ;
}
int F_64 ( struct V_9 * V_9 , struct V_51 * V_52 )
{
int V_75 = V_9 -> V_11 -> V_76 ( V_9 , V_52 ) ;
if ( F_65 ( V_75 > 0 ) ) {
struct V_25 * V_38 ;
V_38 = F_56 ( V_9 -> V_24 ) ;
F_57 ( & V_38 -> V_46 ) ;
V_38 -> V_50 ++ ;
V_38 -> V_49 += V_75 ;
F_58 ( & V_38 -> V_46 ) ;
} else if ( V_75 < 0 ) {
F_66 ( V_9 , V_77 ) ;
F_62 ( V_52 ) ;
} else
F_66 ( V_9 , V_78 ) ;
return V_75 ;
}
static void F_66 ( struct V_9 * V_9 ,
enum V_79 V_80 )
{
switch ( V_80 ) {
case V_81 :
F_67 ( & V_9 -> V_40 . V_43 ) ;
break;
case V_82 :
F_67 ( & V_9 -> V_40 . V_39 ) ;
break;
case V_78 :
F_67 ( & V_9 -> V_40 . V_42 ) ;
break;
case V_77 :
F_67 ( & V_9 -> V_40 . V_41 ) ;
break;
}
}
static void F_68 ( struct V_83 * V_63 )
{
struct V_9 * V_9 = F_69 ( V_63 , struct V_9 , V_63 ) ;
F_17 ( V_9 ) ;
}
void F_70 ( struct V_9 * V_9 )
{
if ( ! V_9 )
return;
F_71 ( & V_9 -> V_63 , F_68 ) ;
}
