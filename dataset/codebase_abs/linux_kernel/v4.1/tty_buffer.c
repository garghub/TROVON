static inline void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 , V_4 ;
for ( V_3 = F_2 ( V_2 -> V_3 ) ;
F_3 ( V_5 , & V_3 ) ;
) {
V_4 = V_3 ;
F_4 ( V_6 , & V_3 ) ;
V_3 = F_5 ( & V_2 -> V_3 , V_4 , V_3 ) ;
if ( V_4 == V_3 ) {
F_6 ( & V_2 -> V_7 ) ;
break;
}
}
}
void F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
F_8 ( & V_11 -> V_12 ) ;
F_9 ( & V_11 -> V_13 ) ;
}
void F_10 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
int V_14 ;
V_14 = V_11 -> V_15 -> V_16 != V_11 -> V_15 -> V_17 ;
F_11 ( & V_11 -> V_12 ) ;
F_12 ( & V_11 -> V_13 ) ;
if ( V_14 )
F_13 ( V_18 , & V_11 -> V_19 ) ;
}
int F_14 ( struct V_8 * V_9 )
{
int V_20 = V_9 -> V_11 . V_21 - F_15 ( & V_9 -> V_11 . V_22 ) ;
return F_16 ( V_20 , 0 ) ;
}
static void F_17 ( struct V_23 * V_24 , T_1 V_25 )
{
V_24 -> V_26 = 0 ;
V_24 -> V_25 = V_25 ;
V_24 -> V_27 = NULL ;
V_24 -> V_16 = 0 ;
V_24 -> V_17 = 0 ;
V_24 -> V_3 = 0 ;
}
void F_18 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_23 * V_24 , * V_27 ;
struct V_28 * V_29 ;
while ( ( V_24 = V_11 -> V_15 ) != NULL ) {
V_11 -> V_15 = V_24 -> V_27 ;
if ( V_24 -> V_25 > 0 )
F_19 ( V_24 ) ;
}
V_29 = F_20 ( & V_11 -> free ) ;
F_21 (p, next, llist, free)
F_19 ( V_24 ) ;
F_17 ( & V_11 -> V_30 , 0 ) ;
V_11 -> V_15 = & V_11 -> V_30 ;
V_11 -> V_31 = & V_11 -> V_30 ;
F_22 ( & V_11 -> V_22 , 0 ) ;
}
static struct V_23 * F_23 ( struct V_8 * V_9 , T_1 V_25 )
{
struct V_28 * free ;
struct V_23 * V_24 ;
V_25 = F_24 ( V_25 , V_32 ) ;
if ( V_25 <= V_33 ) {
free = F_25 ( & V_9 -> V_11 . free ) ;
if ( free ) {
V_24 = F_26 ( free , struct V_23 , free ) ;
goto V_34;
}
}
if ( F_15 ( & V_9 -> V_11 . V_22 ) > V_9 -> V_11 . V_21 )
return NULL ;
V_24 = F_27 ( sizeof( struct V_23 ) + 2 * V_25 , V_35 ) ;
if ( V_24 == NULL )
return NULL ;
V_34:
F_17 ( V_24 , V_25 ) ;
F_28 ( V_25 , & V_9 -> V_11 . V_22 ) ;
return V_24 ;
}
static void F_29 ( struct V_8 * V_9 , struct V_23 * V_36 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
F_30 ( F_31 ( V_36 -> V_25 , & V_11 -> V_22 ) < 0 ) ;
if ( V_36 -> V_25 > V_33 )
F_19 ( V_36 ) ;
else if ( V_36 -> V_25 > 0 )
F_32 ( & V_36 -> free , & V_11 -> free ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_23 * V_27 ;
F_8 ( & V_11 -> V_12 ) ;
F_9 ( & V_11 -> V_13 ) ;
while ( ( V_27 = V_11 -> V_15 -> V_27 ) != NULL ) {
F_29 ( V_9 , V_11 -> V_15 ) ;
V_11 -> V_15 = V_27 ;
}
V_11 -> V_15 -> V_17 = V_11 -> V_15 -> V_16 ;
if ( V_38 && V_38 -> V_39 -> V_40 )
V_38 -> V_39 -> V_40 ( V_2 ) ;
F_1 ( V_2 ) ;
F_11 ( & V_11 -> V_12 ) ;
F_12 ( & V_11 -> V_13 ) ;
}
static int F_34 ( struct V_8 * V_9 , T_1 V_25 ,
int V_3 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_23 * V_36 , * V_41 ;
int V_42 , V_43 ;
V_36 = V_11 -> V_31 ;
if ( V_36 -> V_3 & V_44 )
V_42 = 2 * V_36 -> V_25 - V_36 -> V_26 ;
else
V_42 = V_36 -> V_25 - V_36 -> V_26 ;
V_43 = ( V_36 -> V_3 & V_44 ) && ( ~ V_3 & V_44 ) ;
if ( V_43 || V_42 < V_25 ) {
if ( ( V_41 = F_23 ( V_9 , V_25 ) ) != NULL ) {
V_41 -> V_3 = V_3 ;
V_11 -> V_31 = V_41 ;
V_36 -> V_16 = V_36 -> V_26 ;
F_35 () ;
V_36 -> V_27 = V_41 ;
} else if ( V_43 )
V_25 = 0 ;
else
V_25 = V_42 ;
}
return V_25 ;
}
int F_36 ( struct V_8 * V_9 , T_1 V_25 )
{
return F_34 ( V_9 , V_25 , 0 ) ;
}
int F_37 ( struct V_8 * V_9 ,
const unsigned char * V_45 , char V_46 , T_1 V_25 )
{
int V_47 = 0 ;
do {
int V_48 = F_38 ( T_1 , V_25 - V_47 , V_49 ) ;
int V_3 = ( V_46 == V_50 ) ? V_44 : 0 ;
int V_20 = F_34 ( V_9 , V_48 , V_3 ) ;
struct V_23 * V_51 = V_9 -> V_11 . V_31 ;
if ( F_39 ( V_20 == 0 ) )
break;
memcpy ( F_40 ( V_51 , V_51 -> V_26 ) , V_45 , V_20 ) ;
if ( ~ V_51 -> V_3 & V_44 )
memset ( F_41 ( V_51 , V_51 -> V_26 ) , V_46 , V_20 ) ;
V_51 -> V_26 += V_20 ;
V_47 += V_20 ;
V_45 += V_20 ;
} while ( F_39 ( V_25 > V_47 ) );
return V_47 ;
}
int F_42 ( struct V_8 * V_9 ,
const unsigned char * V_45 , const char * V_3 , T_1 V_25 )
{
int V_47 = 0 ;
do {
int V_48 = F_38 ( T_1 , V_25 - V_47 , V_49 ) ;
int V_20 = F_36 ( V_9 , V_48 ) ;
struct V_23 * V_51 = V_9 -> V_11 . V_31 ;
if ( F_39 ( V_20 == 0 ) )
break;
memcpy ( F_40 ( V_51 , V_51 -> V_26 ) , V_45 , V_20 ) ;
memcpy ( F_41 ( V_51 , V_51 -> V_26 ) , V_3 , V_20 ) ;
V_51 -> V_26 += V_20 ;
V_47 += V_20 ;
V_45 += V_20 ;
V_3 += V_20 ;
} while ( F_39 ( V_25 > V_47 ) );
return V_47 ;
}
void F_43 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
V_11 -> V_31 -> V_16 = V_11 -> V_31 -> V_26 ;
F_44 ( & V_11 -> V_19 ) ;
}
int F_45 ( struct V_8 * V_9 , unsigned char * * V_45 ,
T_1 V_25 )
{
int V_20 = F_34 ( V_9 , V_25 , V_44 ) ;
if ( F_46 ( V_20 ) ) {
struct V_23 * V_51 = V_9 -> V_11 . V_31 ;
* V_45 = F_40 ( V_51 , V_51 -> V_26 ) ;
if ( ~ V_51 -> V_3 & V_44 )
memset ( F_41 ( V_51 , V_51 -> V_26 ) , V_50 , V_20 ) ;
V_51 -> V_26 += V_20 ;
}
return V_20 ;
}
static int
F_47 ( struct V_1 * V_2 , struct V_23 * V_15 , int V_52 )
{
struct V_37 * V_53 = V_2 -> V_54 ;
unsigned char * V_24 = F_40 ( V_15 , V_15 -> V_17 ) ;
char * V_55 = NULL ;
if ( ~ V_15 -> V_3 & V_44 )
V_55 = F_41 ( V_15 , V_15 -> V_17 ) ;
if ( V_53 -> V_39 -> V_56 )
V_52 = V_53 -> V_39 -> V_56 ( V_2 , V_24 , V_55 , V_52 ) ;
else {
V_52 = F_38 ( int , V_52 , V_2 -> V_57 ) ;
if ( V_52 )
V_53 -> V_39 -> F_47 ( V_2 , V_24 , V_55 , V_52 ) ;
}
V_15 -> V_17 += V_52 ;
return V_52 ;
}
static void F_48 ( struct V_58 * V_19 )
{
struct V_8 * V_9 = F_49 ( V_19 , struct V_8 , V_11 . V_19 ) ;
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_1 * V_2 ;
struct V_37 * V_53 ;
V_2 = V_9 -> V_59 ;
if ( V_2 == NULL )
return;
V_53 = F_50 ( V_2 ) ;
if ( V_53 == NULL )
return;
F_9 ( & V_11 -> V_13 ) ;
while ( 1 ) {
struct V_23 * V_15 = V_11 -> V_15 ;
struct V_23 * V_27 ;
int V_52 ;
if ( F_15 ( & V_11 -> V_12 ) )
break;
V_27 = V_15 -> V_27 ;
F_51 () ;
V_52 = V_15 -> V_16 - V_15 -> V_17 ;
if ( ! V_52 ) {
if ( V_27 == NULL ) {
F_1 ( V_2 ) ;
break;
}
V_11 -> V_15 = V_27 ;
F_29 ( V_9 , V_15 ) ;
continue;
}
V_52 = F_47 ( V_2 , V_15 , V_52 ) ;
if ( ! V_52 )
break;
}
F_12 ( & V_11 -> V_13 ) ;
F_52 ( V_53 ) ;
}
void F_53 ( struct V_8 * V_9 )
{
F_43 ( V_9 ) ;
}
void F_54 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 ;
F_55 ( & V_11 -> V_13 ) ;
F_17 ( & V_11 -> V_30 , 0 ) ;
V_11 -> V_15 = & V_11 -> V_30 ;
V_11 -> V_31 = & V_11 -> V_30 ;
F_56 ( & V_11 -> free ) ;
F_22 ( & V_11 -> V_22 , 0 ) ;
F_22 ( & V_11 -> V_12 , 0 ) ;
F_57 ( & V_11 -> V_19 , F_48 ) ;
V_11 -> V_21 = V_60 ;
}
int F_58 ( struct V_8 * V_9 , int V_61 )
{
if ( V_61 < V_33 )
return - V_62 ;
V_9 -> V_11 . V_21 = V_61 ;
return 0 ;
}
void F_59 ( struct V_8 * V_9 )
{
F_60 ( & V_9 -> V_11 . V_13 , V_63 ) ;
}
