static int F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
int V_4 = 0 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 = V_3 -> V_9 ;
struct V_10 * V_11 ;
F_2 ( L_1 , V_3 , V_1 ) ;
V_6 = F_3 ( 1 , V_12 ) ;
if ( ! V_6 ) {
F_4 ( L_2 ) ;
V_4 = - V_13 ;
goto V_14;
}
V_11 = (struct V_10 * ) F_5 ( V_6 , 1 ) ;
V_11 -> V_1 = V_1 ;
F_6 ( & V_8 -> V_15 , V_6 ) ;
V_14:
return V_4 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
F_2 ( L_3 , V_3 ) ;
V_8 = F_8 ( sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_13 ;
F_9 ( & V_8 -> V_15 ) ;
F_9 ( & V_8 -> V_17 ) ;
F_10 ( & V_8 -> V_18 ) ;
V_8 -> V_19 = V_20 ;
V_3 -> V_9 = V_8 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_12 ( & V_8 -> V_17 ) ;
F_12 ( & V_8 -> V_15 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_12 ( & V_8 -> V_17 ) ;
F_12 ( & V_8 -> V_15 ) ;
F_14 ( V_8 -> V_21 ) ;
V_3 -> V_9 = NULL ;
F_15 ( V_8 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = NULL ;
while ( ( V_6 = F_17 ( & V_8 -> V_17 ) ) )
F_6 ( & V_8 -> V_15 , V_6 ) ;
V_8 -> V_19 = V_20 ;
}
static void F_18 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_18 , V_22 ) ;
switch ( V_8 -> V_19 ) {
case V_23 :
F_2 ( L_4 ) ;
case V_24 :
if ( F_1 ( V_25 , V_3 ) < 0 ) {
F_4 ( L_5 ) ;
goto V_14;
}
break;
default:
F_4 ( L_6 , V_8 -> V_19 ) ;
break;
}
F_16 ( V_8 ) ;
V_14:
F_20 ( & V_8 -> V_18 , V_22 ) ;
F_21 ( V_3 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_18 , V_22 ) ;
if ( V_8 -> V_19 != V_20 )
F_4 ( L_7 , V_8 -> V_19 ) ;
if ( F_1 ( V_26 , V_3 ) < 0 ) {
F_4 ( L_8 ) ;
goto V_14;
}
V_8 -> V_19 = V_24 ;
V_14:
F_20 ( & V_8 -> V_18 , V_22 ) ;
F_21 ( V_3 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned long V_22 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_18 , V_22 ) ;
if ( V_8 -> V_19 != V_23 )
F_4 ( L_9 , V_8 -> V_19 ) ;
F_16 ( V_8 ) ;
F_20 ( & V_8 -> V_18 , V_22 ) ;
F_21 ( V_3 ) ;
}
static int F_24 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
unsigned long V_22 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_10 , V_3 , V_6 ) ;
memcpy ( F_25 ( V_6 , 1 ) , & F_26 ( V_6 ) , 1 ) ;
F_19 ( & V_8 -> V_18 , V_22 ) ;
switch ( V_8 -> V_19 ) {
case V_20 :
F_2 ( L_11 ) ;
F_6 ( & V_8 -> V_15 , V_6 ) ;
break;
case V_24 :
F_2 ( L_12 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
if ( F_1 ( V_27 , V_3 ) < 0 ) {
F_4 ( L_13 ) ;
break;
}
V_8 -> V_19 = V_23 ;
break;
case V_23 :
F_2 ( L_14 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
break;
default:
F_4 ( L_15 , V_8 -> V_19 ) ;
F_14 ( V_6 ) ;
break;
}
F_20 ( & V_8 -> V_18 , V_22 ) ;
return 0 ;
}
static inline int F_27 ( struct V_28 * V_29 , struct V_7 * V_8 , int V_30 )
{
int V_31 = F_28 ( V_8 -> V_21 ) ;
F_2 ( L_16 , V_30 , V_31 ) ;
if ( ! V_30 ) {
F_29 ( V_29 , V_8 -> V_21 ) ;
} else if ( V_30 > V_31 ) {
F_4 ( L_17 ) ;
F_14 ( V_8 -> V_21 ) ;
} else {
V_8 -> V_32 = V_33 ;
V_8 -> V_34 = V_30 ;
return V_30 ;
}
V_8 -> V_32 = V_35 ;
V_8 -> V_21 = NULL ;
V_8 -> V_34 = 0 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , const void * V_36 , int V_37 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
const char * V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_30 , type , V_45 ;
F_2 ( L_18 , V_3 , V_37 , V_8 -> V_32 , V_8 -> V_34 ) ;
V_38 = V_36 ;
while ( V_37 ) {
if ( V_8 -> V_34 ) {
V_30 = F_31 (unsigned int, ll->rx_count, count) ;
memcpy ( F_5 ( V_8 -> V_21 , V_30 ) , V_38 , V_30 ) ;
V_8 -> V_34 -= V_30 ; V_37 -= V_30 ; V_38 += V_30 ;
if ( V_8 -> V_34 )
continue;
switch ( V_8 -> V_32 ) {
case V_33 :
F_2 ( L_19 ) ;
F_29 ( V_3 -> V_29 , V_8 -> V_21 ) ;
V_8 -> V_32 = V_35 ;
V_8 -> V_21 = NULL ;
continue;
case V_46 :
V_40 = V_39 ( V_8 -> V_21 ) ;
F_2 ( L_20 , V_40 -> V_47 , V_40 -> V_48 ) ;
F_27 ( V_3 -> V_29 , V_8 , V_40 -> V_48 ) ;
continue;
case V_49 :
V_42 = V_41 ( V_8 -> V_21 ) ;
V_45 = F_32 ( V_42 -> V_45 ) ;
F_2 ( L_21 , V_45 ) ;
F_27 ( V_3 -> V_29 , V_8 , V_45 ) ;
continue;
case V_50 :
V_44 = V_43 ( V_8 -> V_21 ) ;
F_2 ( L_22 , V_44 -> V_45 ) ;
F_27 ( V_3 -> V_29 , V_8 , V_44 -> V_45 ) ;
continue;
}
}
switch ( * V_38 ) {
case V_51 :
F_2 ( L_23 ) ;
V_8 -> V_32 = V_46 ;
V_8 -> V_34 = V_52 ;
type = V_51 ;
break;
case V_53 :
F_2 ( L_24 ) ;
V_8 -> V_32 = V_49 ;
V_8 -> V_34 = V_54 ;
type = V_53 ;
break;
case V_55 :
F_2 ( L_25 ) ;
V_8 -> V_32 = V_50 ;
V_8 -> V_34 = V_56 ;
type = V_55 ;
break;
case V_57 :
F_2 ( L_26 ) ;
F_22 ( V_3 ) ;
V_38 ++ ; V_37 -- ;
continue;
case V_26 :
F_4 ( L_27 , V_8 -> V_19 ) ;
V_38 ++ ; V_37 -- ;
continue;
case V_27 :
F_2 ( L_28 ) ;
F_18 ( V_3 ) ;
V_38 ++ ; V_37 -- ;
continue;
case V_25 :
F_2 ( L_29 ) ;
F_23 ( V_3 ) ;
V_38 ++ ; V_37 -- ;
continue;
default:
F_4 ( L_30 , ( V_58 ) * V_38 ) ;
V_3 -> V_29 -> V_59 . V_60 ++ ;
V_38 ++ ; V_37 -- ;
continue;
}
V_38 ++ ; V_37 -- ;
V_8 -> V_21 = F_3 ( V_61 , V_12 ) ;
if ( ! V_8 -> V_21 ) {
F_4 ( L_31 ) ;
V_8 -> V_32 = V_35 ;
V_8 -> V_34 = 0 ;
return - V_13 ;
}
F_26 ( V_8 -> V_21 ) = type ;
}
return V_37 ;
}
static struct V_5 * F_33 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
return F_17 ( & V_8 -> V_15 ) ;
}
int T_2 F_34 ( void )
{
return F_35 ( & V_62 ) ;
}
int T_3 F_36 ( void )
{
return F_37 ( & V_62 ) ;
}
