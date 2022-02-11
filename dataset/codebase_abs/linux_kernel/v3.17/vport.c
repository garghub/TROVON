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
F_17 ( & V_9 -> V_26 ) ;
return V_9 ;
}
void F_18 ( struct V_9 * V_9 )
{
F_4 ( F_19 ( V_9 -> V_22 ) ) ;
F_20 ( V_9 -> V_24 ) ;
F_4 ( V_9 ) ;
}
struct V_9 * F_21 ( const struct V_16 * V_17 )
{
struct V_9 * V_9 ;
int V_27 = 0 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_22 ( V_29 ) ; V_28 ++ ) {
if ( V_29 [ V_28 ] -> type == V_17 -> type ) {
struct V_3 * V_10 ;
V_9 = V_29 [ V_28 ] -> F_23 ( V_17 ) ;
if ( F_24 ( V_9 ) ) {
V_27 = F_25 ( V_9 ) ;
goto V_30;
}
V_10 = F_5 ( F_10 ( V_9 -> V_13 ) ,
V_9 -> V_11 -> V_12 ( V_9 ) ) ;
F_26 ( & V_9 -> V_31 , V_10 ) ;
return V_9 ;
}
}
V_27 = - V_32 ;
V_30:
return F_13 ( V_27 ) ;
}
int F_27 ( struct V_9 * V_9 , struct V_33 * V_34 )
{
if ( ! V_9 -> V_11 -> V_35 )
return - V_36 ;
return V_9 -> V_11 -> V_35 ( V_9 , V_34 ) ;
}
void F_28 ( struct V_9 * V_9 )
{
F_29 () ;
F_30 ( & V_9 -> V_31 ) ;
V_9 -> V_11 -> V_37 ( V_9 ) ;
}
void F_31 ( struct V_9 * V_9 , struct V_38 * V_39 )
{
int V_28 ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_32 ( & V_9 -> V_26 ) ;
V_39 -> V_40 = V_9 -> V_41 . V_40 ;
V_39 -> V_42 = V_9 -> V_41 . V_42 ;
V_39 -> V_43 = V_9 -> V_41 . V_43 ;
V_39 -> V_44 = V_9 -> V_41 . V_44 ;
F_33 ( & V_9 -> V_26 ) ;
F_34 (i) {
const struct V_25 * V_24 ;
struct V_25 V_45 ;
unsigned int V_46 ;
V_24 = F_35 ( V_9 -> V_24 , V_28 ) ;
do {
V_46 = F_36 ( & V_24 -> V_47 ) ;
V_45 = * V_24 ;
} while ( F_37 ( & V_24 -> V_47 , V_46 ) );
V_39 -> V_48 += V_45 . V_48 ;
V_39 -> V_49 += V_45 . V_49 ;
V_39 -> V_50 += V_45 . V_50 ;
V_39 -> V_51 += V_45 . V_51 ;
}
}
int F_38 ( const struct V_9 * V_9 , struct V_52 * V_53 )
{
struct V_33 * V_54 ;
int V_27 ;
if ( ! V_9 -> V_11 -> V_55 )
return 0 ;
V_54 = F_39 ( V_53 , V_56 ) ;
if ( ! V_54 )
return - V_57 ;
V_27 = V_9 -> V_11 -> V_55 ( V_9 , V_53 ) ;
if ( V_27 ) {
F_40 ( V_53 , V_54 ) ;
return V_27 ;
}
F_41 ( V_53 , V_54 ) ;
return 0 ;
}
int F_15 ( struct V_9 * V_9 , struct V_33 * V_58 )
{
struct V_59 * V_60 , * V_59 ;
if ( ! F_42 ( V_58 ) || F_42 ( V_58 ) % sizeof( V_61 ) )
return - V_23 ;
V_60 = F_43 ( V_9 -> V_22 ) ;
V_59 = F_44 ( sizeof( * V_59 ) + F_42 ( V_58 ) ,
V_4 ) ;
if ( ! V_59 )
return - V_5 ;
V_59 -> V_62 = F_42 ( V_58 ) / sizeof( V_61 ) ;
V_59 -> V_63 = F_45 ( V_59 -> V_62 ) ;
F_46 ( V_59 -> V_58 , V_58 , F_42 ( V_58 ) ) ;
F_47 ( V_9 -> V_22 , V_59 ) ;
if ( V_60 )
F_48 ( V_60 , V_64 ) ;
return 0 ;
}
int F_49 ( const struct V_9 * V_9 ,
struct V_52 * V_53 )
{
struct V_59 * V_58 ;
V_58 = F_50 ( V_9 -> V_22 ) ;
if ( V_9 -> V_13 -> V_65 & V_66 )
return F_51 ( V_53 , V_67 ,
V_58 -> V_62 * sizeof( V_61 ) , ( void * ) V_58 -> V_58 ) ;
else
return F_52 ( V_53 , V_67 , V_58 -> V_58 [ 0 ] ) ;
}
V_61 F_53 ( const struct V_9 * V_68 , struct V_52 * V_53 )
{
struct V_59 * V_58 ;
V_61 V_69 ;
V_61 V_8 ;
V_58 = F_54 ( V_68 -> V_22 ) ;
if ( V_58 -> V_62 == 1 && V_58 -> V_58 [ 0 ] == 0 )
return 0 ;
V_8 = F_55 ( V_53 ) ;
V_69 = V_8 - V_58 -> V_62 * F_56 ( V_8 , V_58 -> V_63 ) ;
return V_58 -> V_58 [ V_69 ] ;
}
void F_57 ( struct V_9 * V_9 , struct V_52 * V_53 ,
struct V_70 * V_71 )
{
struct V_25 * V_39 ;
V_39 = F_58 ( V_9 -> V_24 ) ;
F_59 ( & V_39 -> V_47 ) ;
V_39 -> V_49 ++ ;
V_39 -> V_48 += V_53 -> V_72 ;
F_60 ( & V_39 -> V_47 ) ;
F_61 ( V_53 ) -> V_71 = V_71 ;
F_62 ( V_9 , V_53 ) ;
}
int F_63 ( struct V_9 * V_9 , struct V_52 * V_53 )
{
int V_73 = V_9 -> V_11 -> V_74 ( V_9 , V_53 ) ;
if ( F_64 ( V_73 > 0 ) ) {
struct V_25 * V_39 ;
V_39 = F_58 ( V_9 -> V_24 ) ;
F_59 ( & V_39 -> V_47 ) ;
V_39 -> V_51 ++ ;
V_39 -> V_50 += V_73 ;
F_60 ( & V_39 -> V_47 ) ;
} else if ( V_73 < 0 ) {
F_65 ( V_9 , V_75 ) ;
F_66 ( V_53 ) ;
} else
F_65 ( V_9 , V_76 ) ;
return V_73 ;
}
static void F_65 ( struct V_9 * V_9 ,
enum V_77 V_78 )
{
F_67 ( & V_9 -> V_26 ) ;
switch ( V_78 ) {
case V_79 :
V_9 -> V_41 . V_44 ++ ;
break;
case V_80 :
V_9 -> V_41 . V_40 ++ ;
break;
case V_76 :
V_9 -> V_41 . V_43 ++ ;
break;
case V_75 :
V_9 -> V_41 . V_42 ++ ;
break;
}
F_68 ( & V_9 -> V_26 ) ;
}
static void F_69 ( struct V_81 * V_64 )
{
struct V_9 * V_9 = F_70 ( V_64 , struct V_9 , V_64 ) ;
F_18 ( V_9 ) ;
}
void F_71 ( struct V_9 * V_9 )
{
if ( ! V_9 )
return;
F_72 ( & V_9 -> V_64 , F_69 ) ;
}
