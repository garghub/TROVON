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
int V_19 ;
V_18 = sizeof( struct V_9 ) ;
if ( V_14 ) {
V_18 = F_12 ( V_18 , V_20 ) ;
V_18 += V_14 ;
}
V_9 = F_2 ( V_18 , V_4 ) ;
if ( ! V_9 )
return F_13 ( - V_5 ) ;
V_9 -> V_13 = V_17 -> V_13 ;
V_9 -> V_21 = V_17 -> V_21 ;
V_9 -> V_22 = V_17 -> V_22 ;
V_9 -> V_11 = V_11 ;
F_14 ( & V_9 -> V_23 ) ;
V_9 -> V_24 = F_15 ( struct V_25 ) ;
if ( ! V_9 -> V_24 ) {
F_4 ( V_9 ) ;
return F_13 ( - V_5 ) ;
}
F_16 (i) {
struct V_25 * V_26 ;
V_26 = F_17 ( V_9 -> V_24 , V_19 ) ;
F_18 ( & V_26 -> V_27 ) ;
}
F_19 ( & V_9 -> V_28 ) ;
return V_9 ;
}
void F_20 ( struct V_9 * V_9 )
{
F_21 ( V_9 -> V_24 ) ;
F_4 ( V_9 ) ;
}
struct V_9 * F_22 ( const struct V_16 * V_17 )
{
struct V_9 * V_9 ;
int V_29 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_23 ( V_30 ) ; V_19 ++ ) {
if ( V_30 [ V_19 ] -> type == V_17 -> type ) {
struct V_3 * V_10 ;
V_9 = V_30 [ V_19 ] -> F_24 ( V_17 ) ;
if ( F_25 ( V_9 ) ) {
V_29 = F_26 ( V_9 ) ;
goto V_31;
}
V_10 = F_5 ( F_10 ( V_9 -> V_13 ) ,
V_9 -> V_11 -> V_12 ( V_9 ) ) ;
F_27 ( & V_9 -> V_32 , V_10 ) ;
return V_9 ;
}
}
V_29 = - V_33 ;
V_31:
return F_13 ( V_29 ) ;
}
int F_28 ( struct V_9 * V_9 , struct V_34 * V_35 )
{
if ( ! V_9 -> V_11 -> V_36 )
return - V_37 ;
return V_9 -> V_11 -> V_36 ( V_9 , V_35 ) ;
}
void F_29 ( struct V_9 * V_9 )
{
F_30 () ;
F_31 ( & V_9 -> V_32 ) ;
V_9 -> V_11 -> V_38 ( V_9 ) ;
}
void F_32 ( struct V_9 * V_9 , struct V_39 * V_40 )
{
int V_19 ;
memset ( V_40 , 0 , sizeof( * V_40 ) ) ;
F_33 ( & V_9 -> V_28 ) ;
V_40 -> V_41 = V_9 -> V_42 . V_41 ;
V_40 -> V_43 = V_9 -> V_42 . V_43 ;
V_40 -> V_44 = V_9 -> V_42 . V_44 ;
V_40 -> V_45 = V_9 -> V_42 . V_45 ;
F_34 ( & V_9 -> V_28 ) ;
F_16 (i) {
const struct V_25 * V_24 ;
struct V_25 V_46 ;
unsigned int V_47 ;
V_24 = F_17 ( V_9 -> V_24 , V_19 ) ;
do {
V_47 = F_35 ( & V_24 -> V_27 ) ;
V_46 = * V_24 ;
} while ( F_36 ( & V_24 -> V_27 , V_47 ) );
V_40 -> V_48 += V_46 . V_48 ;
V_40 -> V_49 += V_46 . V_49 ;
V_40 -> V_50 += V_46 . V_50 ;
V_40 -> V_51 += V_46 . V_51 ;
}
}
int F_37 ( const struct V_9 * V_9 , struct V_52 * V_53 )
{
struct V_34 * V_54 ;
int V_29 ;
if ( ! V_9 -> V_11 -> V_55 )
return 0 ;
V_54 = F_38 ( V_53 , V_56 ) ;
if ( ! V_54 )
return - V_57 ;
V_29 = V_9 -> V_11 -> V_55 ( V_9 , V_53 ) ;
if ( V_29 ) {
F_39 ( V_53 , V_54 ) ;
return V_29 ;
}
F_40 ( V_53 , V_54 ) ;
return 0 ;
}
void F_41 ( struct V_9 * V_9 , struct V_52 * V_53 ,
struct V_58 * V_59 )
{
struct V_25 * V_40 ;
V_40 = F_42 ( V_9 -> V_24 ) ;
F_43 ( & V_40 -> V_27 ) ;
V_40 -> V_49 ++ ;
V_40 -> V_48 += V_53 -> V_60 ;
F_44 ( & V_40 -> V_27 ) ;
F_45 ( V_53 ) -> V_59 = V_59 ;
F_46 ( V_9 , V_53 ) ;
}
int F_47 ( struct V_9 * V_9 , struct V_52 * V_53 )
{
int V_61 = V_9 -> V_11 -> V_62 ( V_9 , V_53 ) ;
if ( F_48 ( V_61 > 0 ) ) {
struct V_25 * V_40 ;
V_40 = F_42 ( V_9 -> V_24 ) ;
F_43 ( & V_40 -> V_27 ) ;
V_40 -> V_51 ++ ;
V_40 -> V_50 += V_61 ;
F_44 ( & V_40 -> V_27 ) ;
} else if ( V_61 < 0 ) {
F_49 ( V_9 , V_63 ) ;
F_50 ( V_53 ) ;
} else
F_49 ( V_9 , V_64 ) ;
return V_61 ;
}
void F_49 ( struct V_9 * V_9 , enum V_65 V_66 )
{
F_51 ( & V_9 -> V_28 ) ;
switch ( V_66 ) {
case V_67 :
V_9 -> V_42 . V_45 ++ ;
break;
case V_68 :
V_9 -> V_42 . V_41 ++ ;
break;
case V_64 :
V_9 -> V_42 . V_44 ++ ;
break;
case V_63 :
V_9 -> V_42 . V_43 ++ ;
break;
}
F_52 ( & V_9 -> V_28 ) ;
}
static void F_53 ( struct V_69 * V_70 )
{
struct V_9 * V_9 = F_54 ( V_70 , struct V_9 , V_70 ) ;
F_20 ( V_9 ) ;
}
void F_55 ( struct V_9 * V_9 )
{
if ( ! V_9 )
return;
F_56 ( & V_9 -> V_70 , F_53 ) ;
}
