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
V_39:
for ( V_33 = 0 ; V_33 < V_31 ; V_33 ++ )
F_13 ( V_29 [ V_33 ] ) ;
F_14 ( V_29 ) ;
V_38:
F_14 ( V_27 ) ;
F_2 ( L_4 , V_4 , V_17 ) ;
return V_17 ;
}
static struct V_11 *
F_15 ( struct V_20 * V_21 ,
const struct V_1 * V_2 , long V_16 )
{
struct V_11 * V_17 ;
F_16 () ;
V_17 = F_4 ( V_21 -> V_36 , V_21 -> V_14 , V_2 ,
V_16 ) ;
if ( V_17 != NULL )
F_17 ( & V_17 -> V_19 ) ;
F_18 () ;
return V_17 ;
}
struct V_11 *
F_19 ( struct V_20 * V_21 ,
const struct V_1 * V_2 , struct V_23 * V_24 ,
T_2 V_47 )
{
long V_16 = F_3 ( V_2 ) ;
struct V_11 * V_17 , * V_48 ;
V_17 = F_15 ( V_21 , V_2 , V_16 ) ;
if ( V_17 )
return V_17 ;
V_48 = F_7 ( V_21 , V_2 , V_24 , V_47 ) ;
if ( ! V_48 )
return V_48 ;
F_20 ( & V_49 ) ;
V_17 = F_15 ( V_21 , V_2 , V_16 ) ;
if ( V_17 ) {
F_21 ( & V_49 ) ;
V_21 -> V_36 -> V_50 ( V_48 ) ;
return V_17 ;
}
F_22 ( & V_48 -> V_51 , & V_52 [ V_16 ] ) ;
F_17 ( & V_48 -> V_19 ) ;
F_21 ( & V_49 ) ;
return V_48 ;
}
void
F_23 ( const struct V_12 * V_13 ,
const struct V_14 * V_15 , const struct V_1 * V_2 )
{
struct V_11 * V_17 ;
F_20 ( & V_49 ) ;
F_16 () ;
V_17 = F_4 ( V_13 , V_15 , V_2 , F_3 ( V_2 ) ) ;
F_18 () ;
if ( ! V_17 ) {
F_21 ( & V_49 ) ;
return;
}
F_24 ( & V_17 -> V_51 ) ;
F_21 ( & V_49 ) ;
F_25 () ;
if ( F_26 ( & V_17 -> V_19 ) )
V_17 -> V_13 -> V_50 ( V_17 ) ;
}
void
F_27 ( struct V_11 * V_17 , struct V_20 * V_21 ,
const struct V_1 * V_2 )
{
F_28 ( & V_17 -> V_51 ) ;
F_28 ( & V_17 -> V_53 ) ;
V_17 -> V_13 = V_21 -> V_36 ;
V_17 -> V_14 = V_21 -> V_14 ;
V_17 -> V_54 = 0 ;
V_17 -> V_18 = * V_2 ;
F_29 ( & V_17 -> V_19 , 1 ) ;
}
bool
F_30 ( struct V_11 * V_17 )
{
if ( ! F_26 ( & V_17 -> V_19 ) )
return false ;
V_17 -> V_13 -> V_50 ( V_17 ) ;
return true ;
}
void
F_31 ( struct V_11 * V_51 )
{
V_51 -> V_55 = V_56 ;
F_32 ( V_57 , & V_51 -> V_54 ) ;
}
bool
F_33 ( struct V_11 * V_51 )
{
if ( F_34 ( V_57 , & V_51 -> V_54 ) ) {
unsigned long V_58 , V_59 ;
V_59 = V_56 ;
V_58 = V_59 - V_60 ;
if ( F_35 ( V_51 -> V_55 , V_58 , V_59 ) )
return true ;
F_36 ( V_57 , & V_51 -> V_54 ) ;
}
return false ;
}
static void
F_37 ( const struct V_14 * V_15 , long V_16 )
{
struct V_11 * V_17 ;
F_38 ( V_61 ) ;
F_20 ( & V_49 ) ;
F_16 () ;
F_5 (d, &nfs4_deviceid_cache[hash], node)
if ( V_17 -> V_14 == V_15 && F_6 ( & V_17 -> V_19 ) ) {
F_24 ( & V_17 -> V_51 ) ;
F_39 ( & V_17 -> V_53 , & V_61 ) ;
}
F_18 () ;
F_21 ( & V_49 ) ;
if ( F_40 ( & V_61 ) )
return;
F_25 () ;
while ( ! F_40 ( & V_61 ) ) {
V_17 = F_41 ( V_61 . V_62 , struct V_11 , V_53 ) ;
F_42 ( & V_17 -> V_53 ) ;
if ( F_26 ( & V_17 -> V_19 ) )
V_17 -> V_13 -> V_50 ( V_17 ) ;
}
}
void
F_43 ( const struct V_14 * V_15 )
{
long V_63 ;
if ( ! ( V_15 -> V_64 & V_65 ) )
return;
for ( V_63 = 0 ; V_63 < V_66 ; V_63 ++ )
F_37 ( V_15 , V_63 ) ;
}
void
F_44 ( struct V_14 * V_15 )
{
struct V_11 * V_17 ;
int V_33 ;
F_16 () ;
for ( V_33 = 0 ; V_33 < V_66 ; V_33 ++ ) {
F_5 (d, &nfs4_deviceid_cache[i], node)
if ( V_17 -> V_14 == V_15 )
F_32 ( V_67 , & V_17 -> V_54 ) ;
}
F_18 () ;
}
