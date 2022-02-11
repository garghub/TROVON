static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_3 ( V_8 , V_10 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_6 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
void (* F_10)( struct V_1 * , T_1 * , const T_1 * ) =
F_11 ( V_16 ) -> V_17 ;
int V_18 = F_12 ( V_16 ) ;
unsigned int V_19 = V_15 -> V_19 ;
T_1 * V_20 = V_15 -> V_20 . V_21 . V_22 ;
T_1 * V_23 = V_15 -> V_23 . V_21 . V_22 ;
T_1 * V_24 = V_15 -> V_24 ;
do {
F_13 ( V_24 , V_20 , V_18 ) ;
F_10 ( F_14 ( V_16 ) , V_23 , V_24 ) ;
memcpy ( V_24 , V_23 , V_18 ) ;
V_20 += V_18 ;
V_23 += V_18 ;
} while ( ( V_19 -= V_18 ) >= V_18 );
return V_19 ;
}
static int F_15 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
void (* F_10)( struct V_1 * , T_1 * , const T_1 * ) =
F_11 ( V_16 ) -> V_17 ;
int V_18 = F_12 ( V_16 ) ;
unsigned int V_19 = V_15 -> V_19 ;
T_1 * V_20 = V_15 -> V_20 . V_21 . V_22 ;
T_1 * V_24 = V_15 -> V_24 ;
do {
F_13 ( V_20 , V_24 , V_18 ) ;
F_10 ( F_14 ( V_16 ) , V_20 , V_20 ) ;
V_24 = V_20 ;
V_20 += V_18 ;
} while ( ( V_19 -= V_18 ) >= V_18 );
memcpy ( V_15 -> V_24 , V_24 , V_18 ) ;
return V_19 ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_25 * V_23 , struct V_25 * V_20 ,
unsigned int V_19 )
{
struct V_14 V_15 ;
struct V_26 * V_16 = V_13 -> V_16 ;
struct V_5 * V_6 = F_17 ( V_16 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_18 ( & V_15 , V_23 , V_20 , V_19 ) ;
V_9 = F_19 ( V_13 , & V_15 ) ;
while ( ( V_19 = V_15 . V_19 ) ) {
if ( V_15 . V_20 . V_21 . V_22 == V_15 . V_23 . V_21 . V_22 )
V_19 = F_15 ( V_13 , & V_15 , V_8 ) ;
else
V_19 = F_9 ( V_13 , & V_15 , V_8 ) ;
V_9 = F_20 ( V_13 , & V_15 , V_19 ) ;
}
return V_9 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
void (* F_10)( struct V_1 * , T_1 * , const T_1 * ) =
F_11 ( V_16 ) -> V_27 ;
int V_18 = F_12 ( V_16 ) ;
unsigned int V_19 = V_15 -> V_19 ;
T_1 * V_20 = V_15 -> V_20 . V_21 . V_22 ;
T_1 * V_23 = V_15 -> V_23 . V_21 . V_22 ;
T_1 * V_24 = V_15 -> V_24 ;
do {
F_10 ( F_14 ( V_16 ) , V_23 , V_20 ) ;
F_13 ( V_23 , V_24 , V_18 ) ;
V_24 = V_20 ;
V_20 += V_18 ;
V_23 += V_18 ;
} while ( ( V_19 -= V_18 ) >= V_18 );
memcpy ( V_15 -> V_24 , V_24 , V_18 ) ;
return V_19 ;
}
static int F_22 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
struct V_7 * V_16 )
{
void (* F_10)( struct V_1 * , T_1 * , const T_1 * ) =
F_11 ( V_16 ) -> V_27 ;
int V_18 = F_12 ( V_16 ) ;
unsigned int V_19 = V_15 -> V_19 ;
T_1 * V_20 = V_15 -> V_20 . V_21 . V_22 ;
T_1 V_28 [ V_18 ] ;
V_20 += V_19 - ( V_19 & ( V_18 - 1 ) ) - V_18 ;
memcpy ( V_28 , V_20 , V_18 ) ;
for (; ; ) {
F_10 ( F_14 ( V_16 ) , V_20 , V_20 ) ;
if ( ( V_19 -= V_18 ) < V_18 )
break;
F_13 ( V_20 , V_20 - V_18 , V_18 ) ;
V_20 -= V_18 ;
}
F_13 ( V_20 , V_15 -> V_24 , V_18 ) ;
memcpy ( V_15 -> V_24 , V_28 , V_18 ) ;
return V_19 ;
}
static int F_23 ( struct V_12 * V_13 ,
struct V_25 * V_23 , struct V_25 * V_20 ,
unsigned int V_19 )
{
struct V_14 V_15 ;
struct V_26 * V_16 = V_13 -> V_16 ;
struct V_5 * V_6 = F_17 ( V_16 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_18 ( & V_15 , V_23 , V_20 , V_19 ) ;
V_9 = F_19 ( V_13 , & V_15 ) ;
while ( ( V_19 = V_15 . V_19 ) ) {
if ( V_15 . V_20 . V_21 . V_22 == V_15 . V_23 . V_21 . V_22 )
V_19 = F_22 ( V_13 , & V_15 , V_8 ) ;
else
V_19 = F_21 ( V_13 , & V_15 , V_8 ) ;
V_9 = F_20 ( V_13 , & V_15 , V_19 ) ;
}
return V_9 ;
}
static int F_24 ( struct V_1 * V_16 )
{
struct V_29 * V_30 = ( void * ) V_16 -> V_31 ;
struct V_32 * V_33 = F_25 ( V_30 ) ;
struct V_5 * V_6 = F_2 ( V_16 ) ;
struct V_7 * V_34 ;
V_34 = F_26 ( V_33 ) ;
if ( F_27 ( V_34 ) )
return F_28 ( V_34 ) ;
V_6 -> V_8 = V_34 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_16 ) ;
F_30 ( V_6 -> V_8 ) ;
}
static struct V_29 * F_31 ( struct V_35 * * V_36 )
{
struct V_29 * V_30 ;
struct V_37 * V_38 ;
int V_9 ;
V_9 = F_32 ( V_36 , V_39 ) ;
if ( V_9 )
return F_33 ( V_9 ) ;
V_38 = F_34 ( V_36 , V_40 ,
V_41 ) ;
if ( F_27 ( V_38 ) )
return F_35 ( V_38 ) ;
V_30 = F_33 ( - V_42 ) ;
if ( ! F_36 ( V_38 -> V_43 ) )
goto V_44;
V_30 = F_37 ( L_1 , V_38 ) ;
if ( F_27 ( V_30 ) )
goto V_44;
V_30 -> V_38 . V_45 = V_39 ;
V_30 -> V_38 . V_46 = V_38 -> V_46 ;
V_30 -> V_38 . V_43 = V_38 -> V_43 ;
V_30 -> V_38 . V_47 = V_38 -> V_47 ;
V_30 -> V_38 . V_48 = & V_49 ;
V_30 -> V_38 . V_47 |= F_38 ( V_50 ) - 1 ;
V_30 -> V_38 . V_51 . V_52 = V_38 -> V_43 ;
V_30 -> V_38 . V_51 . V_53 = V_38 -> V_54 . V_55 ;
V_30 -> V_38 . V_51 . V_56 = V_38 -> V_54 . V_57 ;
V_30 -> V_38 . V_58 = sizeof( struct V_5 ) ;
V_30 -> V_38 . V_59 = F_24 ;
V_30 -> V_38 . V_60 = F_29 ;
V_30 -> V_38 . V_51 . V_61 = F_1 ;
V_30 -> V_38 . V_51 . V_62 = F_16 ;
V_30 -> V_38 . V_51 . V_63 = F_23 ;
V_44:
F_39 ( V_38 ) ;
return V_30 ;
}
static void F_40 ( struct V_29 * V_30 )
{
F_41 ( F_25 ( V_30 ) ) ;
F_42 ( V_30 ) ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_64 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_64 ) ;
}
