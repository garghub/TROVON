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
struct V_11 * V_12 ;
F_8 (vport, node, bucket, hash_node)
if ( ! strcmp ( V_7 , V_9 -> V_13 -> V_14 ( V_9 ) ) &&
F_9 ( F_10 ( V_9 -> V_15 ) , V_6 ) )
return V_9 ;
return NULL ;
}
struct V_9 * F_11 ( int V_16 , const struct V_17 * V_13 ,
const struct V_18 * V_19 )
{
struct V_9 * V_9 ;
T_1 V_20 ;
V_20 = sizeof( struct V_9 ) ;
if ( V_16 ) {
V_20 = F_12 ( V_20 , V_21 ) ;
V_20 += V_16 ;
}
V_9 = F_2 ( V_20 , V_4 ) ;
if ( ! V_9 )
return F_13 ( - V_5 ) ;
V_9 -> V_15 = V_19 -> V_15 ;
V_9 -> V_22 = V_19 -> V_22 ;
V_9 -> V_23 = V_19 -> V_23 ;
V_9 -> V_13 = V_13 ;
F_14 ( & V_9 -> V_24 ) ;
V_9 -> V_25 = F_15 ( struct V_26 ) ;
if ( ! V_9 -> V_25 ) {
F_4 ( V_9 ) ;
return F_13 ( - V_5 ) ;
}
F_16 ( & V_9 -> V_27 ) ;
return V_9 ;
}
void F_17 ( struct V_9 * V_9 )
{
F_18 ( V_9 -> V_25 ) ;
F_4 ( V_9 ) ;
}
struct V_9 * F_19 ( const struct V_18 * V_19 )
{
struct V_9 * V_9 ;
int V_28 = 0 ;
int V_29 ;
F_20 () ;
for ( V_29 = 0 ; V_29 < F_21 ( V_30 ) ; V_29 ++ ) {
if ( V_30 [ V_29 ] -> type == V_19 -> type ) {
struct V_3 * V_10 ;
V_9 = V_30 [ V_29 ] -> F_22 ( V_19 ) ;
if ( F_23 ( V_9 ) ) {
V_28 = F_24 ( V_9 ) ;
goto V_31;
}
V_10 = F_5 ( F_10 ( V_9 -> V_15 ) ,
V_9 -> V_13 -> V_14 ( V_9 ) ) ;
F_25 ( & V_9 -> V_32 , V_10 ) ;
return V_9 ;
}
}
V_28 = - V_33 ;
V_31:
return F_13 ( V_28 ) ;
}
int F_26 ( struct V_9 * V_9 , struct V_34 * V_35 )
{
F_20 () ;
if ( ! V_9 -> V_13 -> V_36 )
return - V_37 ;
return V_9 -> V_13 -> V_36 ( V_9 , V_35 ) ;
}
void F_27 ( struct V_9 * V_9 )
{
F_20 () ;
F_28 ( & V_9 -> V_32 ) ;
V_9 -> V_13 -> V_38 ( V_9 ) ;
}
void F_29 ( struct V_9 * V_9 , struct V_39 * V_40 )
{
int V_29 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
F_30 ( & V_9 -> V_27 ) ;
V_40 -> V_41 = V_9 -> V_42 . V_41 ;
V_40 -> V_43 = V_9 -> V_42 . V_43 ;
V_40 -> V_44 = V_9 -> V_42 . V_44 ;
V_40 -> V_45 = V_9 -> V_42 . V_45 ;
F_31 ( & V_9 -> V_27 ) ;
F_32 (i) {
const struct V_26 * V_25 ;
struct V_26 V_46 ;
unsigned int V_47 ;
V_25 = F_33 ( V_9 -> V_25 , V_29 ) ;
do {
V_47 = F_34 ( & V_25 -> V_48 ) ;
V_46 = * V_25 ;
} while ( F_35 ( & V_25 -> V_48 , V_47 ) );
V_40 -> V_49 += V_46 . V_49 ;
V_40 -> V_50 += V_46 . V_50 ;
V_40 -> V_51 += V_46 . V_51 ;
V_40 -> V_52 += V_46 . V_52 ;
}
}
int F_36 ( const struct V_9 * V_9 , struct V_53 * V_54 )
{
struct V_34 * V_55 ;
V_55 = F_37 ( V_54 , V_56 ) ;
if ( ! V_55 )
return - V_57 ;
if ( V_9 -> V_13 -> V_58 ) {
int V_28 = V_9 -> V_13 -> V_58 ( V_9 , V_54 ) ;
if ( V_28 ) {
F_38 ( V_54 , V_55 ) ;
return V_28 ;
}
}
F_39 ( V_54 , V_55 ) ;
return 0 ;
}
void F_40 ( struct V_9 * V_9 , struct V_53 * V_54 )
{
struct V_26 * V_40 ;
V_40 = F_33 ( V_9 -> V_25 , F_41 () ) ;
F_42 ( & V_40 -> V_48 ) ;
V_40 -> V_50 ++ ;
V_40 -> V_49 += V_54 -> V_59 ;
F_43 ( & V_40 -> V_48 ) ;
F_44 ( V_9 , V_54 ) ;
}
int F_45 ( struct V_9 * V_9 , struct V_53 * V_54 )
{
int V_60 = V_9 -> V_13 -> V_61 ( V_9 , V_54 ) ;
if ( F_46 ( V_60 ) ) {
struct V_26 * V_40 ;
V_40 = F_33 ( V_9 -> V_25 , F_41 () ) ;
F_42 ( & V_40 -> V_48 ) ;
V_40 -> V_52 ++ ;
V_40 -> V_51 += V_60 ;
F_43 ( & V_40 -> V_48 ) ;
}
return V_60 ;
}
void F_47 ( struct V_9 * V_9 , enum V_62 V_63 )
{
F_48 ( & V_9 -> V_27 ) ;
switch ( V_63 ) {
case V_64 :
V_9 -> V_42 . V_45 ++ ;
break;
case V_65 :
V_9 -> V_42 . V_41 ++ ;
break;
case V_66 :
V_9 -> V_42 . V_44 ++ ;
break;
case V_67 :
V_9 -> V_42 . V_43 ++ ;
break;
}
F_49 ( & V_9 -> V_27 ) ;
}
