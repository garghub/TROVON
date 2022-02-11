int F_1 ( struct V_1 V_2 , T_1 * V_3 )
{
if ( V_3 == NULL || V_2 . V_4 == V_5 )
return V_6 ;
if ( V_2 . V_4 == V_7 ) {
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_11 = F_2 ( V_2 ,
V_12 ) ;
if ( ! V_11 )
return V_13 ;
V_9 = F_3 ( V_11 , struct V_8 , V_11 ) ;
* V_3 = V_9 -> V_3 ;
F_4 ( V_11 ) ;
} else if ( V_2 . V_4 == V_14 ) {
return V_6 ;
} else {
* V_3 = F_5 ( V_2 . V_4 ) ;
}
return V_15 ;
}
static struct V_8 * F_6 ( T_1 V_16 )
{
T_1 V_17 = F_7 ( V_16 ) ;
struct V_8 * V_18 ;
F_8 (dbell, &vmci_doorbell_it.entries[bucket],
node) {
if ( V_16 == V_18 -> V_16 )
return V_18 ;
}
return NULL ;
}
static void F_9 ( struct V_8 * V_9 )
{
T_1 V_17 ;
T_1 V_19 ;
F_10 ( & V_9 -> V_11 ) ;
F_11 ( & V_20 . V_21 ) ;
if ( V_22 < V_23 || V_24 < V_23 ) {
if ( V_25 < V_22 &&
! F_6 ( V_25 ) ) {
V_19 = V_25 ;
V_25 = V_23 ;
} else {
bool V_26 = false ;
V_19 = V_27 ;
if ( V_24 + 1 < V_22 ) {
do {
if ( ! F_6
( V_19 ) ) {
V_26 = true ;
break;
}
V_19 = ( V_19 + 1 ) %
V_22 ;
} while ( V_19 !=
V_25 );
}
if ( ! V_26 ) {
V_19 = V_22 ;
V_22 ++ ;
}
}
} else {
V_19 = ( V_27 + 1 ) % V_23 ;
}
V_27 = V_19 ;
V_24 ++ ;
V_9 -> V_16 = V_19 ;
V_17 = F_7 ( V_9 -> V_16 ) ;
F_12 ( & V_9 -> V_28 , & V_20 . V_29 [ V_17 ] ) ;
F_13 ( & V_20 . V_21 ) ;
}
static void F_14 ( struct V_8 * V_9 )
{
F_11 ( & V_20 . V_21 ) ;
F_15 ( & V_9 -> V_28 ) ;
V_24 -- ;
if ( V_9 -> V_16 == V_22 - 1 ) {
while ( V_22 > 0 &&
! F_6 ( V_22 - 1 ) )
V_22 -- ;
}
V_25 = V_9 -> V_16 ;
F_13 ( & V_20 . V_21 ) ;
F_4 ( & V_9 -> V_11 ) ;
}
static int F_16 ( struct V_1 V_2 , T_1 V_30 )
{
struct V_31 V_32 ;
V_32 . V_33 . V_34 = F_17 ( V_14 ,
V_35 ) ;
V_32 . V_33 . V_36 = V_37 ;
V_32 . V_33 . V_38 = sizeof( V_32 ) - V_39 ;
V_32 . V_2 = V_2 ;
V_32 . V_30 = V_30 ;
return F_18 ( & V_32 . V_33 ) ;
}
static int F_19 ( struct V_1 V_2 )
{
struct V_40 V_41 ;
V_41 . V_33 . V_34 = F_17 ( V_14 ,
V_42 ) ;
V_41 . V_33 . V_36 = V_37 ;
V_41 . V_33 . V_38 = sizeof( V_41 ) - V_39 ;
V_41 . V_2 = V_2 ;
return F_18 ( & V_41 . V_33 ) ;
}
static int F_20 ( struct V_1 V_2 , T_1 V_3 )
{
struct V_43 V_44 ;
V_44 . V_33 . V_34 = F_17 ( V_14 ,
V_45 ) ;
V_44 . V_33 . V_36 = V_37 ;
V_44 . V_33 . V_38 = sizeof( V_44 ) - V_39 ;
V_44 . V_2 = V_2 ;
return F_18 ( & V_44 . V_33 ) ;
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_3 ( V_47 ,
struct V_8 , V_47 ) ;
V_9 -> V_48 ( V_9 -> V_49 ) ;
F_4 ( & V_9 -> V_11 ) ;
}
int F_22 ( T_1 V_50 , struct V_1 V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( F_23 ( V_2 ) ) {
F_24 ( L_1 ,
V_2 . V_4 , V_2 . V_11 ) ;
return V_6 ;
}
V_11 = F_2 ( V_2 ,
V_12 ) ;
if ( ! V_11 ) {
F_24 ( L_2 ,
V_2 . V_4 , V_2 . V_11 ) ;
return V_13 ;
}
V_9 = F_3 ( V_11 , struct V_8 , V_11 ) ;
if ( V_9 -> V_51 ) {
F_25 ( & V_9 -> V_47 ) ;
} else {
V_9 -> V_48 ( V_9 -> V_49 ) ;
F_4 ( V_11 ) ;
}
return V_15 ;
}
bool F_26 ( T_1 V_52 )
{
int V_53 ;
struct V_54 V_55 ;
V_55 . V_33 . V_34 = F_17 ( V_14 ,
V_56 ) ;
V_55 . V_33 . V_36 = V_37 ;
V_55 . V_33 . V_38 = sizeof( V_55 ) -
V_39 ;
V_55 . V_52 = V_52 ;
V_53 = F_18 ( & V_55 . V_33 ) ;
if ( V_53 != V_15 ) {
F_24 ( L_3 ,
V_52 , V_53 ) ;
return false ;
}
return true ;
}
static void F_27 ( T_1 V_30 )
{
T_1 V_17 = F_7 ( V_30 ) ;
struct V_8 * V_18 ;
F_11 ( & V_20 . V_21 ) ;
F_8 (dbell, &vmci_doorbell_it.entries[bucket], node) {
if ( V_18 -> V_16 == V_30 &&
F_28 ( & V_18 -> V_57 ) == 1 ) {
if ( V_18 -> V_51 ) {
F_10 ( & V_18 -> V_11 ) ;
F_25 ( & V_18 -> V_47 ) ;
} else {
V_18 -> V_48 ( V_18 -> V_49 ) ;
}
}
}
F_13 ( & V_20 . V_21 ) ;
}
void F_29 ( T_2 * V_58 )
{
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
if ( V_58 [ V_16 ] & 0x1 ) {
V_58 [ V_16 ] &= ~ 1 ;
F_27 ( V_16 ) ;
}
}
}
int F_30 ( struct V_1 * V_2 ,
T_1 V_59 ,
T_1 V_3 ,
T_3 V_48 , void * V_49 )
{
struct V_8 * V_9 ;
struct V_1 V_60 ;
int V_53 ;
if ( ! V_2 || ! V_48 || V_59 & ~ V_61 ||
V_3 & ~ V_62 )
return V_6 ;
V_9 = F_31 ( sizeof( * V_9 ) , V_63 ) ;
if ( V_9 == NULL ) {
F_32 ( L_4 ) ;
return V_64 ;
}
if ( F_23 ( * V_2 ) ) {
T_1 V_65 = F_33 () ;
V_60 = F_17 ( V_65 , V_5 ) ;
} else {
bool V_66 = false ;
if ( V_2 -> V_4 == V_7 ||
( F_34 () &&
F_33 () == V_2 -> V_4 ) ) {
V_66 = true ;
}
if ( ! V_66 || V_2 -> V_11 == V_5 ) {
F_24 ( L_5 ,
V_2 -> V_4 , V_2 -> V_11 ) ;
V_53 = V_6 ;
goto V_67;
}
V_60 = * V_2 ;
}
V_9 -> V_16 = 0 ;
F_35 ( & V_9 -> V_28 ) ;
V_9 -> V_3 = V_3 ;
F_36 ( & V_9 -> V_47 , F_21 ) ;
V_9 -> V_51 = V_59 & V_61 ;
V_9 -> V_48 = V_48 ;
V_9 -> V_49 = V_49 ;
F_37 ( & V_9 -> V_57 , 0 ) ;
V_53 = F_38 ( & V_9 -> V_11 ,
V_12 ,
V_60 ) ;
if ( V_53 != V_15 ) {
F_32 ( L_6 ,
V_60 . V_4 , V_60 . V_11 , V_53 ) ;
goto V_67;
}
V_60 = F_39 ( & V_9 -> V_11 ) ;
if ( F_34 () ) {
F_9 ( V_9 ) ;
V_53 = F_16 ( V_60 , V_9 -> V_16 ) ;
if ( V_15 != V_53 )
goto V_68;
F_37 ( & V_9 -> V_57 , 1 ) ;
}
* V_2 = V_60 ;
return V_53 ;
V_68:
F_14 ( V_9 ) ;
F_40 ( & V_9 -> V_11 ) ;
V_67:
F_41 ( V_9 ) ;
return V_53 ;
}
int F_42 ( struct V_1 V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
if ( F_23 ( V_2 ) )
return V_6 ;
V_11 = F_2 ( V_2 ,
V_12 ) ;
if ( ! V_11 ) {
F_24 ( L_7 ,
V_2 . V_4 , V_2 . V_11 ) ;
return V_13 ;
}
V_9 = F_3 ( V_11 , struct V_8 , V_11 ) ;
if ( F_34 () ) {
int V_53 ;
F_14 ( V_9 ) ;
V_53 = F_19 ( V_2 ) ;
if ( V_15 != V_53 ) {
F_24 ( L_8 ,
V_2 . V_4 , V_2 . V_11 , V_53 ) ;
}
}
F_4 ( & V_9 -> V_11 ) ;
F_40 ( & V_9 -> V_11 ) ;
F_41 ( V_9 ) ;
return V_15 ;
}
int F_43 ( struct V_1 V_34 , T_1 V_3 )
{
int V_69 ;
enum V_70 V_71 ;
struct V_1 V_36 ;
if ( F_23 ( V_34 ) ||
( V_3 & ~ V_62 ) )
return V_6 ;
V_36 = V_72 ;
V_69 = V_70 ( & V_36 , & V_34 , false , & V_71 ) ;
if ( V_69 < V_15 )
return V_69 ;
if ( V_73 == V_71 )
return F_44 ( V_7 ,
V_34 , V_3 ) ;
if ( V_74 == V_71 )
return F_20 ( V_34 , V_3 ) ;
F_32 ( L_9 , V_71 ) ;
return V_75 ;
}
