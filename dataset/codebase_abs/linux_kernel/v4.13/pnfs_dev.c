void
F_1 ( const struct V_1 * V_2 )
{
T_1 * V_3 = ( T_1 * ) V_2 ;
F_2 ( L_1 , V_4 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
}
static inline T_1
F_3 ( const struct V_1 * V_2 )
{
unsigned char * V_5 = ( unsigned char * ) V_2 -> V_6 ;
unsigned int V_7 = V_8 ;
T_1 V_9 = 0 ;
while ( V_7 -- ) {
V_9 *= 37 ;
V_9 += * V_5 ++ ;
}
return V_9 & V_10 ;
}
static struct V_11 *
F_4 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 ,
long V_16 )
{
struct V_11 * V_17 ;
F_5 (d, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_13 == V_13 && V_17 -> V_14 == V_15 &&
! memcmp ( & V_17 -> V_18 , V_2 , sizeof( * V_2 ) ) ) {
if ( F_6 ( & V_17 -> V_19 ) )
return V_17 ;
else
continue;
}
return NULL ;
}
static struct V_11 *
F_7 ( struct V_20 * V_21 ,
const struct V_1 * V_22 ,
struct V_23 * V_24 , T_2 V_25 )
{
struct V_11 * V_17 = NULL ;
struct V_26 * V_27 = NULL ;
struct V_28 * * V_29 = NULL ;
T_1 V_30 ;
int V_31 ;
int V_32 , V_33 ;
V_30 = V_21 -> V_14 -> V_34 -> V_35 . V_30 ;
if ( V_21 -> V_36 -> V_37 &&
V_21 -> V_36 -> V_37 < V_30 )
V_30 = V_21 -> V_36 -> V_37 ;
V_31 = F_8 ( 0 , V_30 ) ;
F_2 ( L_2 ,
V_4 , V_21 , V_30 , V_31 ) ;
V_27 = F_9 ( sizeof( * V_27 ) , V_25 ) ;
if ( ! V_27 )
return NULL ;
V_29 = F_10 ( V_31 , sizeof( struct V_28 * ) , V_25 ) ;
if ( ! V_29 )
goto V_38;
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ ) {
V_29 [ V_33 ] = F_11 ( V_25 ) ;
if ( ! V_29 [ V_33 ] )
goto V_39;
}
memcpy ( & V_27 -> V_22 , V_22 , sizeof( * V_22 ) ) ;
V_27 -> V_40 = V_21 -> V_36 -> V_2 ;
V_27 -> V_29 = V_29 ;
V_27 -> V_41 = 0 ;
V_27 -> V_42 = V_30 ;
V_27 -> V_43 = 0 ;
V_27 -> V_44 = V_30 - V_45 ;
V_32 = F_12 ( V_21 , V_27 , V_24 ) ;
F_2 ( L_3 , V_4 , V_32 ) ;
if ( V_32 )
goto V_39;
V_17 = V_21 -> V_36 -> V_46 ( V_21 , V_27 ,
V_25 ) ;
if ( V_17 && V_27 -> V_47 )
F_13 ( V_48 , & V_17 -> V_49 ) ;
V_39:
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
F_14 ( V_29 [ V_33 ] ) ;
F_15 ( V_29 ) ;
V_38:
F_15 ( V_27 ) ;
F_2 ( L_4 , V_4 , V_17 ) ;
return V_17 ;
}
static struct V_11 *
F_16 ( struct V_20 * V_21 ,
const struct V_1 * V_2 , long V_16 )
{
struct V_11 * V_17 ;
F_17 () ;
V_17 = F_4 ( V_21 -> V_36 , V_21 -> V_14 , V_2 ,
V_16 ) ;
if ( V_17 != NULL && ! F_18 ( & V_17 -> V_19 ) )
V_17 = NULL ;
F_19 () ;
return V_17 ;
}
struct V_11 *
F_20 ( struct V_20 * V_21 ,
const struct V_1 * V_2 , struct V_23 * V_24 ,
T_2 V_50 )
{
long V_16 = F_3 ( V_2 ) ;
struct V_11 * V_17 , * V_51 ;
V_17 = F_16 ( V_21 , V_2 , V_16 ) ;
if ( V_17 )
return V_17 ;
V_51 = F_7 ( V_21 , V_2 , V_24 , V_50 ) ;
if ( ! V_51 )
return V_51 ;
F_21 ( & V_52 ) ;
V_17 = F_16 ( V_21 , V_2 , V_16 ) ;
if ( V_17 ) {
F_22 ( & V_52 ) ;
V_21 -> V_36 -> V_53 ( V_51 ) ;
return V_17 ;
}
F_23 ( & V_51 -> V_54 , & V_55 [ V_16 ] ) ;
F_24 ( & V_51 -> V_19 ) ;
F_22 ( & V_52 ) ;
return V_51 ;
}
void
F_25 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
struct V_11 * V_17 ;
F_21 ( & V_52 ) ;
F_17 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
F_19 () ;
if ( ! V_17 ) {
F_22 ( & V_52 ) ;
return;
}
F_26 ( & V_17 -> V_54 ) ;
F_27 ( V_48 , & V_17 -> V_49 ) ;
F_22 ( & V_52 ) ;
F_28 ( V_17 ) ;
}
void
F_29 ( struct V_11 * V_17 , struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
F_30 ( & V_17 -> V_54 ) ;
F_30 ( & V_17 -> V_56 ) ;
V_17 -> V_13 = V_21 -> V_36 ;
V_17 -> V_14 = V_21 -> V_14 ;
V_17 -> V_49 = 0 ;
V_17 -> V_18 = * V_2 ;
F_31 ( & V_17 -> V_19 , 1 ) ;
}
bool
F_28 ( struct V_11 * V_17 )
{
if ( F_32 ( V_48 , & V_17 -> V_49 ) ) {
if ( F_33 ( & V_17 -> V_19 , - 1 , 2 ) )
return false ;
F_25 ( V_17 -> V_13 , V_17 -> V_14 , & V_17 -> V_18 ) ;
}
if ( ! F_34 ( & V_17 -> V_19 ) )
return false ;
V_17 -> V_13 -> V_53 ( V_17 ) ;
return true ;
}
void
F_35 ( struct V_11 * V_54 )
{
V_54 -> V_57 = V_58 ;
F_13 ( V_59 , & V_54 -> V_49 ) ;
}
bool
F_36 ( struct V_11 * V_54 )
{
if ( F_32 ( V_59 , & V_54 -> V_49 ) ) {
unsigned long V_60 , V_61 ;
V_61 = V_58 ;
V_60 = V_61 - V_62 ;
if ( F_37 ( V_54 -> V_57 , V_60 , V_61 ) )
return true ;
F_27 ( V_59 , & V_54 -> V_49 ) ;
}
return false ;
}
static void
F_38 ( const struct V_14 * V_15 , long V_16 )
{
struct V_11 * V_17 ;
F_39 ( V_63 ) ;
F_21 ( & V_52 ) ;
F_17 () ;
F_5 (d, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_14 == V_15 && F_6 ( & V_17 -> V_19 ) ) {
F_26 ( & V_17 -> V_54 ) ;
F_40 ( & V_17 -> V_56 , & V_63 ) ;
F_27 ( V_48 , & V_17 -> V_49 ) ;
}
F_19 () ;
F_22 ( & V_52 ) ;
if ( F_41 ( & V_63 ) )
return;
while ( ! F_41 ( & V_63 ) ) {
V_17 = F_42 ( V_63 . V_64 , struct V_11 , V_56 ) ;
F_43 ( & V_17 -> V_56 ) ;
F_28 ( V_17 ) ;
}
}
void
F_44 ( const struct V_14 * V_15 )
{
long V_65 ;
if ( ! ( V_15 -> V_66 & V_67 ) )
return;
for ( V_65 = 0 ; V_65 < V_68 ; V_65 ++ )
F_38 ( V_15 , V_65 ) ;
}
void
F_45 ( struct V_14 * V_15 )
{
struct V_11 * V_17 ;
int V_33 ;
F_17 () ;
for ( V_33 = 0 ; V_33 < V_68 ; V_33 ++ ) {
F_5 (d, &nfs4_deviceid_cache[i], node)
if ( V_17 -> V_14 == V_15 )
F_13 ( V_69 , & V_17 -> V_49 ) ;
}
F_19 () ;
}
