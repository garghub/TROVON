static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return ( ( V_2 -> V_4 + ( V_2 -> V_5 << 2 ) +
( V_2 -> V_6 << 9 ) ) & V_3 ) ;
}
static struct V_7 *
F_2 ( struct V_8 * V_9 , int V_10 ,
struct V_7 * V_11 , struct V_7 * V_12 ,
struct V_1 * V_13 , struct V_14 * V_15 )
{
struct V_7 * V_16 ;
V_16 = F_3 ( V_17 , V_18 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_13 = * V_13 ;
V_16 -> V_15 = * V_15 ;
if ( V_11 ) {
V_16 -> V_19 = V_11 -> V_19 ;
V_11 -> V_19 = V_16 ;
} else {
V_16 -> V_19 = V_9 -> V_20 [ V_10 ] ;
V_9 -> V_20 [ V_10 ] = V_16 ;
}
V_9 -> V_21 ++ ;
return V_16 ;
}
static int F_4 ( struct V_8 * V_9 , struct V_1 * V_13 , struct V_14 * V_15 )
{
int V_10 ;
struct V_7 * V_11 , * V_12 , * V_16 ;
T_1 V_22 = V_13 -> V_22 & ~ ( V_23 | V_24 ) ;
if ( ! V_9 || ! V_9 -> V_20 )
return - V_25 ;
V_10 = F_1 ( V_13 , V_9 -> V_3 ) ;
for ( V_11 = NULL , V_12 = V_9 -> V_20 [ V_10 ] ;
V_12 ;
V_11 = V_12 , V_12 = V_12 -> V_19 ) {
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 == V_12 -> V_13 . V_4 &&
( V_22 & V_12 -> V_13 . V_22 ) )
return - V_26 ;
if ( V_13 -> V_6 < V_12 -> V_13 . V_6 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 < V_12 -> V_13 . V_5 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 < V_12 -> V_13 . V_4 )
break;
}
V_16 = F_2 ( V_9 , V_10 , V_11 , V_12 , V_13 , V_15 ) ;
if ( ! V_16 )
return - V_27 ;
return 0 ;
}
struct V_7 *
F_5 ( struct V_8 * V_9 , struct V_1 * V_13 , struct V_14 * V_15 )
{
int V_10 ;
struct V_7 * V_11 , * V_12 ;
T_1 V_22 = V_13 -> V_22 & ~ ( V_23 | V_24 ) ;
if ( ! V_9 || ! V_9 -> V_20 )
return NULL ;
V_10 = F_1 ( V_13 , V_9 -> V_3 ) ;
for ( V_11 = NULL , V_12 = V_9 -> V_20 [ V_10 ] ;
V_12 ;
V_11 = V_12 , V_12 = V_12 -> V_19 ) {
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 == V_12 -> V_13 . V_4 &&
( V_22 & V_12 -> V_13 . V_22 ) )
break;
if ( V_13 -> V_6 < V_12 -> V_13 . V_6 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 < V_12 -> V_13 . V_5 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 < V_12 -> V_13 . V_4 )
break;
}
return F_2 ( V_9 , V_10 , V_11 , V_12 , V_13 , V_15 ) ;
}
struct V_14 * F_6 ( struct V_8 * V_9 , struct V_1 * V_13 )
{
int V_10 ;
struct V_7 * V_12 ;
T_1 V_22 = V_13 -> V_22 & ~ ( V_23 | V_24 ) ;
if ( ! V_9 || ! V_9 -> V_20 )
return NULL ;
V_10 = F_1 ( V_13 , V_9 -> V_3 ) ;
for ( V_12 = V_9 -> V_20 [ V_10 ] ; V_12 ; V_12 = V_12 -> V_19 ) {
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 == V_12 -> V_13 . V_4 &&
( V_22 & V_12 -> V_13 . V_22 ) )
return & V_12 -> V_15 ;
if ( V_13 -> V_6 < V_12 -> V_13 . V_6 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 < V_12 -> V_13 . V_5 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 < V_12 -> V_13 . V_4 )
break;
}
return NULL ;
}
struct V_7 *
F_7 ( struct V_8 * V_9 , struct V_1 * V_13 )
{
int V_10 ;
struct V_7 * V_12 ;
T_1 V_22 = V_13 -> V_22 & ~ ( V_23 | V_24 ) ;
if ( ! V_9 || ! V_9 -> V_20 )
return NULL ;
V_10 = F_1 ( V_13 , V_9 -> V_3 ) ;
for ( V_12 = V_9 -> V_20 [ V_10 ] ; V_12 ; V_12 = V_12 -> V_19 ) {
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 == V_12 -> V_13 . V_4 &&
( V_22 & V_12 -> V_13 . V_22 ) )
return V_12 ;
if ( V_13 -> V_6 < V_12 -> V_13 . V_6 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 < V_12 -> V_13 . V_5 )
break;
if ( V_13 -> V_6 == V_12 -> V_13 . V_6 &&
V_13 -> V_5 == V_12 -> V_13 . V_5 &&
V_13 -> V_4 < V_12 -> V_13 . V_4 )
break;
}
return NULL ;
}
struct V_7 *
F_8 ( struct V_7 * V_28 , int V_22 )
{
struct V_7 * V_12 ;
if ( ! V_28 )
return NULL ;
V_22 &= ~ ( V_23 | V_24 ) ;
for ( V_12 = V_28 -> V_19 ; V_12 ; V_12 = V_12 -> V_19 ) {
if ( V_28 -> V_13 . V_6 == V_12 -> V_13 . V_6 &&
V_28 -> V_13 . V_5 == V_12 -> V_13 . V_5 &&
V_28 -> V_13 . V_4 == V_12 -> V_13 . V_4 &&
( V_22 & V_12 -> V_13 . V_22 ) )
return V_12 ;
if ( V_28 -> V_13 . V_6 < V_12 -> V_13 . V_6 )
break;
if ( V_28 -> V_13 . V_6 == V_12 -> V_13 . V_6 &&
V_28 -> V_13 . V_5 < V_12 -> V_13 . V_5 )
break;
if ( V_28 -> V_13 . V_6 == V_12 -> V_13 . V_6 &&
V_28 -> V_13 . V_5 == V_12 -> V_13 . V_5 &&
V_28 -> V_13 . V_4 < V_12 -> V_13 . V_4 )
break;
}
return NULL ;
}
void F_9 ( struct V_8 * V_9 )
{
int V_29 ;
struct V_7 * V_12 , * V_30 ;
if ( ! V_9 || ! V_9 -> V_20 )
return;
for ( V_29 = 0 ; V_29 < V_9 -> V_31 ; V_29 ++ ) {
V_12 = V_9 -> V_20 [ V_29 ] ;
while ( V_12 ) {
V_30 = V_12 ;
V_12 = V_12 -> V_19 ;
F_10 ( V_17 , V_30 ) ;
}
V_9 -> V_20 [ V_29 ] = NULL ;
}
F_11 ( V_9 -> V_20 ) ;
V_9 -> V_20 = NULL ;
V_9 -> V_31 = 0 ;
V_9 -> V_3 = 0 ;
}
int F_12 ( struct V_8 * V_9 )
{
V_9 -> V_20 = NULL ;
V_9 -> V_21 = 0 ;
return 0 ;
}
int F_13 ( struct V_8 * V_9 , T_2 V_32 )
{
T_1 V_3 = 0 ;
T_2 V_33 = 0 ;
T_2 V_34 = V_32 ;
T_2 V_31 = 0 ;
if ( V_32 == 0 )
goto V_35;
while ( V_34 ) {
V_34 = V_34 >> 1 ;
V_33 ++ ;
}
if ( V_33 > 2 )
V_33 = V_33 - 2 ;
V_31 = 1 << V_33 ;
if ( V_31 > V_36 )
V_31 = V_36 ;
V_3 = V_31 - 1 ;
V_9 -> V_20 = F_14 ( V_31 , sizeof( * ( V_9 -> V_20 ) ) , V_18 ) ;
if ( ! V_9 -> V_20 )
return - V_27 ;
V_35:
V_9 -> V_21 = 0 ;
V_9 -> V_31 = V_31 ;
V_9 -> V_3 = V_3 ;
F_15 ( V_37 L_1 ,
V_9 -> V_31 , V_32 ) ;
return 0 ;
}
void F_16 ( struct V_8 * V_9 , char * V_38 )
{
int V_29 , V_39 , V_40 , V_41 ;
unsigned long long V_42 ;
struct V_7 * V_12 ;
V_40 = 0 ;
V_41 = 0 ;
V_42 = 0 ;
for ( V_29 = 0 ; V_29 < V_9 -> V_31 ; V_29 ++ ) {
V_12 = V_9 -> V_20 [ V_29 ] ;
if ( V_12 ) {
V_40 ++ ;
V_39 = 0 ;
while ( V_12 ) {
V_39 ++ ;
V_12 = V_12 -> V_19 ;
}
if ( V_39 > V_41 )
V_41 = V_39 ;
V_42 += V_39 * V_39 ;
}
}
F_15 ( V_37 L_2
L_3 ,
V_38 , V_9 -> V_21 , V_40 , V_9 -> V_31 , V_41 ,
V_42 ) ;
}
int F_17 ( struct V_8 * V_43 , void * V_44 , struct V_45 * V_46 ,
int (* F_18)( struct V_8 * V_43 , struct V_1 * V_47 ,
struct V_14 * V_48 , void * V_49 ) ,
void * V_49 )
{
T_3 V_50 [ 4 ] ;
T_1 V_51 ;
T_4 V_52 [ 7 ] ;
T_2 V_53 , V_54 , V_55 , V_56 = V_46 -> V_57 ;
struct V_1 V_13 ;
struct V_14 V_15 ;
int V_29 , V_58 ;
unsigned V_59 ;
memset ( & V_13 , 0 , sizeof( struct V_1 ) ) ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
if ( V_56 < V_60 ) {
V_58 = F_19 ( V_52 , V_44 , sizeof( T_2 ) ) ;
if ( V_58 ) {
F_15 ( V_61 L_4 ) ;
return V_58 ;
}
V_54 = F_20 ( V_52 [ 0 ] ) ;
if ( V_54 > F_21 ( V_52 ) ) {
F_15 ( V_61 L_5 ) ;
return - V_25 ;
}
V_58 = F_19 ( V_52 , V_44 , sizeof( T_2 ) * V_54 ) ;
if ( V_58 ) {
F_15 ( V_61 L_4 ) ;
return V_58 ;
}
V_53 = 0 ;
V_55 = F_20 ( V_52 [ V_53 ++ ] ) ;
V_13 . V_6 = ( T_1 ) V_55 ;
if ( V_13 . V_6 != V_55 ) {
F_15 ( V_61 L_6 ) ;
return - V_25 ;
}
V_55 = F_20 ( V_52 [ V_53 ++ ] ) ;
V_13 . V_5 = ( T_1 ) V_55 ;
if ( V_13 . V_5 != V_55 ) {
F_15 ( V_61 L_7 ) ;
return - V_25 ;
}
V_55 = F_20 ( V_52 [ V_53 ++ ] ) ;
V_13 . V_4 = ( T_1 ) V_55 ;
if ( V_13 . V_4 != V_55 ) {
F_15 ( V_61 L_8 ) ;
return - V_25 ;
}
V_55 = F_20 ( V_52 [ V_53 ++ ] ) ;
V_51 = ( V_55 & V_24 ) ? V_23 : 0 ;
if ( ! ( V_55 & ( V_62 | V_63 ) ) ) {
F_15 ( V_61 L_9 ) ;
return - V_25 ;
}
if ( ( V_55 & V_62 ) &&
( V_55 & V_63 ) ) {
F_15 ( V_61 L_10 ) ;
return - V_25 ;
}
for ( V_29 = 0 ; V_29 < F_21 ( V_64 ) ; V_29 ++ ) {
if ( V_55 & V_64 [ V_29 ] ) {
V_13 . V_22 = V_64 [ V_29 ] | V_51 ;
V_15 . V_65 = F_20 ( V_52 [ V_53 ++ ] ) ;
V_58 = F_18 ( V_43 , & V_13 , & V_15 , V_49 ) ;
if ( V_58 )
return V_58 ;
}
}
if ( V_53 != V_54 ) {
F_15 ( V_61 L_11 , V_54 , V_53 ) ;
return - V_25 ;
}
return 0 ;
}
V_58 = F_19 ( V_50 , V_44 , sizeof( T_1 ) * 4 ) ;
if ( V_58 ) {
F_15 ( V_61 L_4 ) ;
return V_58 ;
}
V_53 = 0 ;
V_13 . V_6 = F_22 ( V_50 [ V_53 ++ ] ) ;
V_13 . V_5 = F_22 ( V_50 [ V_53 ++ ] ) ;
V_13 . V_4 = F_22 ( V_50 [ V_53 ++ ] ) ;
V_13 . V_22 = F_22 ( V_50 [ V_53 ++ ] ) ;
if ( ! F_23 ( V_46 , V_13 . V_6 ) ||
! F_23 ( V_46 , V_13 . V_5 ) ||
! F_24 ( V_46 , V_13 . V_4 ) ) {
F_15 ( V_61 L_12 ) ;
return - V_25 ;
}
V_59 = 0 ;
for ( V_29 = 0 ; V_29 < F_21 ( V_64 ) ; V_29 ++ ) {
if ( V_13 . V_22 & V_64 [ V_29 ] )
V_59 ++ ;
}
if ( ! V_59 || V_59 > 1 ) {
F_15 ( V_61 L_13 ) ;
return - V_25 ;
}
V_58 = F_19 ( V_52 , V_44 , sizeof( T_2 ) ) ;
if ( V_58 ) {
F_15 ( V_61 L_4 ) ;
return V_58 ;
}
V_15 . V_65 = F_20 ( * V_52 ) ;
if ( ( V_13 . V_22 & V_63 ) &&
! F_23 ( V_46 , V_15 . V_65 ) ) {
F_15 ( V_61 L_14 ) ;
return - V_25 ;
}
return F_18 ( V_43 , & V_13 , & V_15 , V_49 ) ;
}
static int F_25 ( struct V_8 * V_43 , struct V_1 * V_47 ,
struct V_14 * V_48 , void * V_49 )
{
return F_4 ( V_43 , V_47 , V_48 ) ;
}
int F_26 ( struct V_8 * V_43 , void * V_44 , struct V_45 * V_46 )
{
int V_58 ;
T_4 V_66 [ 1 ] ;
T_2 V_21 , V_29 ;
V_58 = F_19 ( V_66 , V_44 , sizeof( T_2 ) ) ;
if ( V_58 < 0 ) {
F_15 ( V_61 L_15 ) ;
goto V_67;
}
V_21 = F_20 ( V_66 [ 0 ] ) ;
if ( ! V_21 ) {
F_15 ( V_61 L_16 ) ;
V_58 = - V_25 ;
goto V_67;
}
V_58 = F_13 ( V_43 , V_21 ) ;
if ( V_58 )
goto V_67;
for ( V_29 = 0 ; V_29 < V_21 ; V_29 ++ ) {
V_58 = F_17 ( V_43 , V_44 , V_46 , F_25 , NULL ) ;
if ( V_58 ) {
if ( V_58 == - V_27 )
F_15 ( V_61 L_17 ) ;
else if ( V_58 == - V_26 )
F_15 ( V_61 L_18 ) ;
goto V_67;
}
}
V_58 = 0 ;
V_68:
return V_58 ;
V_67:
F_9 ( V_43 ) ;
goto V_68;
}
int F_27 ( struct V_45 * V_49 , struct V_7 * V_12 , void * V_44 )
{
T_3 V_50 [ 4 ] ;
T_4 V_52 [ 1 ] ;
int V_58 ;
V_50 [ 0 ] = F_28 ( V_12 -> V_13 . V_6 ) ;
V_50 [ 1 ] = F_28 ( V_12 -> V_13 . V_5 ) ;
V_50 [ 2 ] = F_28 ( V_12 -> V_13 . V_4 ) ;
V_50 [ 3 ] = F_28 ( V_12 -> V_13 . V_22 ) ;
V_58 = F_29 ( V_50 , sizeof( T_1 ) , 4 , V_44 ) ;
if ( V_58 )
return V_58 ;
V_52 [ 0 ] = F_30 ( V_12 -> V_15 . V_65 ) ;
V_58 = F_29 ( V_52 , sizeof( T_2 ) , 1 , V_44 ) ;
if ( V_58 )
return V_58 ;
return 0 ;
}
int F_31 ( struct V_45 * V_49 , struct V_8 * V_43 , void * V_44 )
{
unsigned int V_29 ;
int V_58 = 0 ;
struct V_7 * V_12 ;
T_4 V_66 [ 1 ] ;
V_66 [ 0 ] = F_30 ( V_43 -> V_21 ) ;
V_58 = F_29 ( V_66 , sizeof( T_2 ) , 1 , V_44 ) ;
if ( V_58 )
return V_58 ;
for ( V_29 = 0 ; V_29 < V_43 -> V_31 ; V_29 ++ ) {
for ( V_12 = V_43 -> V_20 [ V_29 ] ; V_12 ; V_12 = V_12 -> V_19 ) {
V_58 = F_27 ( V_49 , V_12 , V_44 ) ;
if ( V_58 )
return V_58 ;
}
}
return V_58 ;
}
void F_32 ( void )
{
V_17 = F_33 ( L_19 ,
sizeof( struct V_7 ) ,
0 , V_69 , NULL ) ;
}
void F_34 ( void )
{
F_35 ( V_17 ) ;
}
