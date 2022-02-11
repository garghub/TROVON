static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
char * V_3 , unsigned long V_4 )
{
T_2 V_5 ;
char T_3 * V_6 = V_3 ;
T_4 V_7 ;
if ( ! ( V_1 -> V_8 & V_9 ) )
return - V_10 ;
if ( ! V_1 -> V_11 -> V_12 && ! V_1 -> V_11 -> V_13 )
return - V_14 ;
V_5 = F_2 () ;
F_3 ( F_4 () ) ;
if ( V_1 -> V_11 -> V_12 )
V_7 = V_1 -> V_11 -> V_12 ( V_1 , V_6 , V_4 , & V_2 ) ;
else
V_7 = F_5 ( V_1 , V_6 , V_4 , & V_2 ) ;
F_3 ( V_5 ) ;
return V_7 ;
}
int F_6 ( void )
{
long V_15 ;
V_16 = F_7 ( V_17 [ V_18 ] , 0 , 0 ) ;
if ( F_8 ( V_16 ) ) {
V_15 = F_9 ( V_16 ) ;
F_10 ( L_1 ,
V_17 [ V_18 ] , V_15 ) ;
return V_15 ;
}
return 0 ;
}
static struct V_19 * F_11 ( enum V_20 V_21 )
{
struct V_19 * V_22 = V_16 ;
int V_15 ;
if ( V_21 != V_18 && V_21 < V_23 ) {
V_22 = F_7 ( V_17 [ V_21 ] , 0 , 0 ) ;
if ( F_8 ( V_22 ) ) {
V_15 = F_9 ( V_22 ) ;
F_10 ( L_2 ,
V_17 [ V_21 ] , V_15 ) ;
}
}
return V_22 ;
}
static void F_12 ( struct V_19 * V_22 )
{
if ( V_22 != V_16 )
F_13 ( V_22 ) ;
}
static int F_14 ( struct V_1 * V_1 ,
struct V_24 * V_25 ,
struct V_19 * V_22 )
{
T_1 V_26 , V_2 = 0 ;
char * V_27 ;
int V_15 , V_12 = 0 ;
struct {
struct V_28 V_29 ;
char V_30 [ F_15 ( V_22 ) ] ;
} V_31 ;
V_31 . V_29 . V_22 = V_22 ;
V_31 . V_29 . V_32 = 0 ;
V_25 -> V_33 = F_16 ( V_22 ) ;
V_15 = F_17 ( & V_31 . V_29 ) ;
if ( V_15 != 0 )
return V_15 ;
V_26 = F_18 ( F_19 ( V_1 ) ) ;
if ( V_26 == 0 )
goto V_34;
V_27 = F_20 ( V_35 , V_36 ) ;
if ( ! V_27 )
return - V_37 ;
if ( ! ( V_1 -> V_8 & V_9 ) ) {
V_1 -> V_8 |= V_9 ;
V_12 = 1 ;
}
while ( V_2 < V_26 ) {
int V_38 ;
V_38 = F_1 ( V_1 , V_2 , V_27 , V_35 ) ;
if ( V_38 < 0 ) {
V_15 = V_38 ;
break;
}
if ( V_38 == 0 )
break;
V_2 += V_38 ;
V_15 = F_21 ( & V_31 . V_29 , V_27 , V_38 ) ;
if ( V_15 )
break;
}
if ( V_12 )
V_1 -> V_8 &= ~ V_9 ;
F_22 ( V_27 ) ;
V_34:
if ( ! V_15 )
V_15 = F_23 ( & V_31 . V_29 , V_25 -> V_39 ) ;
return V_15 ;
}
int F_24 ( struct V_1 * V_1 , struct V_24 * V_25 )
{
struct V_19 * V_22 ;
int V_15 ;
V_22 = F_11 ( V_25 -> V_21 ) ;
if ( F_8 ( V_22 ) )
return F_9 ( V_22 ) ;
V_15 = F_14 ( V_1 , V_25 , V_22 ) ;
F_12 ( V_22 ) ;
return V_15 ;
}
static int F_25 ( struct V_40 * V_41 ,
struct V_42 * V_43 ,
int V_44 ,
struct V_24 * V_25 ,
struct V_19 * V_22 )
{
struct {
struct V_28 V_29 ;
char V_30 [ F_15 ( V_22 ) ] ;
} V_31 ;
int V_15 , V_45 ;
V_31 . V_29 . V_22 = V_22 ;
V_31 . V_29 . V_32 = 0 ;
V_25 -> V_33 = F_16 ( V_22 ) ;
V_15 = F_17 ( & V_31 . V_29 ) ;
if ( V_15 != 0 )
return V_15 ;
for ( V_45 = 0 ; V_45 < V_44 ; V_45 ++ ) {
T_5 V_46 [ V_47 + 1 ] = { 0 } ;
T_5 * V_48 = V_41 [ V_45 ] . V_49 ;
T_6 V_50 = V_41 [ V_45 ] . V_51 ;
if ( strcmp ( V_43 -> V_52 , V_53 ) != 0 ) {
V_15 = F_21 ( & V_31 . V_29 ,
( const T_5 * ) & V_41 [ V_45 ] . V_51 ,
sizeof( V_41 [ V_45 ] . V_51 ) ) ;
if ( V_15 )
break;
} else if ( strcmp ( V_43 -> V_54 [ V_45 ] -> V_55 , L_3 ) == 0 ) {
memcpy ( V_46 , V_48 , V_50 ) ;
V_48 = V_46 ;
V_50 = V_47 + 1 ;
}
V_15 = F_21 ( & V_31 . V_29 , V_48 , V_50 ) ;
if ( V_15 )
break;
}
if ( ! V_15 )
V_15 = F_23 ( & V_31 . V_29 , V_25 -> V_39 ) ;
return V_15 ;
}
int F_26 ( struct V_40 * V_41 ,
struct V_42 * V_31 , int V_44 ,
struct V_24 * V_25 )
{
struct V_19 * V_22 ;
int V_15 ;
V_22 = F_11 ( V_25 -> V_21 ) ;
if ( F_8 ( V_22 ) )
return F_9 ( V_22 ) ;
V_15 = F_25 ( V_41 , V_31 , V_44 ,
V_25 , V_22 ) ;
F_12 ( V_22 ) ;
return V_15 ;
}
static void T_7 F_27 ( int V_56 , T_5 * V_57 )
{
if ( ! V_58 )
return;
if ( F_28 ( V_59 , V_56 , V_57 ) != 0 )
F_10 ( L_4 ) ;
}
static int T_7 F_29 ( char * V_39 ,
struct V_19 * V_22 )
{
T_5 V_60 [ V_61 ] ;
int V_15 , V_45 ;
struct {
struct V_28 V_29 ;
char V_30 [ F_15 ( V_22 ) ] ;
} V_31 ;
V_31 . V_29 . V_22 = V_22 ;
V_31 . V_29 . V_32 = 0 ;
V_15 = F_17 ( & V_31 . V_29 ) ;
if ( V_15 != 0 )
return V_15 ;
for ( V_45 = V_62 ; V_45 < V_63 ; V_45 ++ ) {
F_27 ( V_45 , V_60 ) ;
V_15 = F_21 ( & V_31 . V_29 , V_60 , V_61 ) ;
}
if ( ! V_15 )
F_23 ( & V_31 . V_29 , V_39 ) ;
return V_15 ;
}
int T_7 F_30 ( struct V_24 * V_25 )
{
struct V_19 * V_22 ;
int V_15 ;
V_22 = F_11 ( V_25 -> V_21 ) ;
if ( F_8 ( V_22 ) )
return F_9 ( V_22 ) ;
V_25 -> V_33 = F_16 ( V_22 ) ;
V_15 = F_29 ( V_25 -> V_39 , V_22 ) ;
F_12 ( V_22 ) ;
return V_15 ;
}
