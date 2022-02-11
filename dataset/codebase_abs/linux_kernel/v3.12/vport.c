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
V_9 -> V_21 = V_17 -> V_21 ;
V_9 -> V_11 = V_11 ;
F_14 ( & V_9 -> V_22 ) ;
V_9 -> V_23 = F_15 ( struct V_24 ) ;
if ( ! V_9 -> V_23 ) {
F_4 ( V_9 ) ;
return F_13 ( - V_5 ) ;
}
F_16 ( & V_9 -> V_25 ) ;
return V_9 ;
}
void F_17 ( struct V_9 * V_9 )
{
F_18 ( V_9 -> V_23 ) ;
F_4 ( V_9 ) ;
}
struct V_9 * F_19 ( const struct V_16 * V_17 )
{
struct V_9 * V_9 ;
int V_26 = 0 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_20 ( V_28 ) ; V_27 ++ ) {
if ( V_28 [ V_27 ] -> type == V_17 -> type ) {
struct V_3 * V_10 ;
V_9 = V_28 [ V_27 ] -> F_21 ( V_17 ) ;
if ( F_22 ( V_9 ) ) {
V_26 = F_23 ( V_9 ) ;
goto V_29;
}
V_10 = F_5 ( F_10 ( V_9 -> V_13 ) ,
V_9 -> V_11 -> V_12 ( V_9 ) ) ;
F_24 ( & V_9 -> V_30 , V_10 ) ;
return V_9 ;
}
}
V_26 = - V_31 ;
V_29:
return F_13 ( V_26 ) ;
}
int F_25 ( struct V_9 * V_9 , struct V_32 * V_33 )
{
if ( ! V_9 -> V_11 -> V_34 )
return - V_35 ;
return V_9 -> V_11 -> V_34 ( V_9 , V_33 ) ;
}
void F_26 ( struct V_9 * V_9 )
{
F_27 () ;
F_28 ( & V_9 -> V_30 ) ;
V_9 -> V_11 -> V_36 ( V_9 ) ;
}
void F_29 ( struct V_9 * V_9 , struct V_37 * V_38 )
{
int V_27 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
F_30 ( & V_9 -> V_25 ) ;
V_38 -> V_39 = V_9 -> V_40 . V_39 ;
V_38 -> V_41 = V_9 -> V_40 . V_41 ;
V_38 -> V_42 = V_9 -> V_40 . V_42 ;
V_38 -> V_43 = V_9 -> V_40 . V_43 ;
F_31 ( & V_9 -> V_25 ) ;
F_32 (i) {
const struct V_24 * V_23 ;
struct V_24 V_44 ;
unsigned int V_45 ;
V_23 = F_33 ( V_9 -> V_23 , V_27 ) ;
do {
V_45 = F_34 ( & V_23 -> V_46 ) ;
V_44 = * V_23 ;
} while ( F_35 ( & V_23 -> V_46 , V_45 ) );
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
void F_40 ( struct V_9 * V_9 , struct V_51 * V_52 ,
struct V_57 * V_58 )
{
struct V_24 * V_38 ;
V_38 = F_41 ( V_9 -> V_23 ) ;
F_42 ( & V_38 -> V_46 ) ;
V_38 -> V_48 ++ ;
V_38 -> V_47 += V_52 -> V_59 ;
F_43 ( & V_38 -> V_46 ) ;
F_44 ( V_52 ) -> V_58 = V_58 ;
F_45 ( V_9 , V_52 ) ;
}
int F_46 ( struct V_9 * V_9 , struct V_51 * V_52 )
{
int V_60 = V_9 -> V_11 -> V_61 ( V_9 , V_52 ) ;
if ( F_47 ( V_60 > 0 ) ) {
struct V_24 * V_38 ;
V_38 = F_41 ( V_9 -> V_23 ) ;
F_42 ( & V_38 -> V_46 ) ;
V_38 -> V_50 ++ ;
V_38 -> V_49 += V_60 ;
F_43 ( & V_38 -> V_46 ) ;
} else if ( V_60 < 0 ) {
F_48 ( V_9 , V_62 ) ;
F_49 ( V_52 ) ;
} else
F_48 ( V_9 , V_63 ) ;
return V_60 ;
}
void F_48 ( struct V_9 * V_9 , enum V_64 V_65 )
{
F_50 ( & V_9 -> V_25 ) ;
switch ( V_65 ) {
case V_66 :
V_9 -> V_40 . V_43 ++ ;
break;
case V_67 :
V_9 -> V_40 . V_39 ++ ;
break;
case V_63 :
V_9 -> V_40 . V_42 ++ ;
break;
case V_62 :
V_9 -> V_40 . V_41 ++ ;
break;
}
F_51 ( & V_9 -> V_25 ) ;
}
static void F_52 ( struct V_68 * V_69 )
{
struct V_9 * V_9 = F_53 ( V_69 , struct V_9 , V_69 ) ;
F_17 ( V_9 ) ;
}
void F_54 ( struct V_9 * V_9 )
{
if ( ! V_9 )
return;
F_55 ( & V_9 -> V_69 , F_52 ) ;
}
