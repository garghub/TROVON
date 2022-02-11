static T_1 F_1 ( int V_1 , void * V_2 )
{
if ( F_2 ( V_3 == 0 ) ) {
V_3 = 1 ;
F_3 ( & V_4 ) ;
}
F_4 ( & V_5 ) ;
return V_6 ;
}
static int F_5 ( T_2 V_7 , T_2 V_8 )
{
return ( ( V_8 - V_7 ) <= V_9 ) ;
}
static void * F_6 ( T_2 V_7 ,
T_2 V_8 ,
char * V_10 , T_3 * V_11 )
{
* V_11 = V_9 - F_7 ( V_8 ) ;
if ( ( V_9 - ( V_8 - V_7 ) ) < * V_11 )
* V_11 = V_9 - ( V_8 - V_7 ) ;
return V_10 + F_7 ( V_8 ) ;
}
static const void * F_8 ( T_2 V_7 ,
T_2 V_8 ,
const char * V_10 , T_3 * V_11 )
{
* V_11 = V_9 - F_7 ( V_7 ) ;
if ( ( V_8 - V_7 ) < * V_11 )
* V_11 = V_8 - V_7 ;
return V_10 + F_7 ( V_7 ) ;
}
static int F_9 ( void )
{
struct V_12 * V_13 = V_14 ;
return ( V_13 -> V_15 - V_13 -> V_16 ) != V_9 &&
! F_10 ( & V_17 ) ;
}
static int F_11 ( const void * V_18 , unsigned int V_11 )
{
struct V_12 * V_13 = V_14 ;
T_2 V_7 , V_8 ;
unsigned int V_19 = 0 ;
while ( V_11 != 0 ) {
void * V_20 ;
unsigned int V_21 ;
V_7 = V_13 -> V_16 ;
V_8 = V_13 -> V_15 ;
if ( ! F_5 ( V_7 , V_8 ) ) {
V_13 -> V_16 = V_13 -> V_15 = 0 ;
return - V_22 ;
}
if ( ! F_9 () )
return V_19 ;
F_12 () ;
V_20 = F_6 ( V_7 , V_8 , V_13 -> V_23 , & V_21 ) ;
if ( V_21 == 0 )
continue;
if ( V_21 > V_11 )
V_21 = V_11 ;
memcpy ( V_20 , V_18 , V_21 ) ;
V_18 += V_21 ;
V_11 -= V_21 ;
V_19 += V_21 ;
F_13 () ;
V_13 -> V_15 += V_21 ;
if ( V_8 <= V_13 -> V_16 )
F_14 ( V_24 ) ;
}
return V_19 ;
}
static int F_15 ( void )
{
struct V_12 * V_13 = V_14 ;
return ( V_13 -> V_25 != V_13 -> V_26 ) ;
}
static int F_16 ( void * V_18 , unsigned int V_11 )
{
struct V_12 * V_13 = V_14 ;
T_2 V_7 , V_8 ;
unsigned int V_19 = 0 ;
while ( V_11 != 0 ) {
unsigned int V_21 ;
const char * V_27 ;
V_7 = V_13 -> V_25 ;
V_8 = V_13 -> V_26 ;
if ( V_7 == V_8 )
return V_19 ;
if ( ! F_5 ( V_7 , V_8 ) ) {
V_13 -> V_25 = V_13 -> V_26 = 0 ;
return - V_22 ;
}
V_27 = F_8 ( V_7 , V_8 , V_13 -> V_28 , & V_21 ) ;
if ( V_21 == 0 )
continue;
if ( V_21 > V_11 )
V_21 = V_11 ;
F_17 () ;
memcpy ( V_18 , V_27 , V_21 ) ;
V_18 += V_21 ;
V_11 -= V_21 ;
V_19 += V_21 ;
F_12 () ;
V_13 -> V_25 += V_21 ;
if ( V_13 -> V_26 - V_7 >= V_9 )
F_14 ( V_24 ) ;
}
return V_19 ;
}
static int F_18 ( void )
{
static struct {
struct V_29 V_30 ;
char * V_31 ;
union {
void * V_32 ;
struct V_33 * V_34 ;
};
bool V_35 ;
bool V_36 ;
unsigned int V_37 ;
} V_38 ;
struct V_39 * V_23 ;
int V_40 ;
unsigned int V_11 ;
if ( ! V_38 . V_35 ) {
V_38 . V_35 = true ;
V_38 . V_36 = true ;
V_38 . V_37 = 0 ;
F_19 ( & V_41 ) ;
if ( ! F_15 () ) {
F_20 ( & V_41 ) ;
V_38 . V_35 = false ;
return 0 ;
}
}
if ( V_38 . V_36 ) {
if ( V_38 . V_37 != sizeof( V_38 . V_30 ) ) {
V_40 = F_16 ( ( void * ) & V_38 . V_30 + V_38 . V_37 ,
sizeof( V_38 . V_30 ) - V_38 . V_37 ) ;
if ( V_40 < 0 )
goto V_42;
V_38 . V_37 += V_40 ;
if ( V_38 . V_37 != sizeof( V_38 . V_30 ) )
return 0 ;
if ( V_38 . V_30 . V_11 > V_43 ) {
V_40 = - V_44 ;
goto V_42;
}
}
V_11 = V_38 . V_30 . V_11 + 1 ;
if ( V_38 . V_30 . type == V_45 )
V_11 += sizeof( * V_38 . V_34 ) ;
V_38 . V_32 = F_21 ( V_11 , V_46 | V_47 ) ;
if ( ! V_38 . V_32 )
return - V_48 ;
if ( V_38 . V_30 . type == V_45 )
V_38 . V_31 = V_38 . V_34 -> V_31 ;
else
V_38 . V_31 = V_38 . V_32 ;
V_38 . V_36 = false ;
V_38 . V_37 = 0 ;
}
V_40 = F_16 ( V_38 . V_31 + V_38 . V_37 , V_38 . V_30 . V_11 - V_38 . V_37 ) ;
if ( V_40 < 0 )
goto V_42;
V_38 . V_37 += V_40 ;
if ( V_38 . V_37 != V_38 . V_30 . V_11 )
return 0 ;
V_38 . V_31 [ V_38 . V_30 . V_11 ] = '\0' ;
if ( V_38 . V_30 . type == V_45 ) {
V_38 . V_34 -> V_11 = V_38 . V_30 . V_11 ;
V_40 = F_22 ( V_38 . V_34 ) ;
} else {
V_40 = - V_49 ;
F_19 ( & V_50 ) ;
F_23 (req, &xs_reply_list, list) {
if ( V_23 -> V_30 . V_51 == V_38 . V_30 . V_51 ) {
F_24 ( & V_23 -> V_52 ) ;
V_40 = 0 ;
break;
}
}
F_20 ( & V_50 ) ;
if ( V_40 )
goto V_42;
if ( V_23 -> V_38 == V_53 ) {
V_23 -> V_30 . type = V_38 . V_30 . type ;
V_23 -> V_30 . V_11 = V_38 . V_30 . V_11 ;
V_23 -> V_31 = V_38 . V_31 ;
V_23 -> V_38 = V_54 ;
V_23 -> V_55 ( V_23 ) ;
} else
F_25 ( V_23 ) ;
}
F_20 ( & V_41 ) ;
V_38 . V_35 = false ;
V_38 . V_32 = NULL ;
return V_40 ;
V_42:
F_20 ( & V_41 ) ;
V_38 . V_35 = false ;
F_25 ( V_38 . V_32 ) ;
V_38 . V_32 = NULL ;
return V_40 ;
}
static int F_26 ( void )
{
static struct {
struct V_39 * V_23 ;
int V_56 ;
unsigned int V_57 ;
} V_38 ;
void * V_58 ;
unsigned int V_11 ;
int V_40 = 0 ;
if ( ! F_9 () )
return 0 ;
F_19 ( & V_50 ) ;
if ( ! V_38 . V_23 ) {
V_38 . V_23 = F_27 ( & V_17 ,
struct V_39 , V_52 ) ;
V_38 . V_56 = - 1 ;
V_38 . V_57 = 0 ;
}
if ( V_38 . V_23 -> V_38 == V_59 )
goto V_60;
while ( V_38 . V_56 < V_38 . V_23 -> V_61 ) {
if ( V_38 . V_56 < 0 ) {
V_58 = & V_38 . V_23 -> V_30 ;
V_11 = sizeof( V_38 . V_23 -> V_30 ) ;
} else {
V_58 = V_38 . V_23 -> V_62 [ V_38 . V_56 ] . V_63 ;
V_11 = V_38 . V_23 -> V_62 [ V_38 . V_56 ] . V_64 ;
}
V_40 = F_11 ( V_58 + V_38 . V_57 , V_11 - V_38 . V_57 ) ;
if ( V_40 < 0 )
goto V_60;
V_38 . V_57 += V_40 ;
if ( V_38 . V_57 != V_11 )
goto V_42;
V_38 . V_56 ++ ;
V_38 . V_57 = 0 ;
}
F_24 ( & V_38 . V_23 -> V_52 ) ;
V_38 . V_23 -> V_38 = V_53 ;
F_28 ( & V_38 . V_23 -> V_52 , & V_65 ) ;
V_38 . V_23 = NULL ;
V_42:
F_20 ( & V_50 ) ;
return 0 ;
V_60:
V_38 . V_23 -> V_30 . type = V_66 ;
V_38 . V_23 -> V_40 = V_40 ;
F_24 ( & V_38 . V_23 -> V_52 ) ;
if ( V_38 . V_23 -> V_38 == V_59 )
F_25 ( V_38 . V_23 ) ;
else {
V_38 . V_23 -> V_38 = V_54 ;
F_4 ( & V_38 . V_23 -> V_67 ) ;
}
F_20 ( & V_50 ) ;
V_38 . V_23 = NULL ;
return V_40 ;
}
static int F_29 ( void )
{
return F_15 () || F_9 () ;
}
static int F_30 ( void * V_2 )
{
int V_40 ;
while ( ! F_31 () ) {
if ( F_32 ( V_5 , F_29 () ) )
continue;
V_40 = F_18 () ;
if ( V_40 == - V_48 )
F_33 () ;
else if ( V_40 )
F_34 ( L_1 ,
V_40 ) ;
V_40 = F_26 () ;
if ( V_40 )
F_34 ( L_2 ,
V_40 ) ;
}
V_68 = NULL ;
return 0 ;
}
int F_35 ( void )
{
struct V_12 * V_13 = V_14 ;
if ( V_13 -> V_15 != V_13 -> V_16 )
F_36 ( L_3 ,
V_13 -> V_16 , V_13 -> V_15 ) ;
if ( V_13 -> V_26 != V_13 -> V_25 ) {
F_37 ( L_4 ,
V_13 -> V_25 , V_13 -> V_26 ) ;
if ( ! V_69 )
V_13 -> V_25 = V_13 -> V_26 ;
}
if ( V_70 ) {
F_38 ( V_24 , V_70 ) ;
} else {
int V_40 ;
V_40 = F_39 ( V_24 , F_1 ,
0 , L_5 , & V_5 ) ;
if ( V_40 < 0 ) {
F_36 ( L_6 , V_40 ) ;
return V_40 ;
}
V_70 = V_40 ;
if ( ! V_68 ) {
V_68 = F_40 ( F_30 , NULL ,
L_5 ) ;
if ( F_41 ( V_68 ) )
return F_42 ( V_68 ) ;
}
}
return 0 ;
}
void F_43 ( void )
{
F_44 ( V_70 , & V_5 ) ;
V_70 = 0 ;
}
