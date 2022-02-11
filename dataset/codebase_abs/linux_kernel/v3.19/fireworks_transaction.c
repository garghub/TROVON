int F_1 ( struct V_1 * V_2 ,
const void * V_3 , unsigned int V_4 )
{
return F_2 ( V_2 , V_5 ,
V_6 ,
( void * ) V_3 , V_4 , 0 ) ;
}
int F_3 ( struct V_1 * V_2 ,
const void * V_3 , unsigned int V_7 ,
void * V_8 , unsigned int V_9 )
{
struct V_10 V_11 ;
unsigned int V_12 ;
int V_13 ;
V_11 . V_2 = V_2 ;
V_11 . V_14 = V_8 ;
V_11 . V_4 = V_9 ;
V_11 . V_15 = F_4 ( ( (struct V_16 * ) V_3 ) -> V_15 ) + 1 ;
V_11 . V_17 = V_18 ;
F_5 ( & V_11 . V_19 ) ;
F_6 ( & V_20 ) ;
F_7 ( & V_11 . V_21 , & V_22 ) ;
F_8 ( & V_20 ) ;
V_12 = 0 ;
do {
V_13 = F_1 ( V_11 . V_2 , ( void * ) V_3 , V_7 ) ;
if ( V_13 < 0 )
break;
F_9 ( V_11 . V_19 , V_11 . V_17 != V_18 ,
F_10 ( V_23 ) ) ;
if ( V_11 . V_17 == V_24 ) {
V_13 = V_11 . V_4 ;
break;
} else if ( V_11 . V_17 == V_25 ) {
F_11 ( V_26 ) ;
} else if ( ++ V_12 >= V_27 ) {
F_12 ( & V_11 . V_2 -> V_28 , L_1 ) ;
V_13 = - V_29 ;
break;
}
} while ( 1 );
F_6 ( & V_20 ) ;
F_13 ( & V_11 . V_21 ) ;
F_8 ( & V_20 ) ;
return V_13 ;
}
static void
F_14 ( struct V_30 * V_31 , void * V_32 , T_1 V_33 , int * V_34 )
{
T_1 V_35 , V_36 ;
struct V_16 * V_11 ;
F_6 ( & V_31 -> V_37 ) ;
V_11 = (struct V_16 * ) V_32 ;
V_33 = F_15 ( T_1 , F_4 ( V_11 -> V_33 ) * sizeof( V_38 ) , V_33 ) ;
if ( V_31 -> V_39 < V_31 -> V_40 )
V_35 = ( unsigned int ) ( V_31 -> V_40 - V_31 -> V_39 ) ;
else
V_35 = V_41 -
( unsigned int ) ( V_31 -> V_39 - V_31 -> V_40 ) ;
if ( V_35 < V_33 ) {
* V_34 = V_42 ;
goto V_43;
}
while ( V_33 > 0 ) {
V_36 = V_41 -
( unsigned int ) ( V_31 -> V_39 - V_31 -> V_44 ) ;
V_36 = F_15 (unsigned int, length, till_end) ;
memcpy ( V_31 -> V_39 , V_32 , V_36 ) ;
V_31 -> V_39 += V_36 ;
if ( V_31 -> V_39 >= V_31 -> V_44 + V_41 )
V_31 -> V_39 -= V_41 ;
V_33 -= V_36 ;
V_32 += V_36 ;
}
V_31 -> V_45 ++ ;
F_16 ( & V_31 -> V_46 ) ;
* V_34 = V_47 ;
V_43:
F_8 ( & V_31 -> V_37 ) ;
}
static void
F_17 ( struct V_48 * V_49 , int V_50 , int V_51 ,
void * V_32 , T_1 V_33 , int * V_34 )
{
struct V_52 * V_28 ;
struct V_30 * V_31 ;
unsigned int V_53 ;
F_6 ( & V_54 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
V_31 = V_56 [ V_53 ] ;
if ( V_31 == NULL )
continue;
V_28 = F_18 ( V_31 -> V_2 ) ;
if ( ( V_28 -> V_49 != V_49 ) ||
( V_28 -> V_50 != V_50 ) )
continue;
F_19 () ;
if ( V_28 -> V_57 != V_51 )
continue;
break;
}
if ( V_53 == V_55 )
goto V_43;
F_14 ( V_31 , V_32 , V_33 , V_34 ) ;
V_43:
F_8 ( & V_54 ) ;
}
static void
F_20 ( struct V_48 * V_49 , int V_50 , int V_51 ,
void * V_32 , T_1 V_33 , int * V_34 , V_38 V_15 )
{
struct V_52 * V_28 ;
struct V_10 * V_11 ;
unsigned long V_58 ;
F_21 ( & V_20 , V_58 ) ;
F_22 (t, &transaction_queues, list) {
V_28 = F_18 ( V_11 -> V_2 ) ;
if ( ( V_28 -> V_49 != V_49 ) ||
( V_28 -> V_50 != V_50 ) )
continue;
F_19 () ;
if ( V_28 -> V_57 != V_51 )
continue;
if ( ( V_11 -> V_17 == V_18 ) && ( V_11 -> V_15 == V_15 ) ) {
V_11 -> V_17 = V_24 ;
V_11 -> V_4 = F_15 (unsigned int, length, t->size) ;
memcpy ( V_11 -> V_14 , V_32 , V_11 -> V_4 ) ;
F_16 ( & V_11 -> V_19 ) ;
* V_34 = V_47 ;
}
}
F_23 ( & V_20 , V_58 ) ;
}
static void
F_24 ( struct V_48 * V_49 , struct V_59 * V_60 ,
int V_61 , int V_62 , int V_51 ,
int V_50 , unsigned long long V_63 ,
void * V_32 , T_1 V_33 , void * V_64 )
{
int V_34 , V_65 ;
V_38 V_15 ;
V_34 = V_66 ;
if ( V_33 < sizeof( struct V_16 ) ) {
V_34 = V_67 ;
goto V_43;
} else if ( V_63 != V_68 ) {
V_34 = V_69 ;
goto V_43;
}
V_15 = F_4 ( ( (struct V_16 * ) V_32 ) -> V_15 ) ;
if ( V_15 > V_70 + 1 ) {
F_20 ( V_49 , V_50 , V_51 ,
V_32 , V_33 , & V_34 , V_15 ) ;
if ( V_71 )
F_17 ( V_49 , V_50 , V_51 ,
V_32 , V_33 , & V_65 ) ;
} else {
F_17 ( V_49 , V_50 , V_51 ,
V_32 , V_33 , & V_34 ) ;
}
V_43:
F_25 ( V_49 , V_60 , V_34 ) ;
}
void F_26 ( struct V_30 * V_31 )
{
unsigned int V_53 ;
F_6 ( & V_54 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_56 [ V_53 ] != NULL )
continue;
V_56 [ V_53 ] = V_31 ;
break;
}
F_8 ( & V_54 ) ;
}
void F_27 ( struct V_30 * V_31 )
{
unsigned int V_53 ;
F_6 ( & V_54 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ ) {
if ( V_56 [ V_53 ] != V_31 )
continue;
V_56 [ V_53 ] = NULL ;
}
F_8 ( & V_54 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_10 * V_11 ;
F_6 ( & V_20 ) ;
F_22 (t, &transaction_queues, list) {
if ( ( V_11 -> V_2 == V_2 ) &&
( V_11 -> V_17 == V_18 ) ) {
V_11 -> V_17 = V_25 ;
F_16 ( & V_11 -> V_19 ) ;
}
}
F_8 ( & V_20 ) ;
}
int F_29 ( void )
{
static const struct V_72 V_73 = {
. V_74 = V_68 ,
. V_43 = V_68 +
V_75
} ;
return F_30 ( & V_76 ,
& V_73 ) ;
}
void F_31 ( void )
{
F_32 ( ! F_33 ( & V_22 ) ) ;
F_34 ( & V_76 ) ;
}
