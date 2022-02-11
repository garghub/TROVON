static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - F_2 ( & V_2 -> V_4 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) >= V_2 -> V_5 ;
}
static int F_4 ( const struct V_6 * V_7 )
{
if ( ( V_7 -> V_8 & V_9 ) != V_10 )
return - V_11 ;
return V_7 -> V_12 . V_13 . V_14 & ~ V_15 ;
}
int F_5 ( const struct V_6 * V_7 ,
T_1 V_16 , void * V_17 )
{
int V_14 , V_18 ;
struct V_19 * V_20 ;
if ( ( V_14 = F_4 ( V_7 ) ) <= 0 )
return V_14 ;
if ( V_7 -> V_12 . V_13 . V_14 & V_21 ) {
char V_22 [ 32 ] ;
char T_2 * V_23 = ( char V_24 T_2 * ) V_7 -> V_12 . V_13 . V_25 ;
while ( V_14 > 0 ) {
int V_26 = sizeof( V_22 ) ;
if ( V_14 < V_26 )
V_26 = V_14 ;
if ( F_6 ( V_22 , V_23 , V_26 ) )
return - V_27 ;
V_18 = V_16 ( V_17 , V_22 , V_26 ) ;
if ( V_18 < 0 )
return V_18 ;
V_23 += V_26 ;
V_14 -= V_26 ;
}
return 0 ;
}
if ( ! ( V_7 -> V_12 . V_13 . V_14 & V_28 ) )
return V_16 ( V_17 , V_7 -> V_12 . V_13 . V_25 , V_14 ) ;
V_20 = (struct V_19 * ) V_7 -> V_12 . V_13 . V_25 ;
for (; V_14 > 0 && V_20 ; V_20 = V_20 -> V_29 ) {
int V_26 = sizeof( struct V_6 ) ;
if ( V_14 < V_26 )
V_26 = V_14 ;
V_18 = V_16 ( V_17 , & V_20 -> V_7 , V_26 ) ;
if ( V_18 < 0 )
return V_18 ;
V_14 -= V_26 ;
}
return 0 ;
}
static int F_7 ( char * * V_30 , const void * V_31 , int V_26 )
{
memcpy ( * V_30 , V_31 , V_26 ) ;
* V_30 += V_26 ;
return 0 ;
}
static int F_8 ( char T_2 * * V_30 , const void * V_31 , int V_26 )
{
if ( F_9 ( * V_30 , V_31 , V_26 ) )
return - V_27 ;
* V_30 += V_26 ;
return 0 ;
}
int F_10 ( const struct V_6 * V_7 , int V_32 , char * V_22 ,
int V_33 , int V_34 )
{
int V_14 , V_35 ;
int V_18 ;
if ( ( V_14 = F_4 ( V_7 ) ) < 0 )
return V_14 ;
V_35 = V_14 ;
if ( V_34 > 0 )
V_35 = F_11 ( V_14 , V_34 ) ;
if ( V_32 < V_35 )
return - V_36 ;
if ( V_7 -> V_12 . V_13 . V_14 & V_21 ) {
if ( ! V_33 )
return - V_11 ;
if ( F_6 ( V_22 , ( void V_24 T_2 * ) V_7 -> V_12 . V_13 . V_25 , V_14 ) )
return - V_27 ;
return V_35 ;
}
V_18 = F_5 ( V_7 ,
V_33 ? ( T_1 ) F_7 :
( T_1 ) F_8 ,
& V_22 ) ;
return V_18 < 0 ? V_18 : V_35 ;
}
static inline void F_12 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
V_20 -> V_29 = V_2 -> free ;
V_2 -> free = V_20 ;
F_13 ( & V_2 -> V_4 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
unsigned long V_8 ;
struct V_1 * V_2 ;
if ( F_15 ( ! V_20 ) )
return;
V_2 = V_20 -> V_2 ;
if ( F_15 ( ! V_2 ) )
return;
F_16 ( & V_2 -> V_37 , V_8 ) ;
F_12 ( V_2 , V_20 ) ;
if ( F_17 ( & V_20 -> V_7 ) ) {
if ( V_20 -> V_7 . V_12 . V_13 . V_14 & V_28 ) {
struct V_19 * V_38 , * V_39 ;
V_38 = V_20 -> V_7 . V_12 . V_13 . V_25 ;
for (; V_38 ; V_38 = V_39 ) {
V_39 = V_38 -> V_29 ;
V_38 -> V_29 = V_2 -> free ;
F_12 ( V_2 , V_38 ) ;
}
}
}
if ( F_18 ( & V_2 -> V_40 ) ) {
if ( F_3 ( V_2 ) )
F_19 ( & V_2 -> V_40 ) ;
}
F_20 ( & V_2 -> V_37 , V_8 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_19 * * V_41 ,
int V_42 , struct V_43 * V_43 )
{
struct V_19 * V_20 ;
unsigned long V_8 ;
int V_18 = - V_36 ;
T_3 V_44 ;
if ( V_2 == NULL )
return - V_11 ;
* V_41 = NULL ;
F_22 ( & V_44 , V_45 ) ;
F_16 ( & V_2 -> V_37 , V_8 ) ;
if ( V_2 -> V_25 == NULL ) {
F_23 ( L_1 ) ;
V_18 = - V_11 ;
goto V_46;
}
while ( V_2 -> free == NULL && ! V_42 && ! V_2 -> V_47 ) {
F_24 ( V_48 ) ;
F_25 ( & V_2 -> V_40 , & V_44 ) ;
F_26 ( & V_2 -> V_37 ) ;
F_27 () ;
F_28 ( & V_2 -> V_37 ) ;
F_29 ( & V_2 -> V_40 , & V_44 ) ;
if ( F_30 ( V_45 ) ) {
V_18 = - V_49 ;
goto V_46;
}
}
if ( V_2 -> V_47 ) {
V_18 = - V_50 ;
goto V_46;
}
V_20 = V_2 -> free ;
if ( V_20 ) {
int V_51 ;
V_2 -> free = V_20 -> V_29 ;
F_31 ( & V_2 -> V_4 ) ;
V_51 = F_2 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_52 < V_51 )
V_2 -> V_52 = V_51 ;
V_2 -> V_53 ++ ;
V_20 -> V_29 = NULL ;
V_18 = 0 ;
} else
V_2 -> V_54 ++ ;
* V_41 = V_20 ;
V_46:
F_20 ( & V_2 -> V_37 , V_8 ) ;
return V_18 ;
}
int F_32 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_19 * * V_41 , int V_42 ,
struct V_43 * V_43 )
{
int V_55 , V_18 ;
unsigned int V_56 ;
struct V_19 * V_20 ;
* V_41 = NULL ;
V_55 = 0 ;
V_56 = 0 ;
if ( F_17 ( V_7 ) ) {
V_56 = V_7 -> V_12 . V_13 . V_14 & ~ V_15 ;
V_55 = ( V_56 + sizeof( struct V_6 ) - 1 ) / sizeof( struct V_6 ) ;
}
if ( V_55 >= V_2 -> V_3 )
return - V_50 ;
V_18 = F_21 ( V_2 , & V_20 , V_42 , V_43 ) ;
if ( V_18 < 0 )
return V_18 ;
V_20 -> V_7 = * V_7 ;
if ( F_17 ( V_7 ) ) {
int V_14 = V_56 ;
int V_57 = V_7 -> V_12 . V_13 . V_14 & V_28 ;
int V_58 = V_7 -> V_12 . V_13 . V_14 & V_21 ;
struct V_19 * V_31 , * V_59 , * V_60 ;
char * V_22 ;
V_20 -> V_7 . V_12 . V_13 . V_14 = V_56 | V_28 ;
V_20 -> V_7 . V_12 . V_13 . V_25 = NULL ;
V_31 = (struct V_19 * ) V_7 -> V_12 . V_13 . V_25 ;
V_22 = ( char * ) V_7 -> V_12 . V_13 . V_25 ;
V_60 = NULL ;
while ( V_55 -- > 0 ) {
int V_26 = sizeof( struct V_6 ) ;
if ( V_14 < V_26 )
V_26 = V_14 ;
V_18 = F_21 ( V_2 , & V_59 , V_42 , V_43 ) ;
if ( V_18 < 0 )
goto V_46;
if ( V_20 -> V_7 . V_12 . V_13 . V_25 == NULL )
V_20 -> V_7 . V_12 . V_13 . V_25 = V_59 ;
if ( V_60 )
V_60 -> V_29 = V_59 ;
V_60 = V_59 ;
if ( V_57 && V_31 ) {
V_59 -> V_7 = V_31 -> V_7 ;
V_31 = V_31 -> V_29 ;
} else if ( V_58 ) {
if ( F_6 ( & V_59 -> V_7 , ( char V_24 T_2 * ) V_22 , V_26 ) ) {
V_18 = - V_27 ;
goto V_46;
}
} else {
memcpy ( & V_59 -> V_7 , V_22 , V_26 ) ;
}
V_22 += V_26 ;
V_14 -= V_26 ;
}
}
* V_41 = V_20 ;
return 0 ;
V_46:
F_14 ( V_20 ) ;
return V_18 ;
}
int F_33 ( struct V_1 * V_2 , struct V_43 * V_43 ,
T_4 * V_44 )
{
F_34 ( V_43 , & V_2 -> V_40 , V_44 ) ;
return F_3 ( V_2 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_20 ;
struct V_19 * V_61 ;
unsigned long V_8 ;
if ( F_15 ( ! V_2 ) )
return - V_11 ;
if ( V_2 -> V_25 )
return 0 ;
V_2 -> V_25 = F_36 ( sizeof( struct V_19 ) * V_2 -> V_26 ) ;
if ( V_2 -> V_25 == NULL ) {
F_23 ( L_2 ) ;
return - V_50 ;
}
F_16 ( & V_2 -> V_37 , V_8 ) ;
V_2 -> free = NULL ;
for ( V_20 = 0 ; V_20 < V_2 -> V_26 ; V_20 ++ ) {
V_61 = V_2 -> V_25 + V_20 ;
V_61 -> V_2 = V_2 ;
V_61 -> V_29 = V_2 -> free ;
V_2 -> free = V_61 ;
}
V_2 -> V_5 = ( V_2 -> V_26 + 1 ) / 2 ;
V_2 -> V_52 = 0 ;
V_2 -> V_3 = V_2 -> V_26 ;
F_20 ( & V_2 -> V_37 , V_8 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
unsigned long V_8 ;
struct V_19 * V_25 ;
int V_62 = 5 * V_63 ;
if ( F_15 ( ! V_2 ) )
return - V_11 ;
F_16 ( & V_2 -> V_37 , V_8 ) ;
V_2 -> V_47 = 1 ;
F_20 ( & V_2 -> V_37 , V_8 ) ;
if ( F_18 ( & V_2 -> V_40 ) )
F_19 ( & V_2 -> V_40 ) ;
while ( F_2 ( & V_2 -> V_4 ) > 0 ) {
if ( V_62 == 0 ) {
F_38 ( L_3 , F_2 ( & V_2 -> V_4 ) ) ;
break;
}
F_39 ( 1 ) ;
V_62 -- ;
}
F_16 ( & V_2 -> V_37 , V_8 ) ;
V_25 = V_2 -> V_25 ;
V_2 -> V_25 = NULL ;
V_2 -> free = NULL ;
V_2 -> V_3 = 0 ;
F_20 ( & V_2 -> V_37 , V_8 ) ;
F_40 ( V_25 ) ;
F_16 ( & V_2 -> V_37 , V_8 ) ;
V_2 -> V_47 = 0 ;
F_20 ( & V_2 -> V_37 , V_8 ) ;
return 0 ;
}
struct V_1 * F_41 ( int V_64 )
{
struct V_1 * V_2 ;
V_2 = F_42 ( sizeof( * V_2 ) , V_65 ) ;
if ( V_2 == NULL ) {
F_23 ( L_4 ) ;
return NULL ;
}
F_43 ( & V_2 -> V_37 ) ;
V_2 -> V_25 = NULL ;
V_2 -> free = NULL ;
V_2 -> V_3 = 0 ;
F_44 ( & V_2 -> V_4 , 0 ) ;
V_2 -> V_47 = 0 ;
F_45 ( & V_2 -> V_40 ) ;
V_2 -> V_26 = V_64 ;
V_2 -> V_52 = 0 ;
return V_2 ;
}
int F_46 ( struct V_1 * * V_66 )
{
struct V_1 * V_2 = * V_66 ;
* V_66 = NULL ;
if ( V_2 == NULL )
return 0 ;
F_37 ( V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int T_5 F_48 ( void )
{
return 0 ;
}
void T_6 F_49 ( void )
{
}
void F_50 ( struct V_67 * V_68 ,
struct V_1 * V_2 , char * V_69 )
{
if ( V_2 == NULL )
return;
F_51 ( V_68 , L_5 , V_69 , V_2 -> V_3 ) ;
F_51 ( V_68 , L_6 , V_69 , F_2 ( & V_2 -> V_4 ) ) ;
F_51 ( V_68 , L_7 , V_69 , V_2 -> V_52 ) ;
F_51 ( V_68 , L_8 , V_69 , V_2 -> V_53 ) ;
F_51 ( V_68 , L_9 , V_69 , V_2 -> V_54 ) ;
}
