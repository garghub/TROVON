static char * F_1 ( struct V_1 * V_2 , T_1 V_3 , char * V_4 )
{
T_2 V_5 , * V_6 ;
if ( V_3 >= V_2 -> V_7 . V_8 ) {
F_2 ( V_2 , V_9 , V_3 ) ;
return NULL ;
}
V_6 = ( T_2 * ) V_2 -> V_10 +
( V_3 >> ( V_11 - V_12 ) ) ;
if ( V_3 & 1 )
* V_4 ++ = * V_6 ++ ;
do {
V_5 = * V_6 ++ ;
* V_4 = ( V_5 >> V_13 )
if ( ! ( * V_4 ++ ) )
break;
} while ( ( * V_4 ++ = V_5 & V_14 ) );
return V_4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
char * V_15 , * V_16 , * V_17 ;
T_1 V_18 ;
T_3 V_19 ;
struct V_20 * V_21 ;
V_18 = V_2 -> V_7 . V_22 * V_2 -> V_7 . V_23 ;
V_15 = ( char * ) V_2 -> V_24 -> V_25 ( V_2 -> V_24 , V_18 ) ;
if ( V_15 == NULL ) {
F_2 ( V_2 , V_26 , V_18 ) ;
return;
}
V_2 -> V_15 = V_15 ;
V_16 = V_15 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_7 . V_23 ; V_19 ++ ) {
V_21 = (struct V_20 * ) & V_2 -> V_27 [ V_19 ] ;
V_17 = F_1 ( V_2 , * ( T_1 * ) & V_21 -> V_28 , V_16 ) ;
if ( V_17 == NULL )
break;
V_21 -> V_28 = V_16 ;
V_16 = V_17 ;
}
}
void * F_4 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
struct V_1 * V_2 ;
unsigned * V_33 , V_34 ;
T_1 V_35 ;
#if V_36 <= V_13
T_3 V_19 ;
#endif
if ( ! V_30 || ! V_32 ) {
if ( V_32 != NULL )
F_5 ( V_32 , L_1 ) ;
return NULL ;
}
V_2 = (struct V_1 * )
V_32 -> V_25 ( V_32 , sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_5 ( V_32 , L_2 ) ;
return NULL ;
}
V_33 = ( unsigned * ) V_2 ;
for ( V_34 = sizeof( struct V_1 ) / sizeof( unsigned ) ;
V_34 > 0 ; V_34 -= 1 )
* V_33 ++ = 0 ;
V_2 -> V_37 = V_30 ;
V_2 -> V_24 = V_32 ;
F_6 ( V_2 ) ;
if ( ! V_2 -> V_38 )
F_7 ( V_2 , true ) ;
V_35 = sizeof( struct V_39 ) +
sizeof( struct V_40 ) +
F_8 ( F_9 ( V_2 -> V_7 . V_41 ) ) ;
if ( V_2 -> V_37 -> V_42 ( V_2 -> V_37 , V_35 ) != 0 ) {
F_2 ( V_2 , V_43 , V_35 ) ;
return NULL ;
}
if ( ! V_2 -> V_38 )
F_10 ( V_2 ) ;
if ( V_2 -> V_38 ) {
F_11 ( V_2 ) ;
V_2 = NULL ;
return NULL ;
}
#if V_36 > V_13
F_3 ( V_2 ) ;
#else
for ( V_19 = 0 ; V_19 < V_2 -> V_7 . V_23 ; V_19 ++ ) {
struct V_20 * V_21 =
(struct V_20 * ) & V_2 -> V_27 [ V_19 ] ;
V_21 -> V_28 = V_2 -> V_10 + * ( T_1 * ) & V_21 -> V_28 ;
}
#endif
return V_2 ;
}
int F_12 ( void * V_44 , const char * V_45 ,
const struct V_20 * * const V_46 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
T_3 V_19 ;
V_2 = (struct V_1 * ) V_44 ;
if ( ! V_2 )
return false ;
for ( V_19 = 0 ; V_19 < V_2 -> V_7 . V_23 ; V_19 ++ ) {
V_21 = (struct V_20 * ) & V_2 -> V_27 [ V_19 ] ;
if ( strcmp ( V_45 , V_21 -> V_28 ) == 0 ) {
* V_46 = V_21 ;
return true ;
}
}
return false ;
}
int F_13 ( void * V_44 ,
const struct V_20 * V_46 ,
void * V_47 )
{
struct V_1 * V_2 ;
T_1 V_48 ;
struct V_49 * V_50 = NULL ;
T_4 V_51 ;
struct V_52 V_53 ;
T_4 V_54 ;
T_1 V_55 ;
T_5 * V_56 = ( T_5 * ) V_47 ;
V_2 = (struct V_1 * ) V_44 ;
if ( ! V_2 )
return false ;
V_50 = (struct V_49 * ) V_46 ;
if ( V_50 == NULL )
return false ;
V_48 = F_8 ( F_9 ( ( T_1 ) V_50 -> V_57 ) ) ;
if ( V_2 -> V_37 -> V_42 ( V_2 -> V_37 , V_48 ) != 0 ) {
F_2 ( V_2 , V_43 , V_48 ) ;
return false ;
}
V_51 = V_50 -> V_58 ;
while ( ( V_51 -= 1 ) >= 0 ) {
if ( V_2 -> V_37 -> V_59 ( V_2 -> V_37 , & V_53 ,
V_60 ) != V_60 ) {
F_2 ( V_2 , V_61 , L_3 ) ;
return false ;
}
if ( V_2 -> V_62 )
F_14 ( & V_53 , V_60 , V_2 -> V_62 ) ;
V_54 = F_8 ( F_9 ( V_53 . V_63 ) ) ;
if ( V_54 > F_8 ( V_64 ) ) {
F_2 ( V_2 , V_65 , V_54 ) ;
return false ;
}
if ( V_2 -> V_37 -> V_59
( V_2 -> V_37 , V_56 , V_54 ) != V_54 ) {
F_2 ( V_2 , V_61 , L_3 ) ;
return false ;
}
#if ! F_15 ( V_66 ) || ( V_67 > 16 )
if ( V_2 -> V_62 )
F_14 ( V_56 , V_54 , V_2 -> V_62 ) ;
V_55 = F_16 ( V_56 , V_54 ) ;
#else
if ( V_2 -> V_7 . V_68 !=
F_17 ( F_18 ( V_69 ) ) ) {
F_14 ( V_56 , V_54 ,
F_17 ( V_2 ->
V_7 . V_68 ) ) ;
}
#if V_67 > 8
V_55 = F_19 ( V_56 , V_54 ) ;
#else
V_55 = F_20 ( V_56 , V_54 ) ;
#endif
#endif
V_55 += F_16 ( & V_53 , V_60 ) ;
if ( V_53 . V_70 != 0 ) {
F_2 ( V_2 , V_71 , V_54 ) ;
return false ;
}
if ( ~ V_55 ) {
F_2 ( V_2 , V_72 , L_3 ) ;
return false ;
}
V_56 += V_54 ;
}
return true ;
}
void F_11 ( void * V_44 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_44 ;
if ( ! V_2 )
return;
if ( V_2 -> V_10 )
V_2 -> V_24 -> V_73 ( V_2 -> V_24 ,
V_2 -> V_10 ) ;
if ( V_2 -> V_27 )
V_2 -> V_24 -> V_73 ( V_2 -> V_24 ,
V_2 -> V_27 ) ;
#if V_36 > V_13
if ( V_2 -> V_15 )
V_2 -> V_24 -> V_73 ( V_2 -> V_24 ,
V_2 -> V_15 ) ;
#endif
V_2 -> V_24 -> V_73 ( V_2 -> V_24 , V_2 ) ;
}
