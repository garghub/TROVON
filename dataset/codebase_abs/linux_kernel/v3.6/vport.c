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
static struct V_3 * F_5 ( const char * V_6 )
{
unsigned int V_7 = F_6 ( V_6 , strlen ( V_6 ) ) ;
return & V_1 [ V_7 & ( V_2 - 1 ) ] ;
}
struct V_8 * F_7 ( const char * V_6 )
{
struct V_3 * V_9 = F_5 ( V_6 ) ;
struct V_8 * V_8 ;
struct V_10 * V_11 ;
F_8 (vport, node, bucket, hash_node)
if ( ! strcmp ( V_6 , V_8 -> V_12 -> V_13 ( V_8 ) ) )
return V_8 ;
return NULL ;
}
struct V_8 * F_9 ( int V_14 , const struct V_15 * V_12 ,
const struct V_16 * V_17 )
{
struct V_8 * V_8 ;
T_1 V_18 ;
V_18 = sizeof( struct V_8 ) ;
if ( V_14 ) {
V_18 = F_10 ( V_18 , V_19 ) ;
V_18 += V_14 ;
}
V_8 = F_2 ( V_18 , V_4 ) ;
if ( ! V_8 )
return F_11 ( - V_5 ) ;
V_8 -> V_20 = V_17 -> V_20 ;
V_8 -> V_21 = V_17 -> V_21 ;
V_8 -> V_22 = V_17 -> V_22 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_23 = F_12 ( struct V_24 ) ;
if ( ! V_8 -> V_23 ) {
F_4 ( V_8 ) ;
return F_11 ( - V_5 ) ;
}
F_13 ( & V_8 -> V_25 ) ;
return V_8 ;
}
void F_14 ( struct V_8 * V_8 )
{
F_15 ( V_8 -> V_23 ) ;
F_4 ( V_8 ) ;
}
struct V_8 * F_16 ( const struct V_16 * V_17 )
{
struct V_8 * V_8 ;
int V_26 = 0 ;
int V_27 ;
F_17 () ;
for ( V_27 = 0 ; V_27 < F_18 ( V_28 ) ; V_27 ++ ) {
if ( V_28 [ V_27 ] -> type == V_17 -> type ) {
V_8 = V_28 [ V_27 ] -> F_19 ( V_17 ) ;
if ( F_20 ( V_8 ) ) {
V_26 = F_21 ( V_8 ) ;
goto V_29;
}
F_22 ( & V_8 -> V_30 ,
F_5 ( V_8 -> V_12 -> V_13 ( V_8 ) ) ) ;
return V_8 ;
}
}
V_26 = - V_31 ;
V_29:
return F_11 ( V_26 ) ;
}
int F_23 ( struct V_8 * V_8 , struct V_32 * V_33 )
{
F_17 () ;
if ( ! V_8 -> V_12 -> V_34 )
return - V_35 ;
return V_8 -> V_12 -> V_34 ( V_8 , V_33 ) ;
}
void F_24 ( struct V_8 * V_8 )
{
F_17 () ;
F_25 ( & V_8 -> V_30 ) ;
V_8 -> V_12 -> V_36 ( V_8 ) ;
}
void F_26 ( struct V_8 * V_8 , struct V_37 * V_38 )
{
int V_27 ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
F_27 ( & V_8 -> V_25 ) ;
V_38 -> V_39 = V_8 -> V_40 . V_39 ;
V_38 -> V_41 = V_8 -> V_40 . V_41 ;
V_38 -> V_42 = V_8 -> V_40 . V_42 ;
V_38 -> V_43 = V_8 -> V_40 . V_43 ;
F_28 ( & V_8 -> V_25 ) ;
F_29 (i) {
const struct V_24 * V_23 ;
struct V_24 V_44 ;
unsigned int V_45 ;
V_23 = F_30 ( V_8 -> V_23 , V_27 ) ;
do {
V_45 = F_31 ( & V_23 -> V_46 ) ;
V_44 = * V_23 ;
} while ( F_32 ( & V_23 -> V_46 , V_45 ) );
V_38 -> V_47 += V_44 . V_47 ;
V_38 -> V_48 += V_44 . V_48 ;
V_38 -> V_49 += V_44 . V_49 ;
V_38 -> V_50 += V_44 . V_50 ;
}
}
int F_33 ( const struct V_8 * V_8 , struct V_51 * V_52 )
{
struct V_32 * V_53 ;
V_53 = F_34 ( V_52 , V_54 ) ;
if ( ! V_53 )
return - V_55 ;
if ( V_8 -> V_12 -> V_56 ) {
int V_26 = V_8 -> V_12 -> V_56 ( V_8 , V_52 ) ;
if ( V_26 ) {
F_35 ( V_52 , V_53 ) ;
return V_26 ;
}
}
F_36 ( V_52 , V_53 ) ;
return 0 ;
}
void F_37 ( struct V_8 * V_8 , struct V_51 * V_52 )
{
struct V_24 * V_38 ;
V_38 = F_30 ( V_8 -> V_23 , F_38 () ) ;
F_39 ( & V_38 -> V_46 ) ;
V_38 -> V_48 ++ ;
V_38 -> V_47 += V_52 -> V_57 ;
F_40 ( & V_38 -> V_46 ) ;
F_41 ( V_8 , V_52 ) ;
}
int F_42 ( struct V_8 * V_8 , struct V_51 * V_52 )
{
int V_58 = V_8 -> V_12 -> V_59 ( V_8 , V_52 ) ;
if ( F_43 ( V_58 ) ) {
struct V_24 * V_38 ;
V_38 = F_30 ( V_8 -> V_23 , F_38 () ) ;
F_39 ( & V_38 -> V_46 ) ;
V_38 -> V_50 ++ ;
V_38 -> V_49 += V_58 ;
F_40 ( & V_38 -> V_46 ) ;
}
return V_58 ;
}
void F_44 ( struct V_8 * V_8 , enum V_60 V_61 )
{
F_45 ( & V_8 -> V_25 ) ;
switch ( V_61 ) {
case V_62 :
V_8 -> V_40 . V_43 ++ ;
break;
case V_63 :
V_8 -> V_40 . V_39 ++ ;
break;
case V_64 :
V_8 -> V_40 . V_42 ++ ;
break;
case V_65 :
V_8 -> V_40 . V_41 ++ ;
break;
} ;
F_46 ( & V_8 -> V_25 ) ;
}
