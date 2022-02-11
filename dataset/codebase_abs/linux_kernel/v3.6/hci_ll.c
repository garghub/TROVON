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
V_6 -> V_15 = ( void * ) V_3 -> V_16 ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
V_14:
return V_4 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_7 * V_8 ;
F_2 ( L_3 , V_3 ) ;
V_8 = F_8 ( sizeof( * V_8 ) , V_18 ) ;
if ( ! V_8 )
return - V_13 ;
F_9 ( & V_8 -> V_17 ) ;
F_9 ( & V_8 -> V_19 ) ;
F_10 ( & V_8 -> V_20 ) ;
V_8 -> V_21 = V_22 ;
V_3 -> V_9 = V_8 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_12 ( & V_8 -> V_19 ) ;
F_12 ( & V_8 -> V_17 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_12 ( & V_8 -> V_19 ) ;
F_12 ( & V_8 -> V_17 ) ;
F_14 ( V_8 -> V_23 ) ;
V_3 -> V_9 = NULL ;
F_15 ( V_8 ) ;
return 0 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_5 * V_6 = NULL ;
while ( ( V_6 = F_17 ( & V_8 -> V_19 ) ) )
F_6 ( & V_8 -> V_17 , V_6 ) ;
V_8 -> V_21 = V_22 ;
}
static void F_18 ( struct V_2 * V_3 )
{
unsigned long V_24 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_20 , V_24 ) ;
switch ( V_8 -> V_21 ) {
case V_25 :
F_2 ( L_4 ) ;
case V_26 :
if ( F_1 ( V_27 , V_3 ) < 0 ) {
F_4 ( L_5 ) ;
goto V_14;
}
break;
default:
F_4 ( L_6 , V_8 -> V_21 ) ;
break;
}
F_16 ( V_8 ) ;
V_14:
F_20 ( & V_8 -> V_20 , V_24 ) ;
F_21 ( V_3 ) ;
}
static void F_22 ( struct V_2 * V_3 )
{
unsigned long V_24 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_20 , V_24 ) ;
if ( V_8 -> V_21 != V_22 )
F_4 ( L_7 , V_8 -> V_21 ) ;
if ( F_1 ( V_28 , V_3 ) < 0 ) {
F_4 ( L_8 ) ;
goto V_14;
}
V_8 -> V_21 = V_26 ;
V_14:
F_20 ( & V_8 -> V_20 , V_24 ) ;
F_21 ( V_3 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
unsigned long V_24 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_3 , V_3 ) ;
F_19 ( & V_8 -> V_20 , V_24 ) ;
if ( V_8 -> V_21 != V_25 )
F_4 ( L_9 , V_8 -> V_21 ) ;
F_16 ( V_8 ) ;
F_20 ( & V_8 -> V_20 , V_24 ) ;
F_21 ( V_3 ) ;
}
static int F_24 ( struct V_2 * V_3 , struct V_5 * V_6 )
{
unsigned long V_24 = 0 ;
struct V_7 * V_8 = V_3 -> V_9 ;
F_2 ( L_10 , V_3 , V_6 ) ;
memcpy ( F_25 ( V_6 , 1 ) , & F_26 ( V_6 ) -> V_29 , 1 ) ;
F_19 ( & V_8 -> V_20 , V_24 ) ;
switch ( V_8 -> V_21 ) {
case V_22 :
F_2 ( L_11 ) ;
F_6 ( & V_8 -> V_17 , V_6 ) ;
break;
case V_26 :
F_2 ( L_12 ) ;
F_6 ( & V_8 -> V_19 , V_6 ) ;
if ( F_1 ( V_30 , V_3 ) < 0 ) {
F_4 ( L_13 ) ;
break;
}
V_8 -> V_21 = V_25 ;
break;
case V_25 :
F_2 ( L_14 ) ;
F_6 ( & V_8 -> V_19 , V_6 ) ;
break;
default:
F_4 ( L_15 , V_8 -> V_21 ) ;
F_14 ( V_6 ) ;
break;
}
F_20 ( & V_8 -> V_20 , V_24 ) ;
return 0 ;
}
static inline int F_27 ( struct V_7 * V_8 , int V_31 )
{
int V_32 = F_28 ( V_8 -> V_23 ) ;
F_2 ( L_16 , V_31 , V_32 ) ;
if ( ! V_31 ) {
F_29 ( V_8 -> V_23 ) ;
} else if ( V_31 > V_32 ) {
F_4 ( L_17 ) ;
F_14 ( V_8 -> V_23 ) ;
} else {
V_8 -> V_33 = V_34 ;
V_8 -> V_35 = V_31 ;
return V_31 ;
}
V_8 -> V_33 = V_36 ;
V_8 -> V_23 = NULL ;
V_8 -> V_35 = 0 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 , void * V_37 , int V_38 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
char * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_31 , type , V_46 ;
F_2 ( L_18 , V_3 , V_38 , V_8 -> V_33 , V_8 -> V_35 ) ;
V_39 = V_37 ;
while ( V_38 ) {
if ( V_8 -> V_35 ) {
V_31 = F_31 (unsigned int, ll->rx_count, count) ;
memcpy ( F_5 ( V_8 -> V_23 , V_31 ) , V_39 , V_31 ) ;
V_8 -> V_35 -= V_31 ; V_38 -= V_31 ; V_39 += V_31 ;
if ( V_8 -> V_35 )
continue;
switch ( V_8 -> V_33 ) {
case V_34 :
F_2 ( L_19 ) ;
F_29 ( V_8 -> V_23 ) ;
V_8 -> V_33 = V_36 ;
V_8 -> V_23 = NULL ;
continue;
case V_47 :
V_41 = V_40 ( V_8 -> V_23 ) ;
F_2 ( L_20 , V_41 -> V_48 , V_41 -> V_49 ) ;
F_27 ( V_8 , V_41 -> V_49 ) ;
continue;
case V_50 :
V_43 = V_42 ( V_8 -> V_23 ) ;
V_46 = F_32 ( V_43 -> V_46 ) ;
F_2 ( L_21 , V_46 ) ;
F_27 ( V_8 , V_46 ) ;
continue;
case V_51 :
V_45 = V_44 ( V_8 -> V_23 ) ;
F_2 ( L_22 , V_45 -> V_46 ) ;
F_27 ( V_8 , V_45 -> V_46 ) ;
continue;
}
}
switch ( * V_39 ) {
case V_52 :
F_2 ( L_23 ) ;
V_8 -> V_33 = V_47 ;
V_8 -> V_35 = V_53 ;
type = V_52 ;
break;
case V_54 :
F_2 ( L_24 ) ;
V_8 -> V_33 = V_50 ;
V_8 -> V_35 = V_55 ;
type = V_54 ;
break;
case V_56 :
F_2 ( L_25 ) ;
V_8 -> V_33 = V_51 ;
V_8 -> V_35 = V_57 ;
type = V_56 ;
break;
case V_58 :
F_2 ( L_26 ) ;
F_22 ( V_3 ) ;
V_39 ++ ; V_38 -- ;
continue;
case V_28 :
F_4 ( L_27 , V_8 -> V_21 ) ;
V_39 ++ ; V_38 -- ;
continue;
case V_30 :
F_2 ( L_28 ) ;
F_18 ( V_3 ) ;
V_39 ++ ; V_38 -- ;
continue;
case V_27 :
F_2 ( L_29 ) ;
F_23 ( V_3 ) ;
V_39 ++ ; V_38 -- ;
continue;
default:
F_4 ( L_30 , ( V_59 ) * V_39 ) ;
V_3 -> V_16 -> V_60 . V_61 ++ ;
V_39 ++ ; V_38 -- ;
continue;
} ;
V_39 ++ ; V_38 -- ;
V_8 -> V_23 = F_3 ( V_62 , V_12 ) ;
if ( ! V_8 -> V_23 ) {
F_4 ( L_31 ) ;
V_8 -> V_33 = V_36 ;
V_8 -> V_35 = 0 ;
return - V_13 ;
}
V_8 -> V_23 -> V_15 = ( void * ) V_3 -> V_16 ;
F_26 ( V_8 -> V_23 ) -> V_29 = type ;
}
return V_38 ;
}
static struct V_5 * F_33 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_9 ;
return F_17 ( & V_8 -> V_17 ) ;
}
int T_2 F_34 ( void )
{
int V_4 = F_35 ( & V_63 ) ;
if ( ! V_4 )
F_36 ( L_32 ) ;
else
F_4 ( L_33 ) ;
return V_4 ;
}
int T_3 F_37 ( void )
{
return F_38 ( & V_63 ) ;
}
