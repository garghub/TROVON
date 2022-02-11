static inline int
F_1 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_2 ) ;
}
static inline int
F_3 ( T_1 * V_1 )
{
return ! ( F_1 ( V_1 ) & V_3 ) ;
}
static inline int
F_4 ( T_1 * V_1 )
{
return ! ( F_1 ( V_1 ) & V_4 ) ;
}
static inline int
F_5 ( T_1 * V_1 )
{
return F_2 ( V_1 -> V_5 ) ;
}
static inline void
F_6 ( T_1 * V_1 , unsigned char V_6 )
{
F_7 ( V_6 , V_1 -> V_5 ) ;
}
static T_1 *
F_8 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
T_2 * V_11 ;
if ( V_8 == NULL || V_8 -> V_12 == NULL )
return NULL ;
V_10 = V_8 -> V_12 -> V_10 ;
if ( V_10 == NULL )
return NULL ;
if ( V_10 -> V_13 == NULL )
return NULL ;
V_11 = V_10 -> V_13 ;
return & V_11 -> V_14 . V_1 ;
}
static void F_9 ( T_2 * V_10 )
{
T_1 * V_1 = & V_10 -> V_14 . V_1 ;
T_3 V_15 ;
unsigned long V_16 ;
unsigned char V_17 ;
int V_18 = 256 , V_19 = 1 ;
int V_20 ;
if ( V_1 -> V_21 [ V_1 -> V_22 ] == NULL ) {
goto V_23;
}
while ( V_18 > 0 ) {
for ( V_20 = 30000 ; V_20 > 0 ; V_20 -- ) {
if ( F_4 ( V_1 ) )
break;
}
F_10 ( & V_1 -> V_24 , V_16 ) ;
if ( ( V_1 -> V_25 [ V_1 -> V_22 ] & V_26 ) == 0 ) {
F_11 ( & V_1 -> V_24 , V_16 ) ;
goto V_23;
}
if ( F_4 ( V_1 ) ) {
if ( F_12 ( V_1 -> V_21 [ V_1 -> V_22 ] , & V_17 , 1 ) == 1 ) {
if ( ! V_1 -> V_27 ||
( V_17 != V_28 &&
V_17 != V_29 ) )
F_6 ( V_1 , V_17 ) ;
V_18 -- ;
} else {
if ( V_1 -> V_30 ) {
if ( -- V_1 -> V_30 <= 0 )
F_13 ( & V_1 -> V_31 ) ;
}
V_1 -> V_25 [ V_1 -> V_22 ] &= ~ V_32 ;
F_11 ( & V_1 -> V_24 , V_16 ) ;
goto V_23;
}
} else {
F_11 ( & V_1 -> V_24 , V_16 ) ;
return;
}
F_11 ( & V_1 -> V_24 , V_16 ) ;
}
V_23:
if ( V_1 -> V_21 [ ! V_1 -> V_22 ] == NULL ) {
return;
}
while ( V_18 > 0 ) {
for ( V_20 = 30000 ; V_20 > 0 ; V_20 -- ) {
if ( F_4 ( V_1 ) )
break;
}
F_10 ( & V_1 -> V_24 , V_16 ) ;
if ( ! V_1 -> V_27 )
V_19 = 0 ;
V_15 = V_1 -> V_22 ^ V_19 ;
V_19 = 0 ;
if ( ( V_1 -> V_25 [ V_15 ] & V_26 ) == 0 ) {
F_11 ( & V_1 -> V_24 , V_16 ) ;
return;
}
if ( F_14 ( V_1 -> V_21 [ V_15 ] ) )
goto V_33;
if ( F_4 ( V_1 ) ) {
if ( V_15 != V_1 -> V_22 ) {
F_6 ( V_1 , V_15 == V_34 ?
V_28 :
V_29 ) ;
V_1 -> V_22 = V_15 ;
} else if ( F_12 ( V_1 -> V_21 [ V_15 ] , & V_17 , 1 ) == 1 ) {
if ( ! V_1 -> V_27 ||
( V_17 != V_28 &&
V_17 != V_29 ) )
F_6 ( V_1 , V_17 ) ;
V_18 -- ;
} else {
V_33:
if ( V_1 -> V_30 ) {
if ( -- V_1 -> V_30 <= 0 )
F_13 ( & V_1 -> V_31 ) ;
}
V_1 -> V_25 [ V_15 ] &= ~ V_32 ;
F_11 ( & V_1 -> V_24 , V_16 ) ;
return;
}
} else {
F_11 ( & V_1 -> V_24 , V_16 ) ;
return;
}
F_11 ( & V_1 -> V_24 , V_16 ) ;
}
}
static int F_15 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( F_16 ( ! V_8 || ! V_8 -> V_12 ) )
return - V_35 ;
if ( F_16 ( ! V_8 -> V_12 -> V_13 ) )
return - V_35 ;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL )
return - V_36 ;
F_10 ( & V_1 -> V_37 , V_16 ) ;
V_1 -> V_25 [ V_15 ] |= V_38 ;
V_1 -> V_39 [ V_15 ] = V_8 ;
F_11 ( & V_1 -> V_37 , V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( F_16 ( ! V_8 || ! V_8 -> V_12 ) )
return - V_35 ;
if ( F_16 ( ! V_8 -> V_12 -> V_13 ) )
return - V_35 ;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL )
return - V_36 ;
F_10 ( & V_1 -> V_37 , V_16 ) ;
V_1 -> V_25 [ V_15 ] |= V_26 ;
V_1 -> V_21 [ V_15 ] = V_8 ;
F_11 ( & V_1 -> V_37 , V_16 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( F_16 ( ! V_8 || ! V_8 -> V_12 ) )
return - V_35 ;
if ( F_16 ( ! V_8 -> V_12 -> V_13 ) )
return - V_35 ;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL )
return - V_36 ;
F_10 ( & V_1 -> V_37 , V_16 ) ;
V_1 -> V_25 [ V_15 ] &= ~ V_38 ;
F_11 ( & V_1 -> V_37 , V_16 ) ;
return 0 ;
}
static int F_19 ( struct V_7 * V_8 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( F_16 ( ! V_8 || ! V_8 -> V_12 ) )
return - V_35 ;
if ( F_16 ( ! V_8 -> V_12 -> V_13 ) )
return - V_35 ;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL )
return - V_36 ;
F_10 ( & V_1 -> V_37 , V_16 ) ;
V_1 -> V_25 [ V_15 ] &= ~ V_26 ;
F_11 ( & V_1 -> V_37 , V_16 ) ;
return 0 ;
}
static void F_20 ( struct V_7 * V_8 , int V_40 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( V_8 == NULL || V_8 -> V_12 == NULL )
return;
if ( V_8 -> V_12 -> V_13 == NULL )
return;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL ) {
return;
}
F_10 ( & V_1 -> V_24 , V_16 ) ;
if ( V_40 ) {
V_1 -> V_25 [ V_15 ] |= V_41 ;
} else {
V_1 -> V_25 [ V_15 ] &= ~ V_41 ;
}
F_11 ( & V_1 -> V_24 , V_16 ) ;
}
static void F_21 ( unsigned long V_42 )
{
T_2 * V_10 = ( T_2 * ) V_42 ;
T_1 * V_1 = & V_10 -> V_14 . V_1 ;
unsigned long V_16 ;
F_10 ( & V_1 -> V_24 , V_16 ) ;
F_22 ( & V_1 -> V_31 , 1 + V_43 ) ;
F_11 ( & V_1 -> V_24 , V_16 ) ;
F_9 ( V_10 ) ;
}
static void F_23 ( struct V_7 * V_8 , int V_40 )
{
unsigned long V_16 ;
T_1 * V_1 ;
T_3 V_15 ;
if ( V_8 == NULL || V_8 -> V_12 == NULL )
return;
if ( V_8 -> V_12 -> V_13 == NULL )
return;
V_15 = * ( ( T_3 * ) V_8 -> V_12 -> V_13 ) ;
if ( ( V_1 = F_8 ( V_8 ) ) == NULL ) {
return;
}
F_10 ( & V_1 -> V_24 , V_16 ) ;
if ( V_40 ) {
if ( ( V_1 -> V_25 [ V_15 ] & V_32 ) == 0 ) {
if ( ! V_1 -> V_30 ) {
F_24 ( & V_1 -> V_31 ,
F_21 ,
( unsigned long ) V_8 -> V_12 -> V_10 -> V_13 ) ;
F_22 ( & V_1 -> V_31 , 1 + V_43 ) ;
}
V_1 -> V_30 ++ ;
V_1 -> V_25 [ V_15 ] |= V_32 ;
}
} else {
V_1 -> V_25 [ V_15 ] &= ~ V_32 ;
}
F_11 ( & V_1 -> V_24 , V_16 ) ;
if ( V_40 )
F_9 ( ( T_2 * ) V_8 -> V_12 -> V_10 -> V_13 ) ;
}
void
F_25 ( T_2 * V_10 )
{
unsigned long V_16 ;
T_1 * V_1 ;
static struct V_7 * V_8 = NULL ;
static int V_15 = V_44 ;
int V_18 = 128 ;
unsigned char V_6 ;
V_1 = & V_10 -> V_14 . V_1 ;
if ( ! F_3 ( V_1 ) ) {
F_9 ( V_10 ) ;
return;
}
F_10 ( & V_1 -> V_24 , V_16 ) ;
while ( -- V_18 ) {
if ( F_3 ( V_1 ) ) {
V_6 = F_5 ( V_1 ) ;
if ( V_1 -> V_27 ) {
if ( V_6 == V_29 ) {
V_8 = V_1 -> V_39 [ V_44 ] ;
V_15 = V_44 ;
} else if ( V_6 == V_28 ) {
V_8 = V_1 -> V_21 [ V_34 ] ;
V_15 = V_34 ;
}
} else {
V_8 = V_1 -> V_39 [ V_34 ] ;
V_15 = V_34 ;
}
if ( V_8 == NULL ) {
continue;
}
if ( V_1 -> V_25 [ V_15 ] & V_41 ) {
F_26 ( V_8 , & V_6 , 1 ) ;
}
} else {
break;
}
}
F_11 ( & V_1 -> V_24 , V_16 ) ;
F_9 ( V_10 ) ;
}
void
F_27 ( T_2 * V_10 )
{
unsigned long V_16 ;
F_10 ( & V_10 -> V_14 . V_1 . V_24 , V_16 ) ;
V_10 -> V_14 . V_1 . V_27 = 1 ;
V_10 -> V_14 . V_1 . V_22 = V_34 ;
V_10 -> V_14 . V_1 . V_45 = V_34 ;
F_11 ( & V_10 -> V_14 . V_1 . V_24 , V_16 ) ;
}
void
F_28 ( T_2 * V_10 )
{
unsigned long V_16 ;
F_10 ( & V_10 -> V_14 . V_1 . V_24 , V_16 ) ;
V_10 -> V_14 . V_1 . V_27 = 0 ;
F_11 ( & V_10 -> V_14 . V_1 . V_24 , V_16 ) ;
}
int
F_29 ( T_2 * V_10 )
{
int V_46 , V_47 ;
unsigned char V_48 [ 4 ] , V_49 [ 4 ] ;
T_4 * V_50 ;
T_1 * V_1 ;
V_50 = & V_10 -> V_14 ;
V_1 = & V_50 -> V_1 ;
for ( V_47 = 0 ; V_47 < 30000 && ! F_4 ( V_1 ) ; V_47 ++ ) ;
if ( ! F_4 ( V_1 ) ) {
F_30 ( L_1 ) ;
return - 1 ;
}
V_50 -> V_51 = 1 ;
F_7 ( V_52 , V_1 -> V_53 ) ;
for ( V_46 = 0 , V_47 = 50000 ; V_47 > 0 && ! V_46 ; V_47 -- ) {
if ( F_3 ( V_1 ) ) {
if ( F_5 ( V_1 ) == V_54 ) {
V_46 = 1 ;
break;
}
}
}
if ( ! V_46 ) {
F_30 ( L_2 ) ;
V_50 -> V_51 = 0 ;
return - 1 ;
}
if ( F_31 ( V_50 , V_55 , V_48 , V_49 ) ) {
F_30 ( L_3 ) ;
}
if ( F_31 ( V_50 , V_56 , V_48 , V_49 ) ) {
F_30 ( L_4 ) ;
return 0 ;
}
F_27 ( V_10 ) ;
if ( F_31 ( V_50 , V_57 , V_48 , V_49 ) ) {
F_30 ( L_5 ) ;
F_28 ( V_10 ) ;
}
return 0 ;
}
