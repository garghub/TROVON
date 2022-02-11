static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long V_5 ,
int V_6 )
{
T_1 V_7 ;
T_2 V_8 ;
T_3 * V_9 ;
T_3 * V_10 ;
T_3 V_11 = sizeof( V_7 ) + sizeof( * V_9 ) ;
T_3 V_12 = V_5 / V_13 + ( ( V_5 % V_13 ) > 0 ) ;
T_3 V_14 = V_15 * V_5 + ( sizeof( V_8 ) + sizeof( * V_9 ) ) * V_12 ;
T_3 V_16 = 0 ;
T_3 V_17 = V_11 + V_14 ;
T_3 V_18 ;
V_10 = V_9 = F_2 ( V_2 , V_17 ) ;
if ( F_3 ( V_9 == NULL ) )
return - V_19 ;
V_7 . V_20 = V_6 ;
V_7 . V_21 = V_5 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
V_9 += sizeof( V_7 ) / sizeof( * V_9 ) ;
V_8 . V_20 = V_6 ;
V_8 . V_23 = ( V_15 > sizeof( * V_9 ) ) ?
V_24 : V_25 ;
while ( V_5 > 0 ) {
unsigned long V_26 = F_4 ( V_5 , ( unsigned long ) V_13 ) ;
V_8 . V_27 = V_16 ;
V_8 . V_21 = V_26 ;
* V_9 ++ = V_28 ;
memcpy ( V_9 , & V_8 , sizeof( V_8 ) ) ;
V_9 += sizeof( V_8 ) / sizeof( * V_9 ) ;
for ( V_18 = 0 ; V_18 < V_26 ; ++ V_18 ) {
if ( V_15 <= 4 )
* V_9 = F_5 ( V_4 ) >> V_29 ;
else
* ( ( V_30 * ) V_9 ) = F_5 ( V_4 ) >>
V_29 ;
V_9 += V_15 / sizeof( * V_9 ) ;
F_6 ( V_4 ) ;
}
V_5 -= V_26 ;
V_16 += V_26 ;
}
F_7 ( V_9 != V_10 + V_17 / sizeof( * V_9 ) ) ;
F_8 ( V_2 , V_17 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 ,
int V_6 )
{
T_1 V_7 ;
T_3 V_11 = sizeof( V_7 ) + 4 ;
T_3 * V_9 ;
V_9 = F_2 ( V_2 , V_11 ) ;
if ( F_3 ( V_9 == NULL ) ) {
F_10 ( L_1 ) ;
return;
}
V_7 . V_20 = V_6 ;
V_7 . V_21 = 0 ;
* V_9 ++ = V_22 ;
memcpy ( V_9 , & V_7 , sizeof( V_7 ) ) ;
F_8 ( V_2 , V_11 ) ;
}
static void F_11 ( struct V_31 * V_32 , T_4 V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_36 , * V_37 ;
struct V_38 * V_39 ;
unsigned int V_40 = V_41 /
sizeof( struct V_38 ) - 1 ;
if ( F_12 ( V_35 ) )
return;
F_13 (page, next, desc_pages, lru) {
F_14 ( & V_36 -> V_42 ) ;
if ( F_15 ( V_33 != V_43 ) ) {
F_16 ( V_32 , V_33 , V_41 ,
V_44 ) ;
}
V_39 = F_17 ( V_36 ) ;
V_33 = ( T_4 )
F_18 ( V_39 [ V_40 ] . V_45 ) <<
V_29 ;
F_19 ( V_39 ) ;
F_20 ( V_36 ) ;
}
}
static int F_21 ( struct V_31 * V_32 ,
struct V_34 * V_35 ,
struct V_3 * V_4 ,
unsigned long V_5 ,
T_4 * V_46 )
{
struct V_36 * V_36 ;
struct V_38 * V_39 = NULL ;
struct V_38 * V_47 = NULL ;
unsigned int V_40 ;
unsigned long V_48 ;
unsigned long V_49 ;
int V_50 ;
T_4 V_33 ;
V_40 = V_41 /
sizeof( struct V_38 ) - 1 ;
while ( F_15 ( V_5 != 0 ) ) {
V_36 = F_22 ( V_51 ) ;
if ( F_3 ( V_36 == NULL ) ) {
V_50 = - V_19 ;
goto V_52;
}
F_23 ( & V_36 -> V_42 , V_35 ) ;
V_39 = F_17 ( V_36 ) ;
V_47 = V_39 - 1 ;
V_48 = ~ ( 0UL ) ;
while ( F_15 ( V_5 != 0 ) ) {
V_49 = F_5 ( V_4 ) >> V_29 ;
if ( V_49 != V_48 + 1 ) {
if ( V_47 - V_39 ==
V_40 - 1 )
break;
( ++ V_47 ) -> V_45 = F_24 ( V_49 ) ;
V_47 -> V_5 = F_24 ( 1 ) ;
} else {
T_3 V_53 =
F_18 ( V_47 -> V_5 ) ;
V_47 -> V_5 = F_24 ( V_53 + 1 ) ;
}
V_48 = V_49 ;
-- V_5 ;
F_6 ( V_4 ) ;
}
( ++ V_47 ) -> V_45 = V_54 ;
V_47 -> V_5 = F_24 ( 0 ) ;
F_19 ( V_39 ) ;
}
V_33 = 0 ;
F_25 (page, desc_pages, lru) {
V_39 = F_17 ( V_36 ) ;
V_39 [ V_40 ] . V_45 = F_24
( V_33 >> V_29 ) ;
F_19 ( V_39 ) ;
V_33 = F_26 ( V_32 , V_36 , 0 , V_41 ,
V_44 ) ;
if ( F_3 ( F_27 ( V_32 , V_33 ) ) )
goto V_52;
}
* V_46 = V_33 ;
return 0 ;
V_52:
F_11 ( V_32 , V_43 , V_35 ) ;
return V_50 ;
}
static void F_28 ( struct V_1 * V_2 ,
int V_6 , T_4 V_33 )
{
F_29 ( & V_2 -> V_55 ) ;
F_30 ( V_2 , V_56 , V_6 ) ;
F_31 () ;
F_30 ( V_2 , V_57 , V_33 >> V_29 ) ;
F_32 () ;
F_33 ( & V_2 -> V_55 ) ;
}
int F_34 ( struct V_1 * V_2 ,
const struct V_58 * V_59 ,
unsigned long V_5 ,
int V_6 )
{
struct V_34 V_35 ;
T_4 V_33 = 0 ;
struct V_31 * V_32 = V_2 -> V_32 -> V_32 ;
struct V_3 V_60 ;
int V_50 ;
F_35 ( & V_60 , V_59 , 0 ) ;
if ( F_3 ( ! F_6 ( & V_60 ) ) )
return 0 ;
if ( F_15 ( V_2 -> V_61 & V_62 ) )
return F_1 ( V_2 , & V_60 , V_5 , V_6 ) ;
if ( F_3 ( ! ( V_2 -> V_61 & V_63 ) ) )
return - V_64 ;
if ( V_59 -> V_65 > V_2 -> V_66 )
return - V_64 ;
F_36 ( & V_35 ) ;
V_50 = F_21 ( V_32 , & V_35 , & V_60 ,
V_5 , & V_33 ) ;
if ( F_3 ( V_50 != 0 ) )
return V_50 ;
F_28 ( V_2 , V_6 , V_33 ) ;
F_11 ( V_32 , V_33 , & V_35 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 , int V_6 )
{
if ( F_15 ( V_2 -> V_61 & V_62 ) ) {
F_9 ( V_2 , V_6 ) ;
return;
}
F_29 ( & V_2 -> V_55 ) ;
F_30 ( V_2 , V_56 , V_6 ) ;
F_31 () ;
F_30 ( V_2 , V_57 , 0 ) ;
F_32 () ;
F_33 ( & V_2 -> V_55 ) ;
}
